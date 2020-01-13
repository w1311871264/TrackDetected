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
    QLabel *LabCurFile;                      //��ǰ�ļ���
    QLabel *LabCellPos;                      //��ǰ��Ԫ�����к�
    QLabel *LabCellText;                     //��ǰ��Ԫ������
    QStandardItemModel *theModel;//����ģ��
    QItemSelectionModel *theSelection;//ѡ��ģ��
    void iniModelFromStringList(QStringList&); //��ʼ������ģ��

    Ui::MainWindow3 *ui;

private slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

    void on_actOpen_triggered();
};

#endif // MAINWINDOW3_H
