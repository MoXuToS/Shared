#include <iostream>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager FileManager;
    cout << "Registration" << endl;
    FileManager.RegisterFormats("txt", "notebook");
    cout << "Registration ended" << endl;
    cout << "Check succsesfull registration" << endl;
    if(FileManager.FormatIsRegistred("hehe.txt"))
    {
        cout << "File format was registred" << endl;
    }
    else
    {
        cout << "File format isn't was registred" << endl;
    }
    return 0;
}