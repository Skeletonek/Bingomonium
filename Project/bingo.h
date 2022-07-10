#ifndef BINGO_H
#define BINGO_H

#include <QDialog>
#include <map>
#include <QLabel>
#include <QSizePolicy>
#include <QSysInfo>
#include <QMediaPlayer>
#include <QAudioOutput>

using namespace std;

namespace Ui {
class Bingo;
}

class Bingo : public QDialog {
    Q_OBJECT

public:
    explicit Bingo(QWidget *parent = nullptr);
    ~Bingo();
    int bingoID;
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    void setBingoFilePath(string bingoFilePath_Value);

    void onCreate();

private:
    Ui::Bingo *ui;

    int bingoCount;
    bool bingo[5][5];
    string bingoText[5][5];
    string bingoFilePath;
    QPushButton *btnArr[25];
    QObjectList buttons;
    vector<string> bingoCategories;
    vector<string> bingoValues;

    void constructButtons();
    void fillInButtons();
    void wordWrapQLabel(QString str, int btnIndex);
    void createBingo();
    int checkBingo();
    void setBingoCountText(int bingoCount_);
    void playAudio(int bingoCount_);
    void onPushButtonClicked();

private slots:
    void on_pushButton11_clicked();
    void on_pushButton12_clicked();
    void on_pushButton13_clicked();
    void on_pushButton14_clicked();
    void on_pushButton15_clicked();
    void on_pushButton21_clicked();
    void on_pushButton22_clicked();
    void on_pushButton23_clicked();
    void on_pushButton24_clicked();
    void on_pushButton25_clicked();
    void on_pushButton31_clicked();
    void on_pushButton32_clicked();
    void on_pushButton33_clicked();
    void on_pushButton34_clicked();
    void on_pushButton35_clicked();
    void on_pushButton41_clicked();
    void on_pushButton42_clicked();
    void on_pushButton43_clicked();
    void on_pushButton44_clicked();
    void on_pushButton45_clicked();
    void on_pushButton51_clicked();
    void on_pushButton52_clicked();
    void on_pushButton53_clicked();
    void on_pushButton54_clicked();
    void on_pushButton55_clicked();
    void on_Bingo_destroyed();
};

#endif // BINGO_H
