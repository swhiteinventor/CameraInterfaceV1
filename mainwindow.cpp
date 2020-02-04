#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QCameraViewfinder>

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
