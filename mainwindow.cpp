#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QCameraViewfinder>

#include <QDebug>
#include <QKeyEvent>

int switchCounter = 1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bool haveCameras = checkCameraAvailability();

    /*////*/
        QSlider *J1_horizontalSlider = new QSlider(Qt::Horizontal);
        J1_horizontalSlider->setRange(-999999999, 999999999);
        QSlider *J2_horizontalSlider = new QSlider(Qt::Horizontal);
        J2_horizontalSlider->setRange(-128, 128);
        QSlider *J3_horizontalSlider = new QSlider(Qt::Horizontal);
        J3_horizontalSlider->setRange(-999999999, 999999999);
        QSlider *J4_horizontalSlider = new QSlider(Qt::Horizontal);
        J4_horizontalSlider->setRange(-147, 147);
        QSlider *J5_horizontalSlider = new QSlider(Qt::Horizontal);
        J5_horizontalSlider->setRange(-999999999, 999999999);
        QSlider *J6_horizontalSlider = new QSlider(Qt::Horizontal);
        J6_horizontalSlider->setRange(-120, 120);
        QSlider *J7_horizontalSlider = new QSlider(Qt::Horizontal);
        J7_horizontalSlider->setRange(-999999999, 999999999);
    /*////*/


    if (haveCameras)
    {
        ui->statusBar->showMessage("Showing Head Camera",3500);
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
    ui->statusBar->showMessage("Showing Head Camera",3500);

    if (switchCounter%2 == 1)
    {
        makeLarger = ui->stackedWidgetArm;
        makeSmaller = ui->stackedWidgetHead;
        ui->statusBar->showMessage("Showing Arm Camera",3500);
    }

    makeLarger->move(30,80);
    makeLarger->resize(900,675);
    makeSmaller->resize(180,135);
    makeSmaller->move(750,80);
    makeSmaller->raise();

    //increment the counter
    switchCounter ++;
}

void MainWindow::on_SetPoint_SaveViewButton_clicked()
{
    SaveEditView saveeditview;
    saveeditview.setModal(true);
    saveeditview.exec();
}

/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Still Working on
//
// 1) Key press event - Enter
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "Key Press Event";
    if (e->key() == Qt::Key_Enter) {
        qDebug() << "Enter";
        e->ignore();
//this->QTextEdit::keyPressEvent( ek);
}
}

void MainWindow::on_addName_textEdit_textChanged(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Enter) {
        on_addView_pushButton_clicked();
        qDebug() << "Enter";
        e->ignore();
//this->QTextEdit::keyPressEvent( ek);
    }
}

// 2)
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/


/*/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// Command Window
// Manual Cartesian Control
// PushButton Names: UP_pushButton, DOWN_pushButton, LEFT_pushButton, RIGHT_pushButton
//                   IN_pushButton, OUT_pushButton
// TextEdit Box Names: X_textEdit, Y_textEdit, Z_textEdit
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////*/
int Xcounter = 0;
int Ycounter = 0;
int Zcounter = 0;
void MainWindow::on_UP_pushButton_clicked()
{
    Zcounter++;
    QString strZ = QString::number(Zcounter);
    ui->Z_textEdit->setText(strZ);
}

void MainWindow::on_DOWN_pushButton_clicked()
{
    Zcounter--;
    QString strZ = QString::number(Zcounter);
    ui->Z_textEdit->setText(strZ);
}

void MainWindow::on_OUT_pushButton_clicked()
{
    Xcounter++;
    QString strX = QString::number(Xcounter);
    ui->X_textEdit->setText(strX);
}

void MainWindow::on_IN_pushButton_clicked()
{
    Xcounter--;
    QString strX = QString::number(Xcounter);
    ui->X_textEdit->setText(strX);
}

void MainWindow::on_RIGHT_pushButton_clicked()
{
    Ycounter++;
    QString strY = QString::number(Ycounter);
    ui->Y_textEdit->setText(strY);
}

void MainWindow::on_LEFT_pushButton_clicked()
{
    Ycounter--;
    QString strY = QString::number(Ycounter);
    ui->Y_textEdit->setText(strY);
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Command Window
// Manual Joint Pose Control
// Horizontal Slider Names: J1_horizontalSlider, J2_horizontalSlider, J3_horizontalSlider,
//                          J4_horizontalSlider, J5_horizontalSlider, J6_horizontalSlider,
//                          J7_horizontalSlider
// TextEdit Box Names: J1_textEdit, J2_textEdit, J3_textEdit,J4_textEdit, J5_textEdit,
//                     J6_textEdit, J7_textEdit
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/

void MainWindow::on_J1_horizontalSlider_valueChanged(int value)
{
    //int intValue = value;
    QString b = QString::number(value);
    ui->J1_textEdit->setText(b);
}

void MainWindow::on_J2_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->J2_textEdit->setText(b);
}

void MainWindow::on_J3_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->J3_textEdit->setText(b);
}

void MainWindow::on_J4_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->J4_textEdit->setText(b);
}

void MainWindow::on_J5_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->J5_textEdit->setText(b);
}

void MainWindow::on_J6_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->J6_textEdit->setText(b);
}

void MainWindow::on_J7_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->J7_textEdit->setText(b);
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Command Window
// Manual Camera Control
// Dial and Slider Names: Roll_dial, Pitch_horizontalSlider, Yaw_verticalSlider
// TextEdit Box Names: Roll_textEdit, Pitch_textEdit, Yaw_textEdit
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
void MainWindow::on_Roll_dial_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->Roll_textEdit->setText(b);
}

void MainWindow::on_Pitch_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->Pitch_textEdit->setText(b);
}

void MainWindow::on_Yaw_verticalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->Yaw_textEdit->setText(b);
}
/*/////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// Command Window
// Standard Views Available
// Push Button Name: StandardView1_pushButton, StandardView2_pushButton, StandardView3_pushButton
//                   StandardView4_pushButton, StandardView5_pushButton
///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////*/

void MainWindow::on_StandardView1_pushButton_clicked()
{

}

void MainWindow::on_StandardView2_pushButton_clicked()
{

}

void MainWindow::on_StandardView3_pushButton_clicked()
{

}

void MainWindow::on_StandardView4_pushButton_clicked()
{

}

void MainWindow::on_StandardView5_pushButton_clicked()
{

}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Command Window
// User Added View Selection
// Push Button Names: view1_pushButton, view2_pushButton, view3_pushButton, view4_pushButton,
//                    view5_pushButton
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/

void MainWindow::on_view1_pushButton_clicked()
{

}

void MainWindow::on_view2_pushButton_clicked()
{

}

void MainWindow::on_view3_pushButton_clicked()
{

}

void MainWindow::on_view4_pushButton_clicked()
{

}

void MainWindow::on_view5_pushButton_clicked()
{

}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Command Window
// Add a View
// Push Button Name: addView_pushButton
// TextEdit Box Names:addName_textEdit
// Push Button Names: view1_pushButton, view2_pushButton, view3_pushButton, view4_pushButton,
//                    view5_pushButton
// Combo Box Name: view_ComboBox
// This function will replace the empty views untill all are full
// When all are full, you can replace specific views using the comboBox
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
int count=0;
QString name1;
QString name2;
QString name3;
QString name4;
QString name5;
void MainWindow::on_addView_pushButton_clicked()
{
        count++;
        if (count==1){
          //This view has a name
          QString name1 = ui->addName_textEdit->toPlainText();
          ui->view1_pushButton->setText("1: " + name1);
          ui->addName_textEdit->clear();
          //This view has a cartesian pose for x,yz
          QString X1 = ui->X_textEdit->toPlainText();
          QString Y1 = ui->Y_textEdit->toPlainText();
          QString Z1 = ui->Z_textEdit->toPlainText();
          ui->X_textEdit->clear();
          ui->Y_textEdit->clear();
          ui->Z_textEdit->clear();
          //This view has 7DOF joint angles
          QString J1_1 = ui->J1_textEdit->toPlainText();
          QString J2_1 = ui->J2_textEdit->toPlainText();
          QString J3_1 = ui->J3_textEdit->toPlainText();
          QString J4_1 = ui->J4_textEdit->toPlainText();
          QString J5_1 = ui->J5_textEdit->toPlainText();
          QString J6_1 = ui->J6_textEdit->toPlainText();
          QString J7_1 = ui->J7_textEdit->toPlainText();
          ui->J1_horizontalSlider->setValue(0);
          ui->J2_horizontalSlider->setValue(0);
          ui->J3_horizontalSlider->setValue(0);
          ui->J4_horizontalSlider->setValue(0);
          ui->J5_horizontalSlider->setValue(0);
          ui->J6_horizontalSlider->setValue(0);
          ui->J7_horizontalSlider->setValue(0);
          ui->J1_textEdit->clear();
          ui->J2_textEdit->clear();
          ui->J3_textEdit->clear();
          ui->J4_textEdit->clear();
          ui->J5_textEdit->clear();
          ui->J6_textEdit->clear();
          ui->J7_textEdit->clear();
          //This view has a roll,pitch, and yaw
          QString ROLL1 = ui->Roll_textEdit->toPlainText();
          QString PITCH1 = ui->Pitch_textEdit->toPlainText();
          QString YAW1 = ui->Yaw_textEdit->toPlainText();
          ui->Roll_dial->setValue(0);
          ui->Pitch_horizontalSlider->setValue(0);
          ui->Yaw_verticalSlider->setValue(0);
          ui->Roll_textEdit->clear();
          ui->Pitch_textEdit->clear();
          ui->Yaw_textEdit->clear();
        }
        else if (count==2){
          //This view has a name
          QString name2 = ui->addName_textEdit->toPlainText();
          ui->view2_pushButton->setText("2: " + name2);
          ui->addName_textEdit->clear();
          //This view has a cartesian pose for x,yz
          QString X2 = ui->X_textEdit->toPlainText();
          QString Y2 = ui->Y_textEdit->toPlainText();
          QString Z2 = ui->Z_textEdit->toPlainText();
          ui->X_textEdit->clear();
          ui->Y_textEdit->clear();
          ui->Z_textEdit->clear();
          //This view has 7DOF joint angles
          QString J1_2 = ui->J1_textEdit->toPlainText();
          QString J2_2 = ui->J2_textEdit->toPlainText();
          QString J3_2 = ui->J3_textEdit->toPlainText();
          QString J4_2 = ui->J4_textEdit->toPlainText();
          QString J5_2 = ui->J5_textEdit->toPlainText();
          QString J6_2 = ui->J6_textEdit->toPlainText();
          QString J7_2 = ui->J7_textEdit->toPlainText();
          ui->J1_horizontalSlider->setValue(0);
          ui->J2_horizontalSlider->setValue(0);
          ui->J3_horizontalSlider->setValue(0);
          ui->J4_horizontalSlider->setValue(0);
          ui->J5_horizontalSlider->setValue(0);
          ui->J6_horizontalSlider->setValue(0);
          ui->J7_horizontalSlider->setValue(0);
          ui->J1_textEdit->clear();
          ui->J2_textEdit->clear();
          ui->J3_textEdit->clear();
          ui->J4_textEdit->clear();
          ui->J5_textEdit->clear();
          ui->J6_textEdit->clear();
          ui->J7_textEdit->clear();
          //This view has a roll,pitch, and yaw
          QString ROLL2 = ui->Roll_textEdit->toPlainText();
          QString PITCH2 = ui->Pitch_textEdit->toPlainText();
          QString YAW2 = ui->Yaw_textEdit->toPlainText();
          ui->Roll_dial->setValue(0);
          ui->Pitch_horizontalSlider->setValue(0);
          ui->Yaw_verticalSlider->setValue(0);
          ui->Roll_textEdit->clear();
          ui->Pitch_textEdit->clear();
          ui->Yaw_textEdit->clear();
        }
        else if (count==3){
          //This view has a name
          QString name3 = ui->addName_textEdit->toPlainText();
          ui->view3_pushButton->setText("3: " + name3);
          ui->addName_textEdit->clear();
          //This view has a cartesian pose for x,yz
          QString X3 = ui->X_textEdit->toPlainText();
          QString Y3 = ui->Y_textEdit->toPlainText();
          QString Z3 = ui->Z_textEdit->toPlainText();
          ui->X_textEdit->clear();
          ui->Y_textEdit->clear();
          ui->Z_textEdit->clear();
          //This view has 7DOF joint angles
          QString J1_3 = ui->J1_textEdit->toPlainText();
          QString J2_3 = ui->J2_textEdit->toPlainText();
          QString J3_3 = ui->J3_textEdit->toPlainText();
          QString J4_3 = ui->J4_textEdit->toPlainText();
          QString J5_3 = ui->J5_textEdit->toPlainText();
          QString J6_3 = ui->J6_textEdit->toPlainText();
          QString J7_3 = ui->J7_textEdit->toPlainText();
          ui->J1_horizontalSlider->setValue(0);
          ui->J2_horizontalSlider->setValue(0);
          ui->J3_horizontalSlider->setValue(0);
          ui->J4_horizontalSlider->setValue(0);
          ui->J5_horizontalSlider->setValue(0);
          ui->J6_horizontalSlider->setValue(0);
          ui->J7_horizontalSlider->setValue(0);
          ui->J1_textEdit->clear();
          ui->J2_textEdit->clear();
          ui->J3_textEdit->clear();
          ui->J4_textEdit->clear();
          ui->J5_textEdit->clear();
          ui->J6_textEdit->clear();
          ui->J7_textEdit->clear();
          //This view has a roll,pitch, and yaw
          QString ROLL3 = ui->Roll_textEdit->toPlainText();
          QString PITCH3 = ui->Pitch_textEdit->toPlainText();
          QString YAW3 = ui->Yaw_textEdit->toPlainText();
          ui->Roll_dial->setValue(0);
          ui->Pitch_horizontalSlider->setValue(0);
          ui->Yaw_verticalSlider->setValue(0);
          ui->Roll_textEdit->clear();
          ui->Pitch_textEdit->clear();
          ui->Yaw_textEdit->clear();
        }
        else if (count==4){
          //This view has a name
          QString name4 = ui->addName_textEdit->toPlainText();
          ui->view4_pushButton->setText("4: " + name4);
          ui->addName_textEdit->clear();
          //This view has a cartesian pose for x,yz
          QString X4 = ui->X_textEdit->toPlainText();
          QString Y4 = ui->Y_textEdit->toPlainText();
          QString Z4 = ui->Z_textEdit->toPlainText();
          ui->X_textEdit->clear();
          ui->Y_textEdit->clear();
          ui->Z_textEdit->clear();
          //This view has 7DOF joint angles
          QString J1_4 = ui->J1_textEdit->toPlainText();
          QString J2_4 = ui->J2_textEdit->toPlainText();
          QString J3_4 = ui->J3_textEdit->toPlainText();
          QString J4_4 = ui->J4_textEdit->toPlainText();
          QString J5_4 = ui->J5_textEdit->toPlainText();
          QString J6_4 = ui->J6_textEdit->toPlainText();
          QString J7_4 = ui->J7_textEdit->toPlainText();
          ui->J1_horizontalSlider->setValue(0);
          ui->J2_horizontalSlider->setValue(0);
          ui->J3_horizontalSlider->setValue(0);
          ui->J4_horizontalSlider->setValue(0);
          ui->J5_horizontalSlider->setValue(0);
          ui->J6_horizontalSlider->setValue(0);
          ui->J7_horizontalSlider->setValue(0);
          ui->J1_textEdit->clear();
          ui->J2_textEdit->clear();
          ui->J3_textEdit->clear();
          ui->J4_textEdit->clear();
          ui->J5_textEdit->clear();
          ui->J6_textEdit->clear();
          ui->J7_textEdit->clear();
          //This view has a roll,pitch, and yaw
          QString ROLL4 = ui->Roll_textEdit->toPlainText();
          QString PITCH4 = ui->Pitch_textEdit->toPlainText();
          QString YAW4 = ui->Yaw_textEdit->toPlainText();
          ui->Roll_dial->setValue(0);
          ui->Pitch_horizontalSlider->setValue(0);
          ui->Yaw_verticalSlider->setValue(0);
          ui->Roll_textEdit->clear();
          ui->Pitch_textEdit->clear();
          ui->Yaw_textEdit->clear();
        }
        else if (count==5){
          //This view has a name
          QString name5 = ui->addName_textEdit->toPlainText();
          ui->view5_pushButton->setText("5: " + name5);
          ui->addName_textEdit->clear();
          //This view has a cartesian pose for x,yz
          QString X5 = ui->X_textEdit->toPlainText();
          QString Y5 = ui->Y_textEdit->toPlainText();
          QString Z5 = ui->Z_textEdit->toPlainText();
          ui->X_textEdit->clear();
          ui->Y_textEdit->clear();
          ui->Z_textEdit->clear();
          //This view has 7DOF joint angles
          QString J1_5 = ui->J1_textEdit->toPlainText();
          QString J2_5 = ui->J2_textEdit->toPlainText();
          QString J3_5 = ui->J3_textEdit->toPlainText();
          QString J4_5 = ui->J4_textEdit->toPlainText();
          QString J5_5 = ui->J5_textEdit->toPlainText();
          QString J6_5 = ui->J6_textEdit->toPlainText();
          QString J7_5 = ui->J7_textEdit->toPlainText();
          ui->J1_horizontalSlider->setValue(0);
          ui->J2_horizontalSlider->setValue(0);
          ui->J3_horizontalSlider->setValue(0);
          ui->J4_horizontalSlider->setValue(0);
          ui->J5_horizontalSlider->setValue(0);
          ui->J6_horizontalSlider->setValue(0);
          ui->J7_horizontalSlider->setValue(0);
          ui->J1_textEdit->clear();
          ui->J2_textEdit->clear();
          ui->J3_textEdit->clear();
          ui->J4_textEdit->clear();
          ui->J5_textEdit->clear();
          ui->J6_textEdit->clear();
          ui->J7_textEdit->clear();
          //This view has a roll,pitch, and yaw
          QString ROLL5 = ui->Roll_textEdit->toPlainText();
          QString PITCH5 = ui->Pitch_textEdit->toPlainText();
          QString YAW5 = ui->Yaw_textEdit->toPlainText();
          ui->Roll_dial->setValue(0);
          ui->Pitch_horizontalSlider->setValue(0);
          ui->Yaw_verticalSlider->setValue(0);
          ui->Roll_textEdit->clear();
          ui->Pitch_textEdit->clear();
          ui->Yaw_textEdit->clear();
        }
        /*else {
            QString currentState = ui->view_comboBox->currentText();
            if (currentState == "View 1"){
                QString name1 = ui->addName_textEdit->toPlainText();
                ui->view1_pushButton->setText("1: " + name1);
                ui->addName_textEdit->clear();}
            if (currentState == "View 2"){
                QString name2 = ui->addName_textEdit->toPlainText();
                ui->view2_pushButton->setText("2: " + name2);
                ui->addName_textEdit->clear();}
            if (currentState == "View 3"){
                QString name3 = ui->addName_textEdit->toPlainText();
                ui->view3_pushButton->setText("3: " + name3);
                ui->addName_textEdit->clear();}
            if (currentState == "View 4"){
                QString name4 = ui->addName_textEdit->toPlainText();
                ui->view4_pushButton->setText("4: " + name4);
                ui->addName_textEdit->clear();}
            if (currentState == "View 5"){
                QString name5 = ui->addName_textEdit->toPlainText();
                ui->view5_pushButton->setText("5: " + name5);
                ui->addName_textEdit->clear();
            }
        }*/
}
/*/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// Edit Views Window
// Edit Cartesian Control
// PushButton Names: NewUP_pushButton, NewDOWN_pushButton, NewLEFT_pushButton,
//                   NewRIGHT_pushButton, NewIN_pushButton, NewOUT_pushButton
// TextEdit Box Names: XNEW_textEdit, YNEW_textEdit, ZNEW_textEdit
///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////*/
int XNEWcounter = 0;
int YNEWcounter = 0;
int ZNEWcounter = 0;
void MainWindow::on_NewUP_pushButton_clicked()
{
    ZNEWcounter++;
    QString strZ = QString::number(ZNEWcounter);
    ui->ZNEW_textEdit->setText(strZ);
}

void MainWindow::on_NewDOWN_pushButton_clicked()
{
    ZNEWcounter--;
    QString strZ = QString::number(ZNEWcounter);
    ui->ZNEW_textEdit->setText(strZ);
}

void MainWindow::on_NewLEFT_pushButton_clicked()
{
    YNEWcounter--;
    QString strY = QString::number(YNEWcounter);
    ui->YNEW_textEdit->setText(strY);
}

void MainWindow::on_NewRIGHT_pushButton_clicked()
{
    YNEWcounter++;
    QString strY = QString::number(YNEWcounter);
    ui->YNEW_textEdit->setText(strY);
}

void MainWindow::on_NewIN_pushButton_clicked()
{
    XNEWcounter--;
    QString strX = QString::number(XNEWcounter);
    ui->XNEW_textEdit->setText(strX);
}

void MainWindow::on_NewOUT_pushButton_clicked()
{
    XNEWcounter++;
    QString strX = QString::number(XNEWcounter);
    ui->XNEW_textEdit->setText(strX);
}
/*//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
// Edit Views Window
// Edit Joint Pose Control
// Horizontal Slider Names: NewJ1_horizontalSlider, NewJ2_horizontalSlider, NewJ3_horizontalSlider,
//                          NewJ4_horizontalSlider, NewJ5_horizontalSlider, NewJ6_horizontalSlider,
//                          NewJ7_horizontalSlider
// TextEdit Box Names: NewJ1_textEdit, NewJ2_textEdit, NewJ3_textEdit, NewJ4_textEdit,
//                     NewJ5_textEdit, NewJ6_textEdit, NewJ7_textEdit
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////*/
void MainWindow::on_NewJ1_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ1_textEdit->setText(b);
}

void MainWindow::on_NewJ2_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ2_textEdit->setText(b);
}

void MainWindow::on_NewJ3_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ3_textEdit->setText(b);
}

void MainWindow::on_NewJ4_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ4_textEdit->setText(b);
}

void MainWindow::on_NewJ5_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ5_textEdit->setText(b);
}

void MainWindow::on_NewJ6_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ6_textEdit->setText(b);
}

void MainWindow::on_NewJ7_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewJ7_textEdit->setText(b);
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Edit Views Window
// Edit Camera Control
// Dial and Slider Names: NewRoll_dial, NewPitch_horizontalSlider, NewYaw_verticalSlider
// TextEdit Box Names: NewRoll_textEdit, NewPitch_textEdit, NewYaw_textEdit
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/

void MainWindow::on_Newdial_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewRoll_textEdit->setText(b);
}

void MainWindow::on_New_horizontalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewPitch_textEdit->setText(b);
}

void MainWindow::on_New_verticalSlider_valueChanged(int value)
{
    QString b = QString::number(value);
    ui->NewYaw_textEdit->setText(b);
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Edit Views Window
// Change View Name
// Push Button Name: applyNewName_pushButton
// TextEdit Box Names:newName_textEdit
// Push Button Names: view1_pushButton, view2_pushButton, view3_pushButton, view4_pushButton,
//                    view5_pushButton
// Combo Box Name: selectView_comboBox
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
void MainWindow::on_applyNewName_pushButton_clicked()
{
    QString currentState = ui->selectView_comboBox->currentText();
    if (currentState == "View 1"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view1_pushButton->setText("1: " + name);
        ui->newName_textEdit->clear();}
    if (currentState == "View 2"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view2_pushButton->setText("2: " + name);
        ui->newName_textEdit->clear();}
    if (currentState == "View 3"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view3_pushButton->setText("3: " + name);
        ui->newName_textEdit->clear();}
    if (currentState == "View 4"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view4_pushButton->setText("4: " + name);
        ui->newName_textEdit->clear();}
    if (currentState == "View 5"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view5_pushButton->setText("5: " + name);
        ui->newName_textEdit->clear();
    }
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Edit Views Window
// Apply All Changes
// Push Button Name:
// TextEdit Box Names:
// Push Button Names:
// Combo Box Name:
//This function clears and saves all new information when Apply All Changes is clicked
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
// TODO: Replace labels with NEW labels to make it work
void MainWindow::on_pushButton_11_clicked()
{
    QString currentState = ui->selectView_comboBox->currentText();
    if (currentState == "View 1"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view1_pushButton->setText("1: " + name);
        ui->newName_textEdit->clear();
        //This view has a cartesian pose for x,yz
        QString X = ui->XNEW_textEdit->toPlainText();
        QString Y = ui->YNEW_textEdit->toPlainText();
        QString Z = ui->ZNEW_textEdit->toPlainText();
        ui->XNEW_textEdit->clear();
        ui->YNEW_textEdit->clear();
        ui->ZNEW_textEdit->clear();
        //This view has 7DOF joint angles
        QString J1 = ui->NewJ1_textEdit->toPlainText();
        QString J2 = ui->NewJ2_textEdit->toPlainText();
        QString J3 = ui->NewJ3_textEdit->toPlainText();
        QString J4 = ui->NewJ4_textEdit->toPlainText();
        QString J5 = ui->NewJ5_textEdit->toPlainText();
        QString J6 = ui->NewJ6_textEdit->toPlainText();
        QString J7 = ui->NewJ7_textEdit->toPlainText();
        ui->NewJ1_horizontalSlider->setValue(0);
        ui->NewJ2_horizontalSlider->setValue(0);
        ui->NewJ3_horizontalSlider->setValue(0);
        ui->NewJ4_horizontalSlider->setValue(0);
        ui->NewJ5_horizontalSlider->setValue(0);
        ui->NewJ6_horizontalSlider->setValue(0);
        ui->NewJ7_horizontalSlider->setValue(0);
        ui->NewJ1_textEdit->clear();
        ui->NewJ2_textEdit->clear();
        ui->NewJ3_textEdit->clear();
        ui->NewJ4_textEdit->clear();
        ui->NewJ5_textEdit->clear();
        ui->NewJ6_textEdit->clear();
        ui->NewJ7_textEdit->clear();
        //This view has a roll,pitch, and yaw
        QString ROLL = ui->NewRoll_textEdit->toPlainText();
        QString PITCH = ui->NewPitch_textEdit->toPlainText();
        QString YAW = ui->NewYaw_textEdit->toPlainText();
        ui->Newdial->setValue(0);
        ui->New_horizontalSlider->setValue(0);
        ui->New_verticalSlider->setValue(0);
        ui->NewRoll_textEdit->clear();
        ui->NewPitch_textEdit->clear();
        ui->NewYaw_textEdit->clear();
    }
    if (currentState == "View 2"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view2_pushButton->setText("2: " + name);
        ui->newName_textEdit->clear();
    }
    if (currentState == "View 3"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view3_pushButton->setText("3: " + name);
        ui->newName_textEdit->clear();
    }
    if (currentState == "View 4"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view4_pushButton->setText("4: " + name);
        ui->newName_textEdit->clear();
    }
    if (currentState == "View 5"){
        QString name = ui->newName_textEdit->toPlainText();
        ui->view5_pushButton->setText("5: " + name);
        ui->newName_textEdit->clear();
    }
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Edit Views Window
// Edit Specific View
// Push Button Name:
// TextEdit Box Names:
// Push Button Names:
// Combo Box Name:
// This function should populate the tab with the information specific to that tab
// After is kinds sorts works, it should probably be placed before apply all changes and
// before change name
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
/*void MainWindow::on_selectView_comboBox_activated(const QString &arg1)
{
    //ui->newName_textEdit->setText(name1);
}*/

void MainWindow::on_StadndIn_pushButton_clicked()
{

   // ui->newName_textEdit->setText();
}

/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Relaxed IK Editor Window
// Update Specific Variable
// Dial and Slider Names:
// TextEdit Box Names:
// This function saves specific new variable information
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
QString *CurrentSpeedVal;
QString *CurrentSpeedWeight;
QString *CurrentViewingVal;
QString *CurrentViewingWeight;
QString *CurrentElevationVal;
QString *CurrentElevationWeight;
QString *CurrentRollWeight;
QString *CurrentHandlWeight;
void MainWindow::on_SpeedUpdate_pushButton_clicked()
{
    QString CurrentSpeedVal = ui->SpeedVal_textEdit->toPlainText();
    ui->SpeedVal_textEdit->setText(CurrentSpeedVal);
    QString CurrentSpeedWeight = ui->SpeedWeight_textEdit->toPlainText();
    ui->SpeedWeight_textEdit->setText(CurrentSpeedWeight);
}

void MainWindow::on_ViewingUpdate_pushButton_clicked()
{
    QString CurrentViewingVal = ui->ViewingVal_textEdit->toPlainText();
    ui->ViewingVal_textEdit->setText(CurrentViewingVal);
    QString CurrentViewingWeight = ui->ViewingWeight_textEdit->toPlainText();
    ui->ViewingWeight_textEdit->setText(CurrentViewingWeight);
}

void MainWindow::on_ElecationUpdate_pushButton_clicked()
{
    QString CurrentElevationVal = ui->ElevationVal_textEdit->toPlainText();
    ui->ElevationVal_textEdit->setText(CurrentElevationVal);
    QString CurrentElevationWeight = ui->ElevationWeight_textEdit->toPlainText();
    ui->ElevationWeight_textEdit->setText(CurrentElevationWeight);
}

void MainWindow::on_RollUpdate_pushButton_clicked()
{
    QString CurrentRollWeight = ui->RollWeight_textEdit->toPlainText();
    ui->RollWeight_textEdit->setText(CurrentRollWeight);
}

void MainWindow::on_HandUpdate_pushButton_clicked()
{
    QString CurrentHandWeight = ui->HandWeight_textEdit->toPlainText();
    ui->HandWeight_textEdit->setText(CurrentHandWeight);
}

/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Relaxed IK Editor Window
// Update Specific Variable
// Dial and Slider Names:
// TextEdit Box Names:
// This function resets the values and weights
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
void MainWindow::on_ResetVar_pushButton_clicked()
{
    ui->SpeedVal_textEdit->setText("10");
    ui->ViewingVal_textEdit->setText("9");
    ui->ElevationVal_textEdit->setText("8");
    //ui->RollVal_textEdit->setText("7");
    //ui->HandVal_textEdit->setText("6");
    ui->SpeedWeight_textEdit->setText("20");
    ui->ViewingWeight_textEdit->setText("19");
    ui->ElevationWeight_textEdit->setText("18");
    ui->RollWeight_textEdit->setText("17");
    ui->HandWeight_textEdit->setText("16");
}
/*/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// Relaxed IK Editor Window
// Update Specific Variable
// Dial and Slider Names:
// TextEdit Box Names:
// This function updates and saves the values and weights
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////*/
void MainWindow::on_UpdateAllVars_pushButton_clicked()
{
    QString CurrentSpeedVal = ui->SpeedVal_textEdit->toPlainText();
    ui->SpeedVal_textEdit->setText(CurrentSpeedVal);
    QString CurrentSpeedWeight = ui->SpeedWeight_textEdit->toPlainText();
    ui->SpeedWeight_textEdit->setText(CurrentSpeedWeight);
    QString CurrentViewingVal = ui->ViewingVal_textEdit->toPlainText();
    ui->ViewingVal_textEdit->setText(CurrentViewingVal);
    QString CurrentViewingWeight = ui->ViewingWeight_textEdit->toPlainText();
    ui->ViewingWeight_textEdit->setText(CurrentViewingWeight);
    QString CurrentElevationVal = ui->ElevationVal_textEdit->toPlainText();
    ui->ElevationVal_textEdit->setText(CurrentElevationVal);
    QString CurrentElevationWeight = ui->ElevationWeight_textEdit->toPlainText();
    ui->ElevationWeight_textEdit->setText(CurrentElevationWeight);
    QString CurrentRollWeight = ui->RollWeight_textEdit->toPlainText();
    ui->RollWeight_textEdit->setText(CurrentRollWeight);
    QString CurrentHandWeight = ui->HandWeight_textEdit->toPlainText();
    ui->HandWeight_textEdit->setText(CurrentHandWeight);
}







