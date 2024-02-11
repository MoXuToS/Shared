#include <iostream>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager FileManager;
    FileManager.RegisterFormat("txt");
    FileManager.RegisterOpenType("txt", "Notebook");
    return 0;
}