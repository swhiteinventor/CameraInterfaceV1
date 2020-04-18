#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


// TODO: save recorded info, fix int to float, fix ticks, update JA in views, changeable list order
