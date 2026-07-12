#include "PVAFile.h"
#include <iostream>
#include <vector>
#include <string>

PVAFile::PVAFile(std::string file_path_string) {
    this->_file_path_string = file_path_string;
    this->file_path = std::filesystem::path(this->_file_path_string);
    this->_instream = std::ifstream(this->file_path);
}
PVAFile::~PVAFile() {this->close();}

std::ifstream & PVAFile::get_ifstream() {
    return this->_instream;
}

bool PVAFile::eof() {
    return this->_instream.eof();
}

void PVAFile::parse_line_to_vector_long_double(std::vector<long double> & to_fill, char separator) {
    if (this->eof()) {
        throw "PVA eof reached";
    }
    std::string line;
    std::getline(this->_instream, line);
    std::stringstream ss(line);
    long double el;
    while(ss >> el) {
        to_fill.push_back(el);
        if (ss.peek() == separator) {
            ss.ignore();
        }
    }
}

long long PVAFile::parse_line_to_long_long() {
    if (this->eof()) {
        throw "PVA eof reached";
    }
    std::string line;
    std::getline(this->_instream, line);
    std::stringstream ss(line);
    long long el;
    ss >> el;
    return el;
}

unsigned long PVAFile::parse_line_to_unsigned_long() {
    if (this->eof()) {
        throw "PVA eof reached";
    }
    std::string line;
    std::getline(this->_instream, line);
    std::stringstream ss(line);
    unsigned long el;
    ss >> el;
    return el;
}

long double PVAFile::parse_line_to_long_double() {
    if (this->eof()) {
        throw "PVA eof reached";
    }
    std::string line;
    std::getline(this->_instream, line);
    std::stringstream ss(line);
    long double el;
    ss >> el;
    return el;
}

std::string PVAFile::parse_raw_line() {
    if (this->eof()) {
        throw "PVA eof reached";
    }
    std::string line;
    std::getline(this->_instream, line);
    return line;
}

void PVAFile::close() {
    this->_instream.close();
    std::cout << "Closed my file at " << this->file_path << std::endl;
}
