#ifndef PVAFILE_H
#define PVAFILE_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>


class PVAFile {
    private:
        std::string _file_path_string;
        std::ifstream _instream;
    public:
        std::filesystem::path file_path;
        PVAFile(std::string file_path_string);
        ~PVAFile();
        std::ifstream & get_ifstream();
        bool eof();
        std::string parse_raw_line();
        void parse_line_to_vector_long_double(std::vector<long double> & to_fill, char separator);
        long long parse_line_to_long_long();
        long double parse_line_to_long_double();
        void close();
};

#endif