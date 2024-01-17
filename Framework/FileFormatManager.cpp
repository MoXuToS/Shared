#include <boost/python.hpp>
#include <cstdlib> //setenv
#include "FileFormatManager.hpp"

FileFormatManager::FileFormatManager () 
{
    // Загрузка модуля Python
    setenv("PYTHONPATH", ".", 11);
    Py_Initialize();
    boost::python::object main_module = boost::python::import("Manager");
    boost::python::object manager = main_module.attr("FileFormatManager");
    manager.attr("FileFormatManager")();
}

void FileFormatManager::register_file_format(const std::string& file_format, const std::string& application)
{
    // Загрузка модуля Python
    setenv("PYTHONPATH", ".", 1);
    Py_Initialize();
    boost::python::object main_module = boost::python::import("Manager");
    boost::python::object manager = main_module.attr("FileFormatManager");
    manager.attr("register_file_format")(file_format, application);
}

void FileFormatManager::open_file(const std::string& file_path)
{
    // Загрузка модуля Python
    setenv("PYTHONPATH", ".", 1);
    Py_Initialize();
    boost::python::object main_module = boost::python::import("Manager");
    boost::python::object manager = main_module.attr("FileFormatManager");
    manager.attr("open_file")(file_path);
}

