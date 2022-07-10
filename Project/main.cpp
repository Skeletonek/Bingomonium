#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(QSysInfo::productType().toStdString() == "windows") {
        a.setStyleSheet("QDialog { background-color: rgb(32, 32, 32); color: rgb(230, 230, 230); }"
                        "QMainWindow { background-color: rgb(32, 32, 32); color: rgb(230, 230, 230); }"
                        "QTextBrowser { background-color: rgb(32, 32, 32); color: rgb(230, 230, 230); }"
                        "QListView { background-color: rgb(32, 32, 32); color: rgb(230, 230, 230); }"
                        "QPushButton { background-color: rgb(32, 32, 32); color: rgb(230, 230, 230); }"
                        "QLabel { color: rgb(230, 230, 230); }");
    }

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Bingomonium" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
