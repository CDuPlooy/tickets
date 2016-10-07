#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../../src/tickets_includes.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fa = new FixedAuditorium(5,5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}

void MainWindow::uncheckAll(){
    ui->chkAdult->setChecked(false);
    ui->chkMinor->setChecked(false);
    ui->chkPensioner->setChecked(false);
}

void MainWindow::on_chkAdult_clicked()
{
    uncheckAll();
     ui->chkAdult->setChecked(true);
}

void MainWindow::on_chkPensioner_clicked()
{
    uncheckAll();
    ui->chkPensioner->setChecked(true);
}

void MainWindow::on_chkMinor_clicked()
{
    uncheckAll();
    ui->chkMinor->setChecked(true);
}


void MainWindow::on_btnAdd_clicked()
{
    ui->lstGroup->addItem(ui->edtName->text());
    ui->edtName->setText("");
}

void MainWindow::on_btnBook_clicked()
{

}
