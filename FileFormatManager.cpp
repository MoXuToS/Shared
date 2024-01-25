#include <boost/python.hpp>
#include <Python.h>
#include <cstdlib> //setenv
#include "FileFormatManager.hpp"

FileFormatManager::FileFormatManager () 
{
    // Загрузка модуля Python
    setenv("PYTHONPATH", ".", 1);
    Py_Initialize();
    boost::python::object main_module = boost::python::import("manager");
    manager = main_module.attr("FileFormatManager")();
}

void FileFormatManager::register_file_format(const std::string& file_format, const std::string& application)
{
    manager.attr("register_file_format")(file_format, application);
}

void FileFormatManager::open_file(const std::string& file_path)
{
    manager.attr("open_file")(file_path);
}

