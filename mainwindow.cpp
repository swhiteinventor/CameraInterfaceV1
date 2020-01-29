#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QCameraViewfinder>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCamera* camera = new QCamera;
    QCameraViewfinder* viewfinder = new QCameraViewfinder();
    viewfinder->show();
    camera->setViewfinder(viewfinder);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

