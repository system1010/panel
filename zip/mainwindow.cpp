#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QAbstractNativeEventFilter>

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotGlobalHotkey()
{
    // И сообщаем пользователю, если он нажал нужный нам HotKey
    QMessageBox::information(this,"Global Hotkey", "Global Hotkey is worked", QMessageBox::Ok);
}
