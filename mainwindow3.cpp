#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include <QFileDialog>
#include <QTextStream>

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);  //充满屏幕
    theModel = new QStandardItemModel(2,COLUMN,this); //设置默认两行6列
    theSelection = new QItemSelectionModel(theModel);
    connect(theSelection,SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

    LabCurFile = new QLabel(this);
    LabCellPos = new QLabel(this);
    LabCellText = new QLabel(this);

}

MainWindow3::~MainWindow3()
{
    delete ui;
}


void MainWindow3::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if(current.isValid())
    {
        LabCellPos->setText(QString::asprintf("当前单元格：%d行，%d列",
                                              current.row(),current.column()));
        QStandardItem *aItem = theModel->itemFromIndex(current);
        this->LabCellText->setText("单元格内容："+aItem->text());
    }
}

//打开文件 将文件中的数据存储tableView
void MainWindow3::on_actOpen_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString aFilename = QFileDialog::getOpenFileName(this,"选择一个文件",curPath,"数据文件(*.txt)");
    if(aFilename.isEmpty())
        return;

    QStringList fFileContenx;
    QFile afile(aFilename);
    if(afile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&afile);
        ui->plainTextEdit->clear();
        while(!aStream.atEnd())
        {
            QString str = aStream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fFileContenx.append(str);
        }
        afile.close();

        iniModelFromStringList(fFileContenx);
    }
}


void MainWindow3::iniModelFromStringList(QStringList &aFileContent)
{
    int rowCnt = aFileContent.count();
    theModel->setRowCount(rowCnt-1);
    QString header = aFileContent.at(0);
    QStringList headerList = header.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    theModel->setHorizontalHeaderLabels(headerList);
    QStandardItem *aItem;
    QStringList tmpList;
    int j;
    for(int i=1; i<rowCnt; i++)
    {
        QString aLineText = aFileContent.at(i);
        tmpList = aLineText.split(QRegExp("\\s+"),QString::SkipEmptyParts);
        for(j=0; j<COLUMN-1; j++)
        {
            aItem = new QStandardItem(tmpList.at(j));
            theModel->setItem(i-1, j, aItem);
        }
        aItem = new QStandardItem(headerList.at(j));
        aItem->setCheckable(true);
        if(tmpList.at(j) == "0")
            aItem->setCheckState(Qt::Unchecked);
        else
            aItem->setCheckState(Qt::Checked);
        theModel->setItem(i-1, j, aItem);
    }
}
