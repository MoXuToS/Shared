#include <iostream>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager* FileManager;
    FileManager->RegisterFormats(".txt", "Notebook");
    FileManager->OpenFile("hehe.txt");
    return 0;
}