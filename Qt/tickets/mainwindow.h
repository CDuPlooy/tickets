#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "../../src/FixedAuditorium.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    size_t backX;
    size_t backY;
    short backState;

private slots:
    void on_pushButton_clicked();
    bool checkPerson();
    void uncheckAll();
    void on_actionQuit_triggered();

    void on_chkAdult_clicked();

    void on_chkPensioner_clicked();
    Person *newPerson();
    void on_chkMinor_clicked();

    void on_btnBook_clicked();
    void repaintView();
    void on_btnAdd_clicked();
    void debug();

    void on_tableWidget_cellPressed(int row, int column);

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_btnUndo_clicked();

private:
    Ui::MainWindow *ui;
    FixedAuditorium *fa;
};

#endif // MAINWINDOW_H
