#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QCameraViewfinder>

int switchCounter = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool haveCameras = checkCameraAvailability();
    if (haveCameras)
    {
        const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
        QListIterator<QCameraInfo> i(availableCameras);
        QCamera* cameraHead = new QCamera(i.next());
        cameraHead->setViewfinder(ui->viewfinderHead);
        cameraHead->start();
        QCamera* cameraArm = new QCamera(i.next());
        cameraArm->setViewfinder(ui->viewfinderArm);
        cameraArm->start();


        //camera->start();

    }
    }

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkCameraAvailability()
{
    if (QCameraInfo::availableCameras().count() > 1)
        return true;
    else
        return false;
}

void MainWindow::on_Manual_SwitchButton_clicked()
{
    //figure out which widget should be made larger or smaller
    QStackedWidget* makeLarger = ui->stackedWidgetHead;
    QStackedWidget* makeSmaller = ui->stackedWidgetArm;
    if (switchCounter%2 == 1)
    {
        makeLarger = ui->stackedWidgetArm;
        makeSmaller = ui->stackedWidgetHead;
    }

    makeLarger->move(30,80);
    makeLarger->resize(900,675);
    makeSmaller->resize(180,135);
    makeSmaller->move(750,80);
    makeSmaller->raise();

    //increment the counter
    switchCounter ++;
}
