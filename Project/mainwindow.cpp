#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"

BingoFileParser bingoFileParser;
bool MainWindow::sounds = true;

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
    ui->listView_bingos->setModel(model);

    srand(time(0));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent( QKeyEvent* event) {
    switch(event->key()) {
        case Qt::Key_Control:
            ui->textBrowser_changelog->setText(
                        "QSysInfo\n" +
                        QSysInfo::kernelType() + " " + QSysInfo::currentCpuArchitecture() + "\n" +
                        QSysInfo::kernelVersion() + "\n" +
                        QSysInfo::productType() + " " + QSysInfo::productVersion() + "\n" +
                        QSysInfo::prettyProductName() + "\n" +
                        QSysInfo::machineHostName() + "\n" +
                        QSysInfo::machineUniqueId() + "\n" +
                        QSysInfo::bootUniqueId() + "\n"
                        );
        break;
    }
}

void MainWindow::on_listView_bingos_clicked(const QModelIndex &index) {
    QString itemText = index.data(Qt::DisplayRole).toString();
    bingoDialog = new Bingo(this);
    bingoDialog->setBingoFilePath("bingos/" + itemText.toStdString() + ".bgo");
    bingoDialog->onCreate();
    bingoDialog->setAttribute(Qt::WA_DeleteOnClose);
    bingoDialog->show();
}


void MainWindow::on_actionD_wi_ki_triggered(bool checked)
{
    sounds = checked;
}

