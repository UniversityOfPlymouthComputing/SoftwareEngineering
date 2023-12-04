#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::doButtonClick);
    connect(ui->actionWise_Saying, &QAction::triggered, this, &MainWindow::doWiseSayingMenuClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doButtonClick(bool b)
{
    ui->labelMessage->setText("Hello World");
}

void MainWindow::doWiseSayingMenuClicked()
{
    ui->labelMessage->setText("Live Long and Prosper");
}
