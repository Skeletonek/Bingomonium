#ifndef BINGOFILEEDITOR_H
#define BINGOFILEEDITOR_H

#include <QDialog>

namespace Ui {
class BingoFileEditor;
}

class BingoFileEditor : public QDialog
{
    Q_OBJECT

public:
    explicit BingoFileEditor(QWidget *parent = nullptr);
    ~BingoFileEditor();

private:
    Ui::BingoFileEditor *ui;
};

#endif // BINGOFILEEDITOR_H
