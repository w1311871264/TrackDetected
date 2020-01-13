#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>

const int COLUMN = 6;

namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private:
    QLabel *LabCurFile;                      //当前文件夹
    QLabel *LabCellPos;                      //当前单元格行列号
    QLabel *LabCellText;                     //当前单元格内容
    QStandardItemModel *theModel;//数据模型
    QItemSelectionModel *theSelection;//选择模型
    void iniModelFromStringList(QStringList&); //初始化数据模型

    Ui::MainWindow3 *ui;

private slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_actOpen_triggered();
};

#endif // MAINWINDOW3_H
