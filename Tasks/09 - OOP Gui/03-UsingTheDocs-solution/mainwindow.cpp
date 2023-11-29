#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &MainWindow::updateSlider);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSlider(int u)
{
    QString s = QString("%1").arg(u);
    ui->labelNumericValue->setText(s);
}
