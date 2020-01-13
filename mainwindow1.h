#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <QStringListModel>

#pragma once
#pragma execution_character_set("utf-8")
namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

private:
    QStringListModel *theModel;
    Ui::MainWindow1 *ui;
};

#endif // MAINWINDOW1_H
