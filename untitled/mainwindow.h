#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtXml>
#include <QDebug>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct StartFinish
{
int X_Start=0;
int Y_Start=0;
int X_Finich=0;
int Y_Finich=0;
 };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    StartFinish Cordinate;

private slots:
    void on_pushButton_101_clicked();
    void on_pushButton_102_clicked();
    void on_pushButton_103_clicked();
    void on_pushButton_104_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_finish_clicked();

    void onGameAreaButtonClicked();

    void on_clear_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_209_clicked();


    void on_pushButton_105_clicked();

    void on_pushButton_208_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_108_clicked();

private:
    Ui::MainWindow *ui;
    void setInterfaceStyle();
    void changButtenStatus(int num);

    void configurationTabWidget();
    void addFonts();

    void configurationGameAreaButtons();
    void changeButtonStyle(int row,int colum, QString style);
    void setGameAreaButtonStyle();
    void startGame();
    int gameArea[10][10];
    int player=0;

    bool GameStart=false;
    bool StartChek=false;
    bool FinishChek=false;
    int LastRowF;
    int LastColumF;
    int LastRowS;
    int LastColumS;

    QString str_in;
    void ListElements(int Line,QDomElement root, QString tagname,QString attribute);


};
#endif // MAINWINDOW_H
