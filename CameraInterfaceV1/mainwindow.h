#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "saveeditview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Manual_SwitchButton_clicked();

    void on_SetPoint_SaveViewButton_clicked();

private:
    Ui::MainWindow *ui;
    bool checkCameraAvailability();
};
#endif // MAINWINDOW_H
