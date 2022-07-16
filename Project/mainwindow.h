#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStringListModel>
#include <vector>
#include <QSysInfo>

#include <bingo.h>
#include <bingofileparser.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listView_bingos_clicked(const QModelIndex &index);
    void keyPressEvent(QKeyEvent* k);

private:
    Ui::MainWindow *ui;
    Bingo *bingoDialog;

    vector<string> allBingos;
    QStringList list;
};
#endif // MAINWINDOW_H
