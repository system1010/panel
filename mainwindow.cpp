#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QProcess>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nativeEventFilter = new NativeEventFilter(this);    // Инициализируем фильтр
    qApp->installNativeEventFilter(nativeEventFilter);  // Устанавилваем его на приложение
    // подключаем сигнал фильтра к слоту
    connect(nativeEventFilter, &NativeEventFilter::activated, this, &MainWindow::slotGlobalHotkey);
    nativeEventFilter->setShortcut();   // Устанавилваем хоткей
    QPushButton* button = new QPushButton;
    button->show();
    button->setText("Browser");
    button->setGeometry(10,10,80,23);
    connect(button, SIGNAL(clicked()), this, SLOT(slotButton()));
    QPushButton* button1 = new QPushButton;
    button1->show();
    button1->setText("Terminal");
    button1->setGeometry(10,35,80,23);
    connect(button1, SIGNAL(clicked()), this, SLOT(slotButton1()));
    QPushButton* button2 = new QPushButton;
    button2->show();
    button2->setText("QtCreator");
    button2->setGeometry(10,60,80,23);
    connect(button2, SIGNAL(clicked()), this, SLOT(slotButton2()));
    QPushButton* button3 = new QPushButton;
    button3->show();
    button3->setText("Off");
    button3->setGeometry(10,85,80,23);
    connect(button3, SIGNAL(clicked()), this, SLOT(slotButton3()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotButton()
{
    QProcess process;
    process.startDetached("quicknanobrowser");
}
void MainWindow::slotButton1()
{
    QProcess process;
    process.startDetached("minimal-term -geometry 400x500-1+1");
}
void MainWindow::slotButton2()
{
    QProcess process;
    process.startDetached("/opt/Qt5.9.8/Tools/QtCreator/bin/qtcreator");
}
void MainWindow::slotButton3()
{
    QProcess process;
    process.startDetached("init 0");
}

void MainWindow::slotGlobalHotkey()
{
    // И сообщаем пользователю, если он нажал нужный нам HotKey
    QMessageBox::information(this,"Global Hotkey", "Global Hotkey is worked", QMessageBox::Ok);
}

