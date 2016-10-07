/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *btnBook;
    QCheckBox *chkPensioner;
    QCheckBox *chkMinor;
    QCheckBox *chkAdult;
    QLineEdit *edtName;
    QLabel *label;
    QLabel *label_2;
    QListWidget *lstGroup;
    QPushButton *btnAdd;
    QPushButton *btnUndo;
    QLabel *lblAuditorium;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuSystem;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(374, 323);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnBook = new QPushButton(centralWidget);
        btnBook->setObjectName(QStringLiteral("btnBook"));
        btnBook->setGeometry(QRect(10, 210, 151, 22));
        chkPensioner = new QCheckBox(centralWidget);
        chkPensioner->setObjectName(QStringLiteral("chkPensioner"));
        chkPensioner->setGeometry(QRect(10, 120, 85, 20));
        chkPensioner->setChecked(true);
        chkMinor = new QCheckBox(centralWidget);
        chkMinor->setObjectName(QStringLiteral("chkMinor"));
        chkMinor->setGeometry(QRect(10, 160, 85, 20));
        chkAdult = new QCheckBox(centralWidget);
        chkAdult->setObjectName(QStringLiteral("chkAdult"));
        chkAdult->setGeometry(QRect(10, 140, 85, 20));
        edtName = new QLineEdit(centralWidget);
        edtName->setObjectName(QStringLiteral("edtName"));
        edtName->setGeometry(QRect(10, 100, 113, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 59, 14));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 0, 59, 14));
        lstGroup = new QListWidget(centralWidget);
        lstGroup->setObjectName(QStringLiteral("lstGroup"));
        lstGroup->setGeometry(QRect(10, 20, 161, 61));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(10, 180, 151, 22));
        btnUndo = new QPushButton(centralWidget);
        btnUndo->setObjectName(QStringLiteral("btnUndo"));
        btnUndo->setGeometry(QRect(10, 240, 151, 22));
        lblAuditorium = new QLabel(centralWidget);
        lblAuditorium->setObjectName(QStringLiteral("lblAuditorium"));
        lblAuditorium->setGeometry(QRect(180, 0, 59, 14));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(185, 21, 181, 121));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 374, 19));
        menuSystem = new QMenu(menuBar);
        menuSystem->setObjectName(QStringLiteral("menuSystem"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSystem->menuAction());
        menuSystem->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(btnBook, SIGNAL(clicked()), MainWindow, SLOT(repaint()));
        QObject::connect(btnAdd, SIGNAL(clicked()), MainWindow, SLOT(repaint()));
        QObject::connect(chkAdult, SIGNAL(clicked()), MainWindow, SLOT(repaint()));
        QObject::connect(chkPensioner, SIGNAL(clicked()), MainWindow, SLOT(repaint()));
        QObject::connect(chkMinor, SIGNAL(clicked()), MainWindow, SLOT(repaint()));
        QObject::connect(tableWidget, SIGNAL(cellPressed(int,int)), MainWindow, SLOT(repaint()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit...", 0));
        btnBook->setText(QApplication::translate("MainWindow", "Book", 0));
        chkPensioner->setText(QApplication::translate("MainWindow", "Pensioner", 0));
        chkMinor->setText(QApplication::translate("MainWindow", "Minor", 0));
        chkAdult->setText(QApplication::translate("MainWindow", "Adult", 0));
        label->setText(QApplication::translate("MainWindow", "Name:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Group:", 0));
        btnAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        btnUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        lblAuditorium->setText(QApplication::translate("MainWindow", "<name>", 0));
        menuSystem->setTitle(QApplication::translate("MainWindow", "&System", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
