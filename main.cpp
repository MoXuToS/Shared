#include <iostream>
#include <stdlib.h>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager FileManager;
    cout << "Registration" << endl;
    FileManager.RegisterFormat("txt");
    return 0;
}