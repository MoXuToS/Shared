#pragma once
#include<iostream>

class FileFormatManager {
public:
    FileFormatManager();
    void register_file_format(const std::string& file_format, const std::string& application);
    void open_file(const std::string& file_path);
};
