#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QPixmap>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QCamera *camera ;
    QCameraViewfinder * viewfinder;
    QCameraImageCapture *imageCapture ;
private slots:

    void on_btn_submit_clicked();

    void on_btn_capture_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
