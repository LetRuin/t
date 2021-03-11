#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("mysql60.hostland.ru");
        db.setDatabaseName("host1323541_irkutsk0");
        db.setUserName("host1323541_itstep");
        db.setPassword("269f43dc");
        bool ok = db.open();

        if (ok) {
            QMessageBox msg;
            msg.setText("УРА! Мы подключились.");
            msg.setIcon(QMessageBox::Information);
            msg.exec();
        } else {
            QMessageBox msg;
            msg.setText("Увы.. Мы не подключились.");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
}
