#include <Python.h>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Py_Initialize();
    MainWindow w;
    w.show();
    Py_Finalize();
    return a.exec();
}
