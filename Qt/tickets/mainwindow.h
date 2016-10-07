#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void on_pushButton_clicked();
    void uncheckAll();
    void on_actionQuit_triggered();

    void on_chkAdult_clicked();

    void on_chkPensioner_clicked();

    void on_chkMinor_clicked();

    void on_btnBook_clicked();

    void on_btnAdd_clicked();

    void on_tableWidget_cellPressed(int row, int column);

private:
    Ui::MainWindow *ui;
    FixedAuditorium *fa;
};

#endif // MAINWINDOW_H
