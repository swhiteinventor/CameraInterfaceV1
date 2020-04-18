#include "saveeditview.h"
#include "ui_saveeditview.h"
#include <QDebug>

SaveEditView::SaveEditView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveEditView)
{
    ui->setupUi(this);

    QSlider *JA1_horizontalSlider = new QSlider(Qt::Horizontal);
    JA1_horizontalSlider->setRange(0, 100.00000);
    //JA1_horizontalSlider->setSingleStep(100.00000/1000.00000);

}

SaveEditView::~SaveEditView()
{
    delete ui;
}

void SaveEditView::on_exit_pushButton_clicked()
{
    this->hide();
}

void SaveEditView::on_SaveToView_pushButton_clicked()
{
    if (ui->view1Name_label->text().isEmpty()){
        QString name = ui->Name_textEdit->toPlainText();
        ui->view1Name_label->setText(name);
        QString jointAngle = ui->JA_textEdit->toPlainText();
        ui->JA1_label->setText(jointAngle);
        ui->Name_textEdit->clear();
        ui->JA_textEdit->clear();
    }
    else if (ui->view2Name_label->text().isEmpty()){
        QString name = ui->Name_textEdit->toPlainText();
        ui->view2Name_label->setText(name);
        QString jointAngle = ui->JA_textEdit->toPlainText();
        ui->JA2_label->setText(jointAngle);
        ui->Name_textEdit->clear();
        ui->JA_textEdit->clear();
    }
    else if (ui->view3Name_label->text().isEmpty()){
        QString name = ui->Name_textEdit->toPlainText();
        ui->view3Name_label->setText(name);
        QString jointAngle = ui->JA_textEdit->toPlainText();
        ui->JA3_label->setText(jointAngle);
        ui->Name_textEdit->clear();
        ui->JA_textEdit->clear();
    }
    else if (ui->view4Name_label->text().isEmpty()){
        QString name = ui->Name_textEdit->toPlainText();
        ui->view4Name_label->setText(name);
        QString jointAngle = ui->JA_textEdit->toPlainText();
        ui->JA4_label->setText(jointAngle);
        ui->Name_textEdit->clear();
        ui->JA_textEdit->clear();
    }
    else if(ui->view5Name_label->text().isEmpty()){
        QString name = ui->Name_textEdit->toPlainText();
        ui->view5Name_label->setText(name);
        QString jointAngle = ui->JA_textEdit->toPlainText();
        ui->JA5_label->setText(jointAngle);
        ui->Name_textEdit->clear();
        ui->JA_textEdit->clear();
    }
}

int SaveEditView::count = 0; // initial definition

void SaveEditView::on_editView1_pushButton_clicked()
{
    QString name1 = ui->view1Name_label->text();
    ui->editName_textEdit->setText(name1);

    QString str = ui->JA1_label->text();

    SaveEditView::count = 1;

    QRegExp rx("[,]");// match a comma or a space
    QStringList list = str.split(rx, QString::SkipEmptyParts);

    qDebug() << list;

    QString JA1 = list.at(0);
    QString JA2 = list.at(1);
    QString JA3 = list.at(2);
    QString JA4 = list.at(3);
    QString JA5 = list.at(4);
    QString JA6 = list.at(5);
    QString JA7 = list.at(6);

    ui->JA1textEdit->setText(JA1);
    float value = JA1.toFloat();
    ui->JA1_horizontalSlider->setValue(value);

    ui->JA2_textEdit->setText(JA2);
    float value2 = JA2.toFloat();
    ui->JA2_horizontalSlider->setValue(value2);

    ui->JA3_textEdit->setText(JA3);
    float value3 = JA3.toFloat();
    ui->JA3_horizontalSlider->setValue(value3);

    ui->JA4_textEdit->setText(JA4);
    float value4 = JA4.toFloat();
    ui->JA4_horizontalSlider->setValue(value4);

    ui->JA5_textEdit->setText(JA5);
    float value5 = JA5.toFloat();
    ui->JA5_horizontalSlider->setValue(value5);

    ui->JA6_textEdit->setText(JA6);
    float value6 = JA6.toFloat();
    ui->JA6_horizontalSlider->setValue(value6);

    ui->JA7_textEdit->setText(JA7);
    float value7 = JA7.toFloat();
    ui->JA7_horizontalSlider->setValue(value7);
}

void SaveEditView::on_editView2_pushButton_clicked()
{
    QString name1 = ui->view2Name_label->text();
    ui->editName_textEdit->setText(name1);

    QString str = ui->JA2_label->text();

    SaveEditView::count = 2;

    QRegExp rx("[,]");// match a comma or a space
    QStringList list = str.split(rx, QString::SkipEmptyParts);

    qDebug() << list;

    QString JA1 = list.at(0);
    QString JA2 = list.at(1);
    QString JA3 = list.at(2);
    QString JA4 = list.at(3);
    QString JA5 = list.at(4);
    QString JA6 = list.at(5);
    QString JA7 = list.at(6);

    ui->JA1textEdit->setText(JA1);
    float value = JA1.toFloat();
    ui->JA1_horizontalSlider->setValue(value);

    ui->JA2_textEdit->setText(JA2);
    float value2 = JA2.toFloat();
    ui->JA2_horizontalSlider->setValue(value2);

    ui->JA3_textEdit->setText(JA3);
    float value3 = JA3.toFloat();
    ui->JA3_horizontalSlider->setValue(value3);

    ui->JA4_textEdit->setText(JA4);
    float value4 = JA4.toFloat();
    ui->JA4_horizontalSlider->setValue(value4);

    ui->JA5_textEdit->setText(JA5);
    float value5 = JA5.toFloat();
    ui->JA5_horizontalSlider->setValue(value5);

    ui->JA6_textEdit->setText(JA6);
    float value6 = JA6.toFloat();
    ui->JA6_horizontalSlider->setValue(value6);

    ui->JA7_textEdit->setText(JA7);
    float value7 = JA7.toFloat();
    ui->JA7_horizontalSlider->setValue(value7);
}

void SaveEditView::on_editView3_pushButton_clicked()
{
    QString name1 = ui->view3Name_label->text();
    ui->editName_textEdit->setText(name1);

    QString str = ui->JA3_label->text();

    SaveEditView::count = 3;

    QRegExp rx("[,]");// match a comma or a space
    QStringList list = str.split(rx, QString::SkipEmptyParts);

    qDebug() << list;

    QString JA1 = list.at(0);
    QString JA2 = list.at(1);
    QString JA3 = list.at(2);
    QString JA4 = list.at(3);
    QString JA5 = list.at(4);
    QString JA6 = list.at(5);
    QString JA7 = list.at(6);

    ui->JA1textEdit->setText(JA1);
    float value = JA1.toFloat();
    ui->JA1_horizontalSlider->setValue(value);

    ui->JA2_textEdit->setText(JA2);
    float value2 = JA2.toFloat();
    ui->JA2_horizontalSlider->setValue(value2);

    ui->JA3_textEdit->setText(JA3);
    float value3 = JA3.toFloat();
    ui->JA3_horizontalSlider->setValue(value3);

    ui->JA4_textEdit->setText(JA4);
    float value4 = JA4.toFloat();
    ui->JA4_horizontalSlider->setValue(value4);

    ui->JA5_textEdit->setText(JA5);
    float value5 = JA5.toFloat();
    ui->JA5_horizontalSlider->setValue(value5);

    ui->JA6_textEdit->setText(JA6);
    float value6 = JA6.toFloat();
    ui->JA6_horizontalSlider->setValue(value6);

    ui->JA7_textEdit->setText(JA7);
    float value7 = JA7.toFloat();
    ui->JA7_horizontalSlider->setValue(value7);
}

void SaveEditView::on_editView4_pushButton_clicked()
{
    QString name1 = ui->view4Name_label->text();
    ui->editName_textEdit->setText(name1);

    QString str = ui->JA4_label->text();

    SaveEditView::count = 4;

    QRegExp rx("[,]");// match a comma or a space
    QStringList list = str.split(rx, QString::SkipEmptyParts);

    qDebug() << list;

    QString JA1 = list.at(0);
    QString JA2 = list.at(1);
    QString JA3 = list.at(2);
    QString JA4 = list.at(3);
    QString JA5 = list.at(4);
    QString JA6 = list.at(5);
    QString JA7 = list.at(6);

    ui->JA1textEdit->setText(JA1);
    float value = JA1.toFloat();
    ui->JA1_horizontalSlider->setValue(value);

    ui->JA2_textEdit->setText(JA2);
    float value2 = JA2.toFloat();
    ui->JA2_horizontalSlider->setValue(value2);

    ui->JA3_textEdit->setText(JA3);
    float value3 = JA3.toFloat();
    ui->JA3_horizontalSlider->setValue(value3);

    ui->JA4_textEdit->setText(JA4);
    float value4 = JA4.toFloat();
    ui->JA4_horizontalSlider->setValue(value4);

    ui->JA5_textEdit->setText(JA5);
    float value5 = JA5.toFloat();
    ui->JA5_horizontalSlider->setValue(value5);

    ui->JA6_textEdit->setText(JA6);
    float value6 = JA6.toFloat();
    ui->JA6_horizontalSlider->setValue(value6);

    ui->JA7_textEdit->setText(JA7);
    float value7 = JA7.toFloat();
    ui->JA7_horizontalSlider->setValue(value7);
}

void SaveEditView::on_editView5_pushButton_clicked()
{
    QString name1 = ui->view5Name_label->text();
    ui->editName_textEdit->setText(name1);

    QString str = ui->JA5_label->text();

    SaveEditView::count = 5;

    QRegExp rx("[,]");// match a comma or a space
    QStringList list = str.split(rx, QString::SkipEmptyParts);

    qDebug() << list;

    QString JA1 = list.at(0);
    QString JA2 = list.at(1);
    QString JA3 = list.at(2);
    QString JA4 = list.at(3);
    QString JA5 = list.at(4);
    QString JA6 = list.at(5);
    QString JA7 = list.at(6);

    ui->JA1textEdit->setText(JA1);
    float value = JA1.toFloat();
    ui->JA1_horizontalSlider->setValue(value);

    ui->JA2_textEdit->setText(JA2);
    float value2 = JA2.toFloat();
    ui->JA2_horizontalSlider->setValue(value2);

    ui->JA3_textEdit->setText(JA3);
    float value3 = JA3.toFloat();
    ui->JA3_horizontalSlider->setValue(value3);

    ui->JA4_textEdit->setText(JA4);
    float value4 = JA4.toFloat();
    ui->JA4_horizontalSlider->setValue(value4);

    ui->JA5_textEdit->setText(JA5);
    float value5 = JA5.toFloat();
    ui->JA5_horizontalSlider->setValue(value5);

    ui->JA6_textEdit->setText(JA6);
    float value6 = JA6.toFloat();
    ui->JA6_horizontalSlider->setValue(value6);

    ui->JA7_textEdit->setText(JA7);
    float value7 = JA7.toFloat();
    ui->JA7_horizontalSlider->setValue(value7);
}

void SaveEditView::on_JA1_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA1textEdit->setText(b);
}

void SaveEditView::on_JA2_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA2_textEdit->setText(b);
}

void SaveEditView::on_JA3_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA3_textEdit->setText(b);
}

void SaveEditView::on_JA4_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA4_textEdit->setText(b);
}

void SaveEditView::on_JA5_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA5_textEdit->setText(b);
}

void SaveEditView::on_JA6_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA6_textEdit->setText(b);
}

void SaveEditView::on_JA7_horizontalSlider_valueChanged(int value)
{
    float intValue = value;
    QString b = QString::number(intValue);
    ui->JA7_textEdit->setText(b);
}

void SaveEditView::on_saveNew_pushButton_clicked()
{
    if(SaveEditView::count == 1){
        QString nameNew = ui->editName_textEdit->toPlainText();
        ui->view1Name_label->setText(nameNew);
    }
    else if(SaveEditView::count == 2){
        QString nameNew = ui->editName_textEdit->toPlainText();
        ui->view2Name_label->setText(nameNew);
        }
    else if(SaveEditView::count == 3){
        QString nameNew = ui->editName_textEdit->toPlainText();
        ui->view3Name_label->setText(nameNew);
        }
    else if(SaveEditView::count == 4){
        QString nameNew = ui->editName_textEdit->toPlainText();
        ui->view4Name_label->setText(nameNew);
        }
    else if(SaveEditView::count == 5){
        QString nameNew = ui->editName_textEdit->toPlainText();
        ui->view5Name_label->setText(nameNew);
        }
}

