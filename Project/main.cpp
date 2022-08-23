#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSysInfo>
#include <QKeyEvent>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    if(QSysInfo::productType().toStdString() == "windows") {
        QApplication::setStyle(QStyleFactory::create("fusion"));
    }
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
        const QString baseName = "Bingomonium_" + QLocale(locale).name() + ".qm";
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
