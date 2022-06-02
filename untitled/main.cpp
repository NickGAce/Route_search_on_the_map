#include "mainwindow.h"
#include "astar.h"
#include <QApplication>
#include <QtCore>
#include <QtXml>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
