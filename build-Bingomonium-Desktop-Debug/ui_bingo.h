/********************************************************************************
** Form generated from reading UI file 'bingo.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINGO_H
#define UI_BINGO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bingo
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *buttonsGrid;
    QPushButton *pushButton34;
    QPushButton *pushButton52;
    QPushButton *pushButton33;
    QPushButton *pushButton51;
    QPushButton *pushButton32;
    QPushButton *pushButton54;
    QPushButton *pushButton31;
    QPushButton *pushButton43;
    QPushButton *pushButton44;
    QPushButton *pushButton42;
    QPushButton *pushButton55;
    QPushButton *pushButton15;
    QPushButton *pushButton13;
    QPushButton *pushButton12;
    QPushButton *pushButton41;
    QPushButton *pushButton45;
    QPushButton *pushButton21;
    QPushButton *pushButton24;
    QPushButton *pushButton14;
    QPushButton *pushButton11;
    QPushButton *pushButton23;
    QPushButton *pushButton35;
    QPushButton *pushButton25;
    QPushButton *pushButton53;
    QPushButton *pushButton22;
    QListView *listView;

    void setupUi(QDialog *Bingo)
    {
        if (Bingo->objectName().isEmpty())
            Bingo->setObjectName(QString::fromUtf8("Bingo"));
        Bingo->resize(800, 600);
        Bingo->setMinimumSize(QSize(800, 600));
        Bingo->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/logo.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        Bingo->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(Bingo);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 561, 581));
        buttonsGrid = new QGridLayout(gridLayoutWidget);
        buttonsGrid->setObjectName(QString::fromUtf8("buttonsGrid"));
        buttonsGrid->setContentsMargins(0, 0, 0, 0);
        pushButton34 = new QPushButton(gridLayoutWidget);
        pushButton34->setObjectName(QString::fromUtf8("pushButton34"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton34->sizePolicy().hasHeightForWidth());
        pushButton34->setSizePolicy(sizePolicy);
        pushButton34->setFlat(false);

        buttonsGrid->addWidget(pushButton34, 2, 3, 1, 1);

        pushButton52 = new QPushButton(gridLayoutWidget);
        pushButton52->setObjectName(QString::fromUtf8("pushButton52"));
        sizePolicy.setHeightForWidth(pushButton52->sizePolicy().hasHeightForWidth());
        pushButton52->setSizePolicy(sizePolicy);
        pushButton52->setFlat(false);

        buttonsGrid->addWidget(pushButton52, 4, 1, 1, 1);

        pushButton33 = new QPushButton(gridLayoutWidget);
        pushButton33->setObjectName(QString::fromUtf8("pushButton33"));
        sizePolicy.setHeightForWidth(pushButton33->sizePolicy().hasHeightForWidth());
        pushButton33->setSizePolicy(sizePolicy);
        pushButton33->setFlat(false);

        buttonsGrid->addWidget(pushButton33, 2, 2, 1, 1);

        pushButton51 = new QPushButton(gridLayoutWidget);
        pushButton51->setObjectName(QString::fromUtf8("pushButton51"));
        sizePolicy.setHeightForWidth(pushButton51->sizePolicy().hasHeightForWidth());
        pushButton51->setSizePolicy(sizePolicy);
        pushButton51->setFlat(false);

        buttonsGrid->addWidget(pushButton51, 4, 0, 1, 1);

        pushButton32 = new QPushButton(gridLayoutWidget);
        pushButton32->setObjectName(QString::fromUtf8("pushButton32"));
        sizePolicy.setHeightForWidth(pushButton32->sizePolicy().hasHeightForWidth());
        pushButton32->setSizePolicy(sizePolicy);
        pushButton32->setFlat(false);

        buttonsGrid->addWidget(pushButton32, 2, 1, 1, 1);

        pushButton54 = new QPushButton(gridLayoutWidget);
        pushButton54->setObjectName(QString::fromUtf8("pushButton54"));
        sizePolicy.setHeightForWidth(pushButton54->sizePolicy().hasHeightForWidth());
        pushButton54->setSizePolicy(sizePolicy);
        pushButton54->setFlat(false);

        buttonsGrid->addWidget(pushButton54, 4, 3, 1, 1);

        pushButton31 = new QPushButton(gridLayoutWidget);
        pushButton31->setObjectName(QString::fromUtf8("pushButton31"));
        sizePolicy.setHeightForWidth(pushButton31->sizePolicy().hasHeightForWidth());
        pushButton31->setSizePolicy(sizePolicy);
        pushButton31->setFlat(false);

        buttonsGrid->addWidget(pushButton31, 2, 0, 1, 1);

        pushButton43 = new QPushButton(gridLayoutWidget);
        pushButton43->setObjectName(QString::fromUtf8("pushButton43"));
        sizePolicy.setHeightForWidth(pushButton43->sizePolicy().hasHeightForWidth());
        pushButton43->setSizePolicy(sizePolicy);
        pushButton43->setFlat(false);

        buttonsGrid->addWidget(pushButton43, 3, 2, 1, 1);

        pushButton44 = new QPushButton(gridLayoutWidget);
        pushButton44->setObjectName(QString::fromUtf8("pushButton44"));
        sizePolicy.setHeightForWidth(pushButton44->sizePolicy().hasHeightForWidth());
        pushButton44->setSizePolicy(sizePolicy);
        pushButton44->setFlat(false);

        buttonsGrid->addWidget(pushButton44, 3, 3, 1, 1);

        pushButton42 = new QPushButton(gridLayoutWidget);
        pushButton42->setObjectName(QString::fromUtf8("pushButton42"));
        sizePolicy.setHeightForWidth(pushButton42->sizePolicy().hasHeightForWidth());
        pushButton42->setSizePolicy(sizePolicy);
        pushButton42->setFlat(false);

        buttonsGrid->addWidget(pushButton42, 3, 1, 1, 1);

        pushButton55 = new QPushButton(gridLayoutWidget);
        pushButton55->setObjectName(QString::fromUtf8("pushButton55"));
        sizePolicy.setHeightForWidth(pushButton55->sizePolicy().hasHeightForWidth());
        pushButton55->setSizePolicy(sizePolicy);
        pushButton55->setFlat(false);

        buttonsGrid->addWidget(pushButton55, 4, 4, 1, 1);

        pushButton15 = new QPushButton(gridLayoutWidget);
        pushButton15->setObjectName(QString::fromUtf8("pushButton15"));
        sizePolicy.setHeightForWidth(pushButton15->sizePolicy().hasHeightForWidth());
        pushButton15->setSizePolicy(sizePolicy);
        pushButton15->setFlat(false);

        buttonsGrid->addWidget(pushButton15, 0, 4, 1, 1);

        pushButton13 = new QPushButton(gridLayoutWidget);
        pushButton13->setObjectName(QString::fromUtf8("pushButton13"));
        sizePolicy.setHeightForWidth(pushButton13->sizePolicy().hasHeightForWidth());
        pushButton13->setSizePolicy(sizePolicy);
        pushButton13->setFlat(false);

        buttonsGrid->addWidget(pushButton13, 0, 2, 1, 1);

        pushButton12 = new QPushButton(gridLayoutWidget);
        pushButton12->setObjectName(QString::fromUtf8("pushButton12"));
        sizePolicy.setHeightForWidth(pushButton12->sizePolicy().hasHeightForWidth());
        pushButton12->setSizePolicy(sizePolicy);
        pushButton12->setFlat(false);

        buttonsGrid->addWidget(pushButton12, 0, 1, 1, 1);

        pushButton41 = new QPushButton(gridLayoutWidget);
        pushButton41->setObjectName(QString::fromUtf8("pushButton41"));
        sizePolicy.setHeightForWidth(pushButton41->sizePolicy().hasHeightForWidth());
        pushButton41->setSizePolicy(sizePolicy);
        pushButton41->setFlat(false);

        buttonsGrid->addWidget(pushButton41, 3, 0, 1, 1);

        pushButton45 = new QPushButton(gridLayoutWidget);
        pushButton45->setObjectName(QString::fromUtf8("pushButton45"));
        sizePolicy.setHeightForWidth(pushButton45->sizePolicy().hasHeightForWidth());
        pushButton45->setSizePolicy(sizePolicy);
        pushButton45->setFlat(false);

        buttonsGrid->addWidget(pushButton45, 3, 4, 1, 1);

        pushButton21 = new QPushButton(gridLayoutWidget);
        pushButton21->setObjectName(QString::fromUtf8("pushButton21"));
        sizePolicy.setHeightForWidth(pushButton21->sizePolicy().hasHeightForWidth());
        pushButton21->setSizePolicy(sizePolicy);
        pushButton21->setFlat(false);

        buttonsGrid->addWidget(pushButton21, 1, 0, 1, 1);

        pushButton24 = new QPushButton(gridLayoutWidget);
        pushButton24->setObjectName(QString::fromUtf8("pushButton24"));
        sizePolicy.setHeightForWidth(pushButton24->sizePolicy().hasHeightForWidth());
        pushButton24->setSizePolicy(sizePolicy);
        pushButton24->setFlat(false);

        buttonsGrid->addWidget(pushButton24, 1, 3, 1, 1);

        pushButton14 = new QPushButton(gridLayoutWidget);
        pushButton14->setObjectName(QString::fromUtf8("pushButton14"));
        sizePolicy.setHeightForWidth(pushButton14->sizePolicy().hasHeightForWidth());
        pushButton14->setSizePolicy(sizePolicy);
        pushButton14->setFlat(false);

        buttonsGrid->addWidget(pushButton14, 0, 3, 1, 1);

        pushButton11 = new QPushButton(gridLayoutWidget);
        pushButton11->setObjectName(QString::fromUtf8("pushButton11"));
        sizePolicy.setHeightForWidth(pushButton11->sizePolicy().hasHeightForWidth());
        pushButton11->setSizePolicy(sizePolicy);
        pushButton11->setFlat(false);

        buttonsGrid->addWidget(pushButton11, 0, 0, 1, 1);

        pushButton23 = new QPushButton(gridLayoutWidget);
        pushButton23->setObjectName(QString::fromUtf8("pushButton23"));
        sizePolicy.setHeightForWidth(pushButton23->sizePolicy().hasHeightForWidth());
        pushButton23->setSizePolicy(sizePolicy);
        pushButton23->setFlat(false);

        buttonsGrid->addWidget(pushButton23, 1, 2, 1, 1);

        pushButton35 = new QPushButton(gridLayoutWidget);
        pushButton35->setObjectName(QString::fromUtf8("pushButton35"));
        sizePolicy.setHeightForWidth(pushButton35->sizePolicy().hasHeightForWidth());
        pushButton35->setSizePolicy(sizePolicy);
        pushButton35->setFlat(false);

        buttonsGrid->addWidget(pushButton35, 2, 4, 1, 1);

        pushButton25 = new QPushButton(gridLayoutWidget);
        pushButton25->setObjectName(QString::fromUtf8("pushButton25"));
        sizePolicy.setHeightForWidth(pushButton25->sizePolicy().hasHeightForWidth());
        pushButton25->setSizePolicy(sizePolicy);
        pushButton25->setFlat(false);

        buttonsGrid->addWidget(pushButton25, 1, 4, 1, 1);

        pushButton53 = new QPushButton(gridLayoutWidget);
        pushButton53->setObjectName(QString::fromUtf8("pushButton53"));
        sizePolicy.setHeightForWidth(pushButton53->sizePolicy().hasHeightForWidth());
        pushButton53->setSizePolicy(sizePolicy);
        pushButton53->setFlat(false);

        buttonsGrid->addWidget(pushButton53, 4, 2, 1, 1);

        pushButton22 = new QPushButton(gridLayoutWidget);
        pushButton22->setObjectName(QString::fromUtf8("pushButton22"));
        sizePolicy.setHeightForWidth(pushButton22->sizePolicy().hasHeightForWidth());
        pushButton22->setSizePolicy(sizePolicy);
        pushButton22->setFlat(false);

        buttonsGrid->addWidget(pushButton22, 1, 1, 1, 1);

        listView = new QListView(Bingo);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(580, 350, 211, 241));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);

        retranslateUi(Bingo);

        QMetaObject::connectSlotsByName(Bingo);
    } // setupUi

    void retranslateUi(QDialog *Bingo)
    {
        Bingo->setWindowTitle(QCoreApplication::translate("Bingo", "Bingomonium", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bingo: public Ui_Bingo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINGO_H
