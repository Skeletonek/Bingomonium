#include "bingofileeditor.h"
#include "ui_bingofileeditor.h"

BingoFileEditor::BingoFileEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BingoFileEditor)
{
    ui->setupUi(this);
}

BingoFileEditor::~BingoFileEditor()
{
    delete ui;
}
