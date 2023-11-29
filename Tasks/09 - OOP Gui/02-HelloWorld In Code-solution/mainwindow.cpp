#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect signal to slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::okButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::okButtonClicked(bool b)
{
    ui->labelMessage->setText("Hello World");
}

