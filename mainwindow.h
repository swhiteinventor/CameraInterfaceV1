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

    //void keyPressEvent(QKeyEvent * e);

private slots:
    void on_Manual_SwitchButton_clicked();

    void on_SetPoint_SaveViewButton_clicked();

    void on_UP_pushButton_clicked();

    void on_DOWN_pushButton_clicked();

    void on_OUT_pushButton_clicked();

    void on_IN_pushButton_clicked();

    void on_RIGHT_pushButton_clicked();

    void on_LEFT_pushButton_clicked();

    void on_J1_horizontalSlider_valueChanged(int value);

    void on_J2_horizontalSlider_valueChanged(int value);

    void on_J3_horizontalSlider_valueChanged(int value);

    void on_J4_horizontalSlider_valueChanged(int value);

    void on_J5_horizontalSlider_valueChanged(int value);

    void on_J6_horizontalSlider_valueChanged(int value);

    void on_J7_horizontalSlider_valueChanged(int value);

    void on_Roll_dial_valueChanged(int value);

    void on_Yaw_horizontalSlider_valueChanged(int value);

    void on_Pitch_verticalSlider_valueChanged(int value);

    void on_view1_pushButton_clicked();

    void on_view2_pushButton_clicked();

    void on_view3_pushButton_clicked();

    void on_view4_pushButton_clicked();

    void on_view5_pushButton_clicked();

    void on_addView_pushButton_clicked();

    void on_StandardView1_pushButton_clicked();

    void on_StandardView2_pushButton_clicked();

    void on_StandardView3_pushButton_clicked();

    void on_StandardView4_pushButton_clicked();

    void on_StandardView5_pushButton_clicked();

    //void on_addName_textEdit_textChanged(QKeyEvent *e);

    void on_applyNewName_pushButton_clicked();

    void on_NewUP_pushButton_clicked();

    void on_NewDOWN_pushButton_clicked();

    void on_NewLEFT_pushButton_clicked();

    void on_NewIN_pushButton_clicked();

    void on_NewOUT_pushButton_clicked();

    void on_NewRIGHT_pushButton_clicked();

    void on_NewJ1_horizontalSlider_valueChanged(int value);

    void on_NewJ2_horizontalSlider_valueChanged(int value);

    void on_NewJ3_horizontalSlider_valueChanged(int value);

    void on_NewJ4_horizontalSlider_valueChanged(int value);

    void on_NewJ5_horizontalSlider_valueChanged(int value);

    void on_NewJ6_horizontalSlider_valueChanged(int value);

    void on_NewJ7_horizontalSlider_valueChanged(int value);

    void on_Newdial_valueChanged(int value);

    void on_New_horizontalSlider_valueChanged(int value);

    void on_New_verticalSlider_valueChanged(int value);

    void on_SpeedUpdate_pushButton_clicked();

    void on_ViewingUpdate_pushButton_clicked();

    void on_ElecationUpdate_pushButton_clicked();

    void on_RollUpdate_pushButton_clicked();

    void on_HandUpdate_pushButton_clicked();

    void on_ResetVar_pushButton_clicked();

    void on_UpdateAllVars_pushButton_clicked();

    void on_selectView_comboBox_activated(const QString &arg1);

    void on_ApplyAllChanges_pushButton_clicked();

    void on_Speed_horizontalSlider_valueChanged(int value);

    void on_ViewingDistance_horizontalSlider_valueChanged(int value);

    void on_Elevation_horizontalSlider_valueChanged(int value);

    void on_CameraRoll_horizontalSlider_valueChanged(int value);

    void on_LookAtHand_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    bool checkCameraAvailability();
};
#endif // MAINWINDOW_H
