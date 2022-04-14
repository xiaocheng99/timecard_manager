#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QCameraInfo>
#include <QtSql/QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCameraInfo dc = QCameraInfo::defaultCamera();
        qDebug() << dc.description();
        camera = new QCamera();
        viewfinder = new QCameraViewfinder(ui->label_camera);
        imageCapture = new QCameraImageCapture(camera);
        ui->label_camera->setScaledContents(true);
        camera->setViewfinder(viewfinder);
        camera->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_submit_clicked()
{
       QString employee_id = ui->lineEdit_employee_id->text();
       QString department_id = ui->lineEdit_department_id->text();
       QString position_id = ui->lineEdit_position_id->text();
       QString employee_name = ui->lineEdit_position_id->text();
       QString cart_id = ui->lineEdit_cart_id->text();
       QString sex = ui->lineEdit_sex->text();
       QString phone = ui->lineEdit_phone->text();
       QString email = ui->lineEdit_email->text();
       QString pswd = ui->lineEdit_pswd->text();

       QSqlQuery query;
       query.prepare("insert into employee "
                     "(employee_id,department_id,position_id,employee_name,cart_id,sex,phone,email) "
                     "values (:employee_id,:department_id,:position_id,:employee_name,:cart_id,:sex,:phone,:email)" );
       query.bindValue(":employee_id",employee_id.toInt());
       query.bindValue(":department_id",department_id.toInt());
       query.bindValue(":position_id",position_id.toInt());
       query.bindValue(":employee_name",employee_name);
       query.bindValue(":cart_id",cart_id.toInt());
       query.bindValue(":sex",sex);
       query.bindValue(":phone",phone);
       query.bindValue(":email",email);
//       query.bindValue(8,pswd);

       if(!query.exec())
       {
          QSqlError lastError = query.lastError();
          qDebug() << "插入失败：" << lastError.driverText() << lastError.databaseText();
          return;
       }

}

void MainWindow::on_btn_capture_clicked()
{
    int count = ui->label_count->text().toInt();
    count++;
    ui->label_count->setText(QString::number(count));
    QString employee_id = ui->lineEdit_employee_id->text();
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->searchAndLock();
    QString file_path = "D:\\Desktop\\graduation thesis\\photo\\";
    QString file_name = QString::number(count) + "." + employee_id + ".jpg";
    imageCapture->capture(file_path+file_name);

    camera->unlock();

//    QPixmap pix ;
//    pix.load(file_path+file_name);
//    pix.scaled(ui->label_photo->width(),ui->label_photo->height());
//    ui->label_photo->setPixmap(pix);

}
