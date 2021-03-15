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
    db.DataBaseAddContactTable(ui->lineEdit_Firstname->text(),ui->lineEdit_Lastname->text(),ui->lineEdit_Patronymic->text());
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

    db.DataBaseReqvestTable();
}
