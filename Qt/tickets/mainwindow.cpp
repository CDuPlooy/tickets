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

    fa->enableMemento(true);
    fa->setVoid(0,2,1,false);
    fa->getMemento()->callback(&backX , &backY , &backState);
    fa->getMemento()->guiMode = true;

    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);

    for(size_t i = 0 ; i < 25 ; i++){
        ui->tableWidget->setRowHeight(i,17);
        ui->tableWidget->setColumnWidth(i,34);
    }
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QPalette q;
    q.setColor(QPalette::Base , Qt::blue);
    ui->tableWidget->setPalette(q);
    for(size_t i = 0 ; i < 5 ; i++)
        for(size_t j = 0 ; j < 5 ; j++){
            QTableWidgetItem *qtw = new QTableWidgetItem;
            ui->tableWidget->setItem(i,j,qtw);
            if(fa->getState(i,j)==SEAT_VOID)
                ui->tableWidget->item(i,j)->setBackgroundColor(Qt::black);
        }
    ui->lstGroup->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lstGroup->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->lstGroup->repaint();

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
    QString preThingy("");
    if(ui->chkAdult->isChecked())
            preThingy = "A:";
    if(ui->chkMinor->isChecked())
            preThingy = "M:";
    if(ui->chkPensioner->isChecked())
            preThingy = "P:";

    ui->lstGroup->addItem(preThingy + ui->edtName->text());
    ui->edtName->setText("");
}

void MainWindow::on_btnBook_clicked()
{
    size_t numPeople = ui->lstGroup->count();
    Group *group = new Group();
    for(size_t i = 0 ; i < numPeople ; i++){
        if(ui->lstGroup->item(i)->text()[0] == 'A'){
            uncheckAll();
            ui->chkAdult->setChecked(true);
            }
        if(ui->lstGroup->item(i)->text()[0] == 'M'){
            uncheckAll();
            ui->chkMinor->setChecked(true);
            }
        if(ui->lstGroup->item(i)->text()[0] == 'P'){
            uncheckAll();
            ui->chkPensioner->setChecked(true);
            }

        group->push_back(newPerson());
    }
    fa->bookAdv(*group);
    delete group;
    repaintView();
}
void MainWindow::repaintView(){
    for(size_t i = 0 ; i < 5 ; i++)
        for(size_t j = 0 ; j < 5 ; j++){
            if(fa->getState(i,j)==SEAT_VOID)
               ui->tableWidget->item(i,j)->setBackgroundColor(Qt::black);
            if(fa->getState(i,j)==SEAT_EMPTY)
               ui->tableWidget->item(i,j)->setBackgroundColor(Qt::blue);
            if(fa->getState(i,j)==SEAT_TAKEN)
               ui->tableWidget->item(i,j)->setBackgroundColor(Qt::red);
        }
}

bool MainWindow::checkPerson(){
    unsigned short errors = 0;
    if(ui->edtName->text().length() == 0)
          errors++;
    if(!ui->chkAdult->isChecked() && !ui->chkMinor->isChecked() && !ui->chkPensioner->isChecked())
           errors++;
    return !errors; //Gotta love this.
}

Person *MainWindow::newPerson(){
    Person *person;
    if(ui->chkAdult->isChecked()){
        person = new Adult();
    }
    if(ui->chkMinor->isChecked()){
        person = new Minor();
    }
    if(ui->chkPensioner->isChecked()){
        person = new Pensioner();
    }
    person->setName(ui->edtName->text().toStdString());
    return person;
}
void MainWindow::debug(){
      QMessageBox messageBox;
      messageBox.setText("Debug");
      messageBox.setWindowTitle("Message:  ");
      messageBox.exec();
}

void MainWindow::on_tableWidget_doubleClicked(const QModelIndex &index)
{

    if(!checkPerson()){
        QMessageBox messageBox;
        messageBox.setText("Please fill out all forms!");
        messageBox.setWindowTitle("Message:  ");
        messageBox.exec();
        return;
    }
    else{
        Person *person = newPerson();
        if(fa->getState(index.row(),index.column()) == SEAT_VOID || fa->getState(index.row(),index.column()) == SEAT_TAKEN){
            QMessageBox messageBox;
            messageBox.setText("You cannot book this seat!");
            messageBox.setWindowTitle("Error:  ");
            messageBox.exec();
            delete person;
            return;
        }

        if(!fa->book(person,index.row(),index.column())){
            delete person;
            return;
        }
        ui->tableWidget->item(index.row(),index.column())->setBackgroundColor(Qt::red);
        ui->edtName->clear();
    }

}

void MainWindow::on_btnUndo_clicked()
{
    Debug();
     if(fa->mementoLinked()){
        fa->undo();

        if(backState == SEAT_EMPTY)
            ui->tableWidget->item(backX,backY)->setBackgroundColor(Qt::red);
        else
            ui->tableWidget->item(backX,backY)->setBackgroundColor(Qt::blue);

     }
     repaintView();

}

void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    return;
}
