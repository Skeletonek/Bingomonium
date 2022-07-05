#include "bingo.h"
#include "ui_bingo.h"
#include "bingofileparser.h"
#include <QLabel>
#include <QSizePolicy>

BingoFileParser bingoFileParse;

Bingo::Bingo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bingo){
    bingoFileParse.readFile("bingos/CSGOBingoDB.txt");
    bingoValues = bingoFileParse.getValuesData();
    createBingo();
    ui->setupUi(this);
    constructButtons();
    fillInButtons();
    //wordWrapQLabel(); Method broken: Don't use
}

Bingo::~Bingo(){
    delete ui;
}

void Bingo::on_Bingo_destroyed(){
}

void Bingo::wordWrapQLabel(QString str, int btnIndex){
    auto label = new QLabel(str, btnArr[btnIndex]);
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignHCenter);
    label->setGeometry(0, 0, 105, 100); //Find out how to get buttons size
    label->setMargin(8);
    label->setStyleSheet("background-color: none;");
}

void Bingo::createBingo(){
    int random;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(bingoValues.size() != 0){
            random = rand()%(bingoValues.size());
            string tile_tmp = bingoValues.at(random);
            bingoValues.erase(bingoValues.begin()+random);
            bingoText[i][j] = tile_tmp;
            }
        }
    }
}

void Bingo::constructButtons(){
    buttons = ui->buttonsGrid->children();
    btnArr[0] = ui->pushButton11;
    btnArr[1] = ui->pushButton12;
    btnArr[2] = ui->pushButton13;
    btnArr[3] = ui->pushButton14;
    btnArr[4] = ui->pushButton15;
    btnArr[5] = ui->pushButton21;
    btnArr[6] = ui->pushButton22;
    btnArr[7] = ui->pushButton23;
    btnArr[8] = ui->pushButton24;
    btnArr[9] = ui->pushButton25;
    btnArr[10] = ui->pushButton31;
    btnArr[11] = ui->pushButton32;
    btnArr[12] = ui->pushButton33;
    btnArr[13] = ui->pushButton34;
    btnArr[14] = ui->pushButton35;
    btnArr[15] = ui->pushButton41;
    btnArr[16] = ui->pushButton42;
    btnArr[17] = ui->pushButton43;
    btnArr[18] = ui->pushButton44;
    btnArr[19] = ui->pushButton45;
    btnArr[20] = ui->pushButton51;
    btnArr[21] = ui->pushButton52;
    btnArr[22] = ui->pushButton53;
    btnArr[23] = ui->pushButton54;
    btnArr[24] = ui->pushButton55;
}

void Bingo::fillInButtons(){
    int k = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            wordWrapQLabel(QString::fromStdString(bingoText[i][j]), k);
            //btnArr[k]->setText(QString::fromStdString(bingoText[i][j]));
            k++;
        }
    }
}

int Bingo::checkBingo(){
        int bingoCount = 0;
        bool bingoCheck;

        for(int x = 0; x < 5; x++){ //Horizontal Check
            bingoCheck = true;
            for (int y = 0; y < 5; y++){
                if(!bingo[x][y]){
                    bingoCheck = false;
                    break;
                }
            }
            if(bingoCheck){
                bingoCount++;
            }
        }

        for(int x = 0; x < 5; x++){ //Vertical Check
            bingoCheck = true;
            for (int y = 0; y < 5; y++){
                if(!bingo[y][x]){
                    bingoCheck = false;
                    break;
                }
            }
            if(bingoCheck){
                bingoCount++;
            }
        }

        if (bingo[2][2]){ //Diagonal check
            bingoCheck = true;
            for (int z = 0; z < 5; z++){ // Top left diagonal
                if (!bingo[z][z]){
                    bingoCheck = false;
                    break;
                }
            }
            if (bingoCheck){
                bingoCount++;
            }
            bingoCheck = true;
            for (int z = 0; z < 5; z++){ // Top right diagonal
                if (!bingo[z][5 - 1 - z]){
                    bingoCheck = false;
                    break;
                }
            }
            if (bingoCheck){
                bingoCount++;
            }
        }
        return bingoCheck;
    }

void Bingo::onPushButtonClicked(){
    int indexx = 0; int indexy = 0;

    for(QPushButton* btn : btnArr){
        if(btn == sender()){
            if(!bingo[indexx][indexy]){
                btn->setStyleSheet("background-color: red;");
                bingo[indexx][indexy] = true;
            }
            else{
                btn->setStyleSheet("background-color: none;");
                bingo[indexx][indexy] = false;
            }
        }
        indexy++;
        if(indexy > 4){
            indexy = 0;
            indexx++;
        }
    }
}

void Bingo::on_pushButton11_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton12_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton13_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton14_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton15_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton21_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton22_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton23_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton24_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton25_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton31_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton32_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton33_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton34_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton35_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton41_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton42_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton43_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton44_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton45_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton51_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton52_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton53_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton54_clicked(){onPushButtonClicked();}
void Bingo::on_pushButton55_clicked(){onPushButtonClicked();}

