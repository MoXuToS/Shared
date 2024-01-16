#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  "FileFormatManager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RegisterButton_clicked();

    void on_OpenButton_clicked();

private:
    Ui::MainWindow *ui;
    FileFormatManager* manager;
};
#endif // MAINWINDOW_H
