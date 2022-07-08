#include "mainwindow.h"
#include "ui_mainwindow.h"

BingoFileParser bingoFileParser;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    allBingos = bingoFileParser.getAllFiles();
    QStringListModel* model = new QStringListModel(this);
    for(string vectorString : allBingos) {
        QString text = QString::fromStdString(vectorString);
        list << text;
    }
    model->setStringList(list);
    ui->setupUi(this);
    ui->listView->setModel(model);
    srand(time(0));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_listView_clicked(const QModelIndex &index) {
    QString itemText = index.data(Qt::DisplayRole).toString();
    bingoDialog = new Bingo(this);
    bingoDialog->setBingoFilePath(itemText.toStdString());
    bingoDialog->onCreate();
    bingoDialog->show();
}

