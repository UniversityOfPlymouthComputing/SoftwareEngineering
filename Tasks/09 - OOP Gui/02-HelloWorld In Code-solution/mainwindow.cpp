#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connect signals to slots

    // source object: pushButton
    // signal: clicked()
    // destination object: this
    // slot: okButtonClicked(bool)
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::okButtonClicked);

    // source object: pushButton_2
    // signal: clicked()
    // destination object: this
    // slot: secondButtonClicked(bool)
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::secondButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::okButtonClicked(bool b)
{
    ui->labelMessage->setText("Hello World");
}

void MainWindow::secondButtonClicked(bool b)
{
    ui->labelMessage->setText("May the Force be With You");
}

