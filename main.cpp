#include <iostream>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager FileManager;
    cout << "Registration" << endl;
    FileManager.RegisterFormats("txt", "notebook");
    while(true)
    {
        break;
    }
    return 0;
}