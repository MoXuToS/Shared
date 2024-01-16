#include <Python.h>
#include <cstdlib>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new FileFormatManager();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::on_RegisterButton_clicked()
{
    std::string FileFormat,  app;
    FileFormat = (ui->FileFormat->text()).toStdString();
    app  = (ui->FileApplication->text()).toStdString();
    if(FileFormat != "" || app != "")
    {
        setenv("PYTHONPATH", ".", 1);
        Py_Initialize();
        manager->register_file_format(FileFormat, app);
        Py_Finalize();
    }
}

void MainWindow::on_OpenButton_clicked()
{
    QString FileName;
    std::string FilePath;
    FileName = QFileDialog::getOpenFileName(this, "Open File");
    FilePath = FileName.toStdString();
    if(FilePath != "")
    {
        setenv("PYTHONPATH", ".", 1);
        Py_Initialize();
        manager->open_file(FilePath);
        Py_Finalize();
    }
}

