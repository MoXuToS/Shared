#include <boost/python.hpp>
#include "FileFormatManager.hpp"

FileFormatManager::FileFormatManager () 
{
    // Загрузка модуля Python
    boost::python::object main_module = boost::python::import("__main__");
    boost::python::object main_namespace = main_module.attr("__dict__");
    main_namespace["__init__"];
}

void FileFormatManager::register_file_format(const std::string& file_format, const std::string& application)
{
    // Загрузка модуля Python
    std::string command;
    boost::python::object main_module = boost::python::import("__main__");
    boost::python::object main_namespace = main_module.attr("__dict__");
    command = "register_file_format(" + file_format + "," + application + ")";
    main_namespace[command];
}

void FileFormatManager::open_file(const std::string& file_path)
{
    // Загрузка модуля Python
    boost::python::object main_module = boost::python::import("__main__");
    boost::python::object main_namespace = main_module.attr("__dict__");
    std::string command = "open_file(" + file_path + ")";
    main_namespace[command];
}

