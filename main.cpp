#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("timecard");
        db.setUserName("root");
        db.setPassword("520520");
        bool ok = db.open();
        if (ok){
           qDebug()<<"mysql open successed!";
        }
        else {
            qDebug()<<"error open database because"<<db.lastError().text();
        }


    return a.exec();
}



