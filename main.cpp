#include <iostream>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager FileManager;
    cout << "FileManager Created" << endl;
    FileManager.RegisterFormats(".txt", "Notebook");
    cout << "FileFormat registred" << endl;
    FileManager.OpenFile("hehe.txt");
    cout << "File should be opened" << endl;
    return 0;
}