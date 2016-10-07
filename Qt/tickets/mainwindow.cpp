#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../../src/tickets_includes.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fa = new FixedAuditorium(5,5);
    fa->setName("Brooklyn");
    ui->lblAuditorium->setText("Brooklyn");
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);

    for(size_t i = 0 ; i < 25 ; i++){
        ui->tableWidget->setRowHeight(i,17);
        ui->tableWidget->setColumnWidth(i,34);
    }
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QPalette q;
    q.setColor(QPalette::Base , Qt::green);
    ui->tableWidget->setPalette(q);
    for(size_t i = 0 ; i < 5 ; i++)
        for(size_t j = 0 ; j < 5 ; j++){
            QTableWidgetItem *qtw = new QTableWidgetItem;
            ui->tableWidget->setItem(i,j,qtw);
        }
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

void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    ui->tableWidget->item(row,column)->setBackgroundColor(Qt::red);
}
