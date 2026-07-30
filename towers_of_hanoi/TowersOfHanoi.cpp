#include<vector>
#include<iostream>
#include <stdexcept>
#include <string>

#include "TowersOfHanoi.h"
#include "Algorithm.h"


TowersOfHanoi::TowersOfHanoi(const char * uid, unsigned long tower_count, unsigned long ring_count) : Algorithm(uid) {
    if (tower_count != 3) {
        throw std::invalid_argument("Only three towers of Hanoi supported");
    }
    this->ring_count = ring_count;
    this->tower_count= tower_count;
    this->initialize_state();
};

TowersOfHanoi::TowersOfHanoi(std::string uid, unsigned long tower_count, unsigned long ring_count) :  Algorithm(uid) {
    if (tower_count != 3) {
        throw std::invalid_argument("Only three towers of Hanoi supported");
    }
    this->ring_count = ring_count;
    this->tower_count= tower_count;
    this->initialize_state();
};

void TowersOfHanoi::initialize_state() {
    this->state = std::vector<std::vector<unsigned long>>();
    for (unsigned long i = 0; i < this->tower_count; ++i) {
        this->state.push_back(std::vector<unsigned long>());
    }
    if (this->ring_count == 0)
        return;

    for (unsigned long i = this->ring_count - 1; i > 0; --i) {
        this->state[0].push_back(i);
    }
    this->state[0].push_back(0);
}

void TowersOfHanoi::print_state(std::string indent) {
    for (unsigned long ti = 0; ti < this->tower_count; ti++) {
        std::cout << indent << "Tower " << ti << ": ";
        for (unsigned long ri = 0; ri < this->state[ti].size(); ri++) {
            std::cout << this->state[ti][ri] << ", ";
        }
        std::cout << std::endl;
    }
}

void TowersOfHanoi::move_ring(unsigned long source_tower_index, unsigned long target_tower_index) {
    if (source_tower_index > this->tower_count || target_tower_index > this->tower_count) {
        throw std::invalid_argument("move_ring: tower index out of bound");
    }
    if (source_tower_index == target_tower_index) {
        return;
    }
    if (this->state[source_tower_index].size() == 0) {
        throw std::invalid_argument("move_ring: source tower is empty");
    }
    unsigned long source_top_element = this->state[source_tower_index].back();
    if (this->state[target_tower_index].size() == 0) {
        this->state[target_tower_index].push_back(source_top_element);
        this->state[source_tower_index].pop_back();
        return;
    }
    unsigned long target_top_element = this->state[target_tower_index].back();
    if (target_top_element <= source_top_element) {
        throw std::invalid_argument("move_ring: target top must be greater than source top");
    }
    this->state[target_tower_index].push_back(source_top_element);
    this->state[source_tower_index].pop_back();
}

void TowersOfHanoi::_solve(
    unsigned long level,
    unsigned long main_tower_index,
    unsigned long target_tower_index,
    unsigned long empty_tower_index
)
{   // SCOP: muta MAIN pe TARGET folosind EMPTY
    std::string indent = "";
    for (int i = 0; i < this->ring_count - level; i++) {
        indent.push_back(' ');indent.push_back(' ');indent.push_back(' ');
    }
    if (level == 0)
        return;
    //std::cout << indent << "CASE 2. Level = "<< level << ", Main_tower_index = " << main_tower_index << ", target_tower_index = " << target_tower_index << ", empty_tower_index = " << empty_tower_index << std::endl;
    unsigned long empty_tower_size_0 = this->state[empty_tower_index].size();
    this->_solve(level - 1, main_tower_index, empty_tower_index, target_tower_index);
    unsigned long empty_tower_size_1 = this->state[empty_tower_index].size();
    unsigned long initial_empty_size = this->state[empty_tower_index].size();
    //this->print_state(indent);
    //std::cout << indent << "will move from main " << main_tower_index << " to target " << target_tower_index << std::endl;
    this->move_ring(main_tower_index, target_tower_index);
    this->_solve(empty_tower_size_1 - empty_tower_size_0, empty_tower_index, target_tower_index, main_tower_index);
    /*if (level == this->ring_count) {
        this->print_state(indent);
        std::cout << std::endl;
    }*/
}

std::vector<std::vector<unsigned long>> TowersOfHanoi::solve() {
    this->_solve(this->state[0].size(), 0, 1, 2);
    return this->state;
}
