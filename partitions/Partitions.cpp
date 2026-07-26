#include <vector>
#include <utility>
#include <unordered_set>
#include <stdexcept>

#include "Partitions.h"
#include "Algorithm.h"


Partitions::Partitions(const char * uid) : Algorithm(uid) {};

Partitions::Partitions(std::string uid) :  Algorithm(uid) {};

std::vector<std::vector<unsigned long>> Partitions::_get_subset_indices(
    unsigned long n,
    unsigned long current_index,
    unsigned long start_index
)
{
    if (start_index >= current_index) {
        throw std::invalid_argument("invalid args, start index >= current index");
    }
    if (start_index >= n - 1) {
        throw std::invalid_argument("start_index >= n - 1");
    }

    std::vector<std::vector<unsigned long>> current_subsets_indices;
    if (current_index == n) {
        std::vector<unsigned long> empty_vector;
        current_subsets_indices.push_back(empty_vector);
        return current_subsets_indices;
    }

    for (auto & higher_subset_indices : this->_get_subset_indices(n, current_index + 1, start_index)) {
        std::vector<unsigned long> current_subset_indices;
        if (current_index == start_index + 1) {
            current_subset_indices.push_back(start_index);
        }
        std::vector<unsigned long> current_subset_indices_with_current(current_subset_indices);
        current_subset_indices_with_current.push_back(current_index);
        current_subset_indices_with_current.insert(current_subset_indices_with_current.end(), higher_subset_indices.begin(), higher_subset_indices.end());
        current_subsets_indices.push_back(current_subset_indices_with_current);

        current_subset_indices.insert(current_subset_indices.end(), higher_subset_indices.begin(), higher_subset_indices.end());
        current_subsets_indices.push_back(current_subset_indices);
    }
    return current_subsets_indices;
}

std::pair<std::vector<unsigned long>, std::vector<unsigned long>> Partitions::_partition_vector_by_indices(
    std::vector<unsigned long> & v,
    std::vector<unsigned long> & indices
)
{
    std::vector<unsigned long> v1;
    std::vector<unsigned long> v2;
    std::unordered_set<unsigned long> indices_set(indices.begin(), indices.end());
    for (unsigned long i = 0; i < v.size(); ++i) {
        if (indices_set.count(i)) {
            v1.push_back(v[i]);
        }
        else {
            v2.push_back(v[i]);
        }
    }
    return std::pair<std::vector<unsigned long>, std::vector<unsigned long>>(v1, v2);
}

std::vector<std::vector<std::vector<unsigned long>>> Partitions::get_partitions(std::vector<unsigned long> & v) {
    unsigned long n = v.size();
    std::vector<std::vector<std::vector<unsigned long>>> all_partitions;
    if (n == 0) {
        all_partitions.push_back(std::vector<std::vector<unsigned long>>());
        return all_partitions;
    }
    if (n == 1) {
        std::vector<std::vector<unsigned long>> first_partition = {{v[0]}};
        all_partitions.push_back(first_partition);
        return all_partitions;
    }
    if (n == 2) {
        std::vector<std::vector<unsigned long>> first_partition = {{v[0], v[1]}};
        all_partitions.push_back(first_partition);
        std::vector<std::vector<unsigned long>> second_partition = {{v[0]}, {v[1]}};
        all_partitions.push_back(second_partition);
        return all_partitions;
    }

    for(auto & v1_indices : this->_get_subset_indices(n, 1, 0)) {
        std::pair<std::vector<unsigned long>, std::vector<unsigned long>> v1_v2 = this->_partition_vector_by_indices(v, v1_indices);
        auto v1 = v1_v2.first;
        auto v2 = v1_v2.second;
        for (auto & higher_partition : this->get_partitions(v2)) {
            higher_partition.push_back(v1);
            all_partitions.push_back(higher_partition);
        }
    }
    return all_partitions;
}
