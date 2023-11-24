#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonPrev_clicked();

    void on_buttonNext_clicked();

    void on_tableWidget_cellChanged(int row, int column);


private:
    Ui::MainWindow *ui;
    void updateMarks(float adjustment);
};
#endif // MAINWINDOW_H
