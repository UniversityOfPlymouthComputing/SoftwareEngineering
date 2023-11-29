#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <functional>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set the dimensions of the table ui->tableWidget
    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setColumnCount(2);

    //Populate with some data
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("COMP1010"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("55.7"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("COMP1234"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("80.4"));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("COMP1066"));
    ui->tableWidget->setItem(2, 1, new QTableWidgetItem("55.7"));

    qDebug() << "Ready\n";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMarks(float adjustment)
{
    //Read and convert to numbers again, modify, and write back
    QTableWidget* tableWidget = ui->tableWidget;

    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        QString strData = tableWidget->item(row,1)->text();
        bool didConvert;
        float val = strData.toFloat(&didConvert);
        if (didConvert) {
            QString strVal = tr("%1").arg(val+adjustment);
            QTableWidgetItem *newItem = new QTableWidgetItem(strVal);
            tableWidget->setItem(row, 1, newItem);
        }
    }
}

void MainWindow::on_buttonPrev_clicked()
{
    updateMarks(-1.0f);
}


void MainWindow::on_buttonNext_clicked()
{
    updateMarks(1.0f);
}


void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    qDebug() << "cellChanged: " << row << " and column " << column;
    qDebug() << ui->tableWidget->item(row, column)->text();
}



