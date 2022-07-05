#include "mainwindow.h"
#include "ui_mainwindow.h"

BingoFileParser bingoFileParser;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    allBingos = bingoFileParser.getAllFiles();
    QStringListModel* model = new QStringListModel(this);
    QStringList list;
    for(string vectorString : allBingos){
        QString text = QString::fromStdString(vectorString);
        list << text;
    }
    model->setStringList(list);
    ui->setupUi(this);
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bingoDialog = new Bingo(this);
    bingoDialog->show();
}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    bingoDialog = new Bingo(this);
    bingoDialog->show();
}

