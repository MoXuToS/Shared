#include <Python.h>
#include <cstdlib>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setenv("PYTHONPATH", "..", 1);
    Py_Initialize();
    MainWindow w;
    w.show();
    Py_Finalize();
    return a.exec();
}
