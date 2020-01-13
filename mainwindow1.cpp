#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    QStringList theStringList;
    theStringList<<"北京"<<"上海"<<"广州"<<"深圳";
    theModel = new QStringListModel(this);
    theModel->setStringList(theStringList);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_2_clicked()
{
    theModel->QStringListModel::insertRow(theModel->rowCount());
    QModelIndex index = theModel->index(theModel->rowCount()-1,0);
    theModel->setData(index,"new item",Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

void MainWindow1::on_pushButton_7_clicked()
{
    QStringList list = theModel->stringList();
    ui->plainTextEdit->clear();
    for(int i=0; i<list.count();i++){
        ui->plainTextEdit->appendPlainText(list[i]);
    }
}
