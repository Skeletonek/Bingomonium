/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QListView *listView;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(581, 321);
        MainWindow->setMinimumSize(QSize(581, 321));
        MainWindow->setMaximumSize(QSize(581, 321));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/logo.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 276, 221, 20));
        QFont font;
        font.setPointSize(9);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 90, 211, 181));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setProperty("isWrapping", QVariant(true));
        listView->setViewMode(QListView::ListMode);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 290, 221, 16));
        QFont font1;
        font1.setPointSize(7);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(230, 10, 341, 301));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 191, 48));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/bingomonium_logo.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bingomonium", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Wersja: 2.0-Alpha-060722", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Copyright \302\251 2021-2022 Skeletonek", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Pre2.0-Alpha-060722</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> - Udost\304\231pnienie pierwszej wersji Bingomonium</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> - Bingomonium to rework aplikacji PandemoniumBingo</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> - Aplikacja z"
                        "osta\305\202a przepisana z \305\233rodowiska WPF (C#) do Qt (C++)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> - Dodano CS:GO Pandemonium Bingo</p></body></html>", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
