#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


// TODO: save recorded info, changeable list order, cartesian and joint angles interact together

// TODO: fix int to float, add negative vlaues, fix ticks
//change integer with slider and then manually enter the decimal you want and if you want it to be negative



