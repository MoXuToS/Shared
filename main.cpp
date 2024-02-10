#include <iostream>
#include <stdlib.h>
#include "FileFormatManager.hpp"
using namespace std;

int main()
{
    Manager FileManager;
    cout << "Registration" << endl;
    FileManager.RegisterFormats("txt", "notebook");
    while(true)
    {
        FILE *pipe = popen("zenity --file-selection --title=\"Выберите файл\"", "r");
        if(!pipe)
        {
            cerr << "Ошибка при открытии pipe" << endl;
            break;
        }
        char buffer[256];
        string result = "";
        while(!feof(pipe))
            if(fgets(buffer, 256, pipe) != NULL)
                result += buffer;

        if(!result.empty())
            cout << "Выбранный файл: " << result << endl;
        else
            cout << "Операция отменена" << endl;
        break;
    }
    return 0;
}