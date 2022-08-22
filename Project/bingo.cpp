#include "bingo.h"
#include "ui_bingo.h"
#include "bingofileparser.h"

BingoFileParser bingoFileParse;

Bingo::Bingo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bingo) {
    ui->setupUi(this);
}

Bingo::~Bingo() { delete ui; }

void Bingo::onCreate() {
    bingoFileParse.readFile(bingoFilePath);
    bingoValues = bingoFileParse.getValuesData();
    bingoCategories = bingoFileParse.getCategoriesData();
    player = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    constructButtons();
    fillInCategoriesList();
    createBingo();

    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.25);
    player->setSource(QUrl("qrc:/media/Ding.wav"));

    if(bingoFilePath == "bingos/BiniumMongo.bgo"){
        setWindowIcon(QIcon(":/img/BiniumMongo.xpm"));
    }
}

void Bingo::setBingoFilePath(string bingoFilePath_) { bingoFilePath = bingoFilePath_; }

void Bingo::createBingo() {
    int random;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            bingo[i][j] = false;
            bingoText[i][j] = "";
            if(bingoValues.size() != 0){
                do {
                    random = rand()%(bingoValues.size());
                        if(bingoCategories.at(random) == "" ||
                                bingoCat.at(model->stringList().indexOf
                                (QString::fromStdString(
                                     bingoCategories.at(random)))) == true) {
                            string tile_tmp = bingoValues.at(random);
                            bingoValues.erase(bingoValues.begin()+random);
                            bingoCategories.erase(bingoCategories.begin()+random);
                            bingoText[i][j] = tile_tmp;
                        }
                } while(bingoText[i][j] == "");
            }
        }
    }

    fillInButtons();
    bingoCreatedOnce = true;
}

void Bingo::fillInButtons() {
    int k = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(!bingoCreatedOnce) {
                createQLabel(QString::fromStdString(bingoText[i][j]), k);
            } else {
                setTextQLabel(QString::fromStdString(bingoText[i][j]), k);
            }
            k++;
        }
    }
}

void Bingo::createQLabel(QString str, int btnIndex) {

    //Default PushButton labels don't support text wrapping
    //We need to embed QLabels to QPushButtons for text wrap support

    QLabel *label = new QLabel("<html><body>" + str + "</body></html>", btnArr[btnIndex]);
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignHCenter);
    label->setGeometry(0, 0, 105, 120); //TODO: Find out how to get buttons size
    label->setMargin(8);
    label->setStyleSheet("background-color: none;");
    label->setTextInteractionFlags(Qt::NoTextInteraction);
}

void Bingo::setTextQLabel(QString str, int btnIndex) {
    QLabel *label = btnArr[btnIndex]->findChild<QLabel*>();
    str = "<html><body>" + str + "</body></html>";
    label->setText(str);
}

void Bingo::fillInCategoriesList() {
    QStringList catList;
    model = new QStringListModel(this);
    for(string cat : bingoCategories) {
        if(!catList.contains(QString::fromStdString(cat)) && cat != "") {
            catList.push_back(QString::fromStdString(cat));
            bingoCat.push_back(false);
        }
    }
    model->setStringList(catList);
    ui->listView_categories->setModel(model);
}

void Bingo::destroyQLabels() {
    for(QPushButton *btn : btnArr) {
        for(QObject *obj : btn->children()) {
            obj->deleteLater();
        }
    }
}

int Bingo::checkBingo() {
    int bingoCount = 0;
    bool bingoCheck;

    for(int x = 0; x < 5; x++) { //Horizontal Check
        bingoCheck = true;
        for (int y = 0; y < 5; y++) {
            if(!bingo[x][y]) {
                bingoCheck = false;
                break;
            }
        }
        if(bingoCheck) {
            bingoCount++;
        }
    }

    for(int x = 0; x < 5; x++) { //Vertical Check
        bingoCheck = true;
        for (int y = 0; y < 5; y++) {
            if(!bingo[y][x]) {
                bingoCheck = false;
                break;
            }
        }
        if(bingoCheck) {
            bingoCount++;
        }
    }

    if (bingo[2][2]) { //Diagonal check
        bingoCheck = true;
        for (int z = 0; z < 5; z++) { // Top left diagonal
            if (!bingo[z][z]) {
                bingoCheck = false;
                break;
            }
        }
        if (bingoCheck) {
            bingoCount++;
        }
        bingoCheck = true;
        for (int z = 0; z < 5; z++) { // Top right diagonal
            if (!bingo[z][5 - 1 - z]) {
                bingoCheck = false;
                break;
            }
        }
        if (bingoCheck) {
            bingoCount++;
        }
    }
    return bingoCount;
}

void Bingo::updateButton(int indexx, int indexy) {
    int btnNmbr = 0;
    for(int x = 0; x < indexx; x++) {
        btnNmbr += 5;
    }
    for(int y = 0; y < indexy; y++) {
        btnNmbr ++;
    }

    if(!bingo[indexx][indexy]) {
        btnArr[btnNmbr]->setStyleSheet("background-color: red;");
    } else {
        if(QSysInfo::productType().toStdString() != "windows") {
            btnArr[btnNmbr]->setStyleSheet("background-color: none;");
        } else {
            btnArr[btnNmbr]->setStyleSheet("background-color: rgb(32, 32, 32);");
        }
    }

    bingo[indexx][indexy] = !bingo[indexx][indexy];
}

void Bingo::setBingoCountText(int bingoCount_) {
    ostringstream oss;
    oss << "Bingo: " << bingoCount_;
    if(bingoCount_ > 0) {
        ui->label_bingo->setText(QString::fromStdString(oss.str()));
    } else {
        ui->label_bingo->setText("");
    }
}

void Bingo::playAudio(int bingoCount_) {
    if(bingoCount < bingoCount_) {
        if(player->playbackState() == QMediaPlayer::PlayingState)
            player->stop();
        player->play();
    }
}

void Bingo::onPushButtonClicked() {
    int indexx = 0; int indexy = 0;

    for(QPushButton* btn : btnArr) {
        if(btn == sender()) {
            updateButton(indexx, indexy);
        }
        indexy++;
        if(indexy > 4) {
            indexy = 0;
            indexx++;
        }
    }

    int _bingoCount = checkBingo();
    setBingoCountText(_bingoCount);
    playAudio(_bingoCount);
    bingoCount = _bingoCount;
}

void Bingo::on_pushButton_regenBingo_clicked()
{
    QModelIndexList list = ui->listView_categories->selectionModel()->selectedIndexes();
    for(int i = 0; i < (int)bingoCat.size(); i++){
        foreach(const QModelIndex &index, list){
            if(index.row() == i){
                bingoCat.at(i) = true;
                break;
            } else {
                bingoCat.at(i) = false;
            }
        }
    }

    bingoValues = bingoFileParse.getValuesData();
    bingoCategories = bingoFileParse.getCategoriesData();
    createBingo();

    int indexx = 0; int indexy = 0;
    for(int i = 0; i < 25; i++) {
        bingo[indexx][indexy] = true;
        updateButton(indexx, indexy);
        indexy++;
        if(indexy > 4) {
            indexy = 0;
            indexx++;
        }
    }
    int bingoCount_ = checkBingo();
    setBingoCountText(bingoCount_);
}

void Bingo::constructButtons() {
    buttons = ui->grid_button->children();
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

void Bingo::on_pushButton11_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton12_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton13_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton14_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton15_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton21_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton22_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton23_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton24_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton25_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton31_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton32_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton33_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton34_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton35_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton41_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton42_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton43_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton44_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton45_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton51_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton52_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton53_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton54_clicked() { onPushButtonClicked(); }
void Bingo::on_pushButton55_clicked() { onPushButtonClicked(); }
