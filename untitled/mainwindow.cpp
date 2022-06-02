#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTabBar>
#include"stylehelper.h"
#include<QStyleOption>
#include<QFontDatabase>
#include<QGridLayout>
#include "astar.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configurationTabWidget();
    setInterfaceStyle();
    addFonts();

    ui->label->setStyleSheet("QLabel{background:none;}");
    ui->label_2->setStyleSheet("QLabel{background:none;color: rgb(255, 255, 255);}");
    ui->label_3->setStyleSheet("QLabel{background:none;color: rgb(255, 255, 255);}");
    ui->tabWidget->setStyleSheet(StyleHelper::getTabWidgetStyle());
    ui->Map->setStyleSheet(StyleHelper::getTabStyle());
    configurationGameAreaButtons();
    startGame();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());
    ui->pushButton_208->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_209->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_107->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_105->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_106->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->pushButton_108->setStyleSheet(StyleHelper::getStartButtonsStyle());

    ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
    ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
    ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
    ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());

    ui->pushButton_start->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
    ui->pushButton_finish->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());

    ui->clear->setStyleSheet(StyleHelper::getStartButtonsStyle());

    setGameAreaButtonStyle();


}

void MainWindow::changButtenStatus(int num)
{
    switch ( num ) {
    case 1:
      ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftActiveButtonsStyle());
      ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());

      ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());

      ui->pushButton_start->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
      ui->pushButton_finish->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      break;
    case 2:
       ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightActiveButtonsStyle());
       ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
       ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());

       ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());

       ui->pushButton_start->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
       ui->pushButton_finish->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      break;
    case 3:
        ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftActiveButtonsStyle());
        ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
        ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
        ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());

        ui->pushButton_start->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
        ui->pushButton_finish->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      break;
    case 4:
      ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightActiveButtonsStyle());
      ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
      ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());

      ui->pushButton_start->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
      ui->pushButton_finish->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      break;

    case 5:


      ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
      ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
      ui->pushButton_start->setStyleSheet(StyleHelper::getStartActiveButtonsStyle());
      ui->pushButton_finish->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
      break;
    case 6:

        ui->pushButton_104->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
        ui->pushButton_103->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
        ui->pushButton_102->setStyleSheet(StyleHelper::getLocalRightButtonsStyle());
        ui->pushButton_101->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
        ui->pushButton_start->setStyleSheet(StyleHelper::getLocalLeftButtonsStyle());
        ui->pushButton_finish->setStyleSheet(StyleHelper::getFinishActiveButtonsStyle());
      break;
    default:

      break;
    }
}

void MainWindow::configurationTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::addFonts()
{
    QFontDatabase::addApplicationFont(":/resours/fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont(":/resours/fonts/Roboto-MediumItalic.ttf");
}

void MainWindow::configurationGameAreaButtons()
{
 QGridLayout *grid = qobject_cast <QGridLayout*>(ui->Map->layout());
 for(int row=0;row<10;row++){
     for(int colum=0;colum<10;colum++){
         QPushButton *btn = qobject_cast <QPushButton*>(grid->itemAtPosition(row,colum)->widget());
         btn->setProperty("row",row);
         btn->setProperty("colum",colum);
         connect(btn,&QPushButton::clicked,this,&MainWindow::onGameAreaButtonClicked);
     }
 }
}

void MainWindow::changeButtonStyle(int row, int colum, QString style)
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->Map->layout());
    QPushButton *btn = qobject_cast <QPushButton*>(grid->itemAtPosition(row,colum)->widget());
    btn->setStyleSheet(style);
}

void MainWindow::setGameAreaButtonStyle()
{
      QString style =StyleHelper::getBlankStyle();
      for(int row=0;row<10;row++){
          for(int colum=0;colum<10;colum++){
              changeButtonStyle(row,colum,style);
          }
      }
}

void MainWindow::startGame()
{
    ui->label_2->setText("Путь пока не найден... \n");
    for(int row=0;row<10;row++){
        for(int colum=0;colum<10;colum++){
            gameArea[row][colum]=1;
        }
    }
    GameStart=true;

}

void MainWindow::ListElements(int Line,QDomElement root, QString tagname, QString attribute)
{
    QDomNodeList items =root.elementsByTagName(tagname);
    for(int i=0;i<items.count();i++){
        QDomNode itemnode=items.at(i);
        if(itemnode.isElement()){

            QDomElement itemele =itemnode.toElement();
            gameArea[Line][i]=itemele.attribute(attribute).toInt();
        }
    }
}

void MainWindow::on_pushButton_101_clicked()
{
    changButtenStatus(1);
    player=1;
}

void MainWindow::on_pushButton_102_clicked()
{
    changButtenStatus(2);
    player=2;
}

void MainWindow::on_pushButton_103_clicked()
{
    changButtenStatus(3);
    player=3;
}

void MainWindow::on_pushButton_104_clicked()
{
    changButtenStatus(4);
    player=4;
}

void MainWindow::on_pushButton_start_clicked()
{
    changButtenStatus(5);
    player=5;
}

void MainWindow::on_pushButton_finish_clicked()
{
    changButtenStatus(6);
    player=6;
}

void MainWindow::onGameAreaButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    int row = btn->property("row").toInt();
    int colum = btn->property("colum").toInt();
    QString style;

    switch ( player ) {
    case 1:
      style = StyleHelper::getMountainsStyle();
      changeButtonStyle(row,colum,style);
      gameArea[row][colum]=5;
      break;
    case 2:
        style = StyleHelper::getWatertStyle();
        changeButtonStyle(row,colum,style);
        gameArea[row][colum]=4;
      break;
    case 3:
        style = StyleHelper::getFieldtStyle();
        changeButtonStyle(row,colum,style);
        gameArea[row][colum]=2;
      break;
    case 4:
        style = StyleHelper::getForestStyle();
        changeButtonStyle(row,colum,style);
        gameArea[row][colum]=3;
      break;

    case 5:
        if(!StartChek){
        style = StyleHelper::getStartStyle();
        changeButtonStyle(row,colum,style);
        gameArea[row][colum]=1;
        Cordinate.X_Start=colum;
        Cordinate.Y_Start=row;
        StartChek=true;
        LastRowS=row;
        LastColumS=colum;

        }else
        {
           style = StyleHelper::getStartStyle();
           changeButtonStyle(row,colum,style);
           gameArea[row][colum]=1;
           Cordinate.X_Start=colum;
           Cordinate.Y_Start=row;
           style = StyleHelper::getBlankStyle();
           changeButtonStyle(LastRowS,LastColumS,style);
           gameArea[row][colum]=1;
           LastRowS=row;
           LastColumS=colum;
        }

      break;
    case 6:
        if(!FinishChek){
        style = StyleHelper::getFinishStyle();
        changeButtonStyle(row,colum,style);
        gameArea[row][colum]=1;
        Cordinate.X_Finich=colum;
        Cordinate.Y_Finich=row;
        FinishChek=true;
        LastRowF=row;
        LastColumF=colum;
        }else
        {
           style = StyleHelper::getFinishStyle();
           changeButtonStyle(row,colum,style);
           gameArea[row][colum]=1;
           Cordinate.X_Finich=colum;
           Cordinate.Y_Finich=row;
           style = StyleHelper::getBlankStyle();
           changeButtonStyle(LastRowF,LastColumF,style);
           gameArea[row][colum]=1;
           LastRowF=row;
           LastColumF=colum;
        }
      break;
    default:

      break;
    }
}

void MainWindow::on_clear_clicked()
{
  setGameAreaButtonStyle();
  startGame();
  FinishChek=false;
  StartChek=false;
  ui->label_2->setText("Путь пока не найден... \n");
}

void MainWindow::on_pushButton_107_clicked()
{
    QDomDocument document;
    QDomElement root = document.createElement("Cells");
        document.appendChild(root);

        for(int i=0;i<10;i++){
            QDomElement Line=document.createElement("Line");
            Line.setAttribute("Number",QString::number(i));
            root.appendChild(Line);

            for(int h=0;h<10;h++){
            QDomElement Cell=document.createElement("Cell");
            Cell.setAttribute("Condition",QString::number(gameArea[i][h]));
            Cell.setAttribute("ID",QString::number(h));
            Line.appendChild(Cell);
            }
        }
        if(FinishChek==true && StartChek==true){
        QDomElement LineStart=document.createElement("LineStart");
        LineStart.setAttribute("Number",QString::number(Cordinate.Y_Start));
        root.appendChild(LineStart);
        QDomElement CellStart=document.createElement("CellStart");


        CellStart.setAttribute("ID",QString::number(Cordinate.X_Start));
        LineStart.appendChild(CellStart);

        QDomElement LineFinich=document.createElement("LineFinich");
        LineFinich.setAttribute("Number",QString::number(Cordinate.Y_Finich));
        root.appendChild(LineFinich);

        QDomElement CellFinich=document.createElement("CellFinich");
        CellFinich.setAttribute("ID",QString::number(Cordinate.X_Finich));
        LineFinich.appendChild(CellFinich);
        }

        QFile file("../MyXMLArea.xml");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug()<<"Fail";

        }
        else
        {
            QTextStream stream(&file);
            stream<< document.toString();
            file.close();
            qDebug()<<"NAIC";
        }

}

void MainWindow::on_pushButton_209_clicked()
{

if(FinishChek==true && StartChek==true){

    Astar ast(Cordinate);

    ast.res.resize(10);
    for(int row=0;row<10;row++){
        ast.res[row].resize(10);
        for(int colum=0;colum<10;colum++){
            ast.res[row][colum]=gameArea[row][colum];
        }
    }

    ast.Map_Input();

    ast.getOpenList();

    if(ast.Get_path_find()==false){
        ui->tabWidget->setCurrentIndex(2);
    }else{

    ui->label_2->setText("Путь такой: \n");
    ast.GetPath();

    ast.Get_Result();



    QString style;
    for(int row=0;row<10;row++){
        for(int colum=0;colum<10;colum++){
            switch ( ast.res[row][colum] ) {
            case 5:
              style = StyleHelper::getMountainsActiveStyle();
              changeButtonStyle(row,colum,style);
              gameArea[row][colum]=5;

              break;
            case 4:
                style = StyleHelper::getWatertActiveStyle();
                changeButtonStyle(row,colum,style);
                gameArea[row][colum]=4;
                ui->label_2->setText(ui->label_2->text() +QString("Клетка с номером ")+ QString::number(row)+QString(" ")+QString::number(colum)+QString(" и проходимостью: ")+QString::number(gameArea[row][colum])+QString("\n"));
              break;
            case 2:
                style = StyleHelper::getFieldtActiveStyle();
                changeButtonStyle(row,colum,style);
                gameArea[row][colum]=2;
                ui->label_2->setText(ui->label_2->text() +QString("Клетка с номером ")+ QString::number(row)+QString(" ")+QString::number(colum)+QString(" и проходимостью: ")+QString::number(gameArea[row][colum])+QString("\n"));
              break;
            case 3:
                style = StyleHelper::getForestActiveStyle();
                changeButtonStyle(row,colum,style);
                gameArea[row][colum]=3;
               ui->label_2->setText(ui->label_2->text() +QString("Клетка с номером ")+ QString::number(row)+QString(" ")+QString::number(colum)+QString(" и проходимостью: ")+QString::number(gameArea[row][colum])+QString("\n"));
              break;
            case 1:

                style = StyleHelper::getBlankActiveStyle();
                changeButtonStyle(row,colum,style);
                gameArea[row][colum]=1;
                ui->label_2->setText(ui->label_2->text() +QString("Клетка с номером ")+ QString::number(row)+QString(" ")+QString::number(colum)+QString(" и проходимостью: ")+QString::number(gameArea[row][colum])+QString("\n"));
              break;
            default:

              break;        
            }

        }
    }
 ui->label_2->setText(ui->label_2->text() +QString("Клетка старта: ")+QString::number(Cordinate.Y_Start)+QString(" ")+QString::number(Cordinate.X_Start));
 ui->label_2->setText(ui->label_2->text() +QString("\nКлетка финиша: ")+QString::number(Cordinate.Y_Finich)+QString(" ")+QString::number(Cordinate.X_Finich));
 ui->label_2->setText(ui->label_2->text()+QString("\nДлина пути: ")+QString::number(ast.Get_path_size()));
 ui->label_2->setText(ui->label_2->text()+QString("\nВремя пути: ")+QString::number(ast.Get_path_time()));
 }
    QDomDocument document;
    QDomElement root = document.createElement("Cells");
        document.appendChild(root);

        for(int i=0;i<10;i++){
            QDomElement Line=document.createElement("Line");
            Line.setAttribute("Number",QString::number(i));
            root.appendChild(Line);

            for(int h=0;h<10;h++){
            QDomElement Cell=document.createElement("Cell");
            Cell.setAttribute("ID",QString::number(h));
            Cell.setAttribute("Condition",QString::number(ast.res[i][h]));
            Line.appendChild(Cell);
            }
        }
        if(FinishChek==true && StartChek==true){
        QDomElement LineStart=document.createElement("LineStart");
        LineStart.setAttribute("Number",QString::number(Cordinate.Y_Start));
        root.appendChild(LineStart);

        QDomElement CellStart=document.createElement("CellStart");
        CellStart.setAttribute("ID",QString::number(Cordinate.X_Start));
        LineStart.appendChild(CellStart);

        QDomElement LineFinich=document.createElement("LineFinich");
        LineFinich.setAttribute("Number",QString::number(Cordinate.Y_Finich));
        root.appendChild(LineFinich);

        QDomElement CellFinich=document.createElement("CellFinich");
        CellFinich.setAttribute("ID",QString::number(Cordinate.X_Finich));
        LineFinich.appendChild(CellFinich);

        QDomElement PathSize=document.createElement("PathSize");
        PathSize.setAttribute("Size",QString::number(ast.Get_path_size()));
        root.appendChild(PathSize);

        QDomElement PathTime=document.createElement("PathTime");
        PathTime.setAttribute("TiMe",QString::number(ast.Get_path_time()));
        root.appendChild(PathTime);
        }

        QFile file("../MyXMLAreaPath.xml");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug()<<"Fail";

        }
        else
        {
            QTextStream stream(&file);
            stream<< document.toString();
            file.close();
           // qDebug()<<"NAIC";
        }
}else{ui->tabWidget->setCurrentIndex(2);}
}

void MainWindow::on_pushButton_105_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_208_clicked()
{
     ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_106_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_108_clicked()
{
     str_in = ui->lineEdit->text();
     QDomDocument document;
     QFile file(str_in);
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
         qDebug()<<"Fail";

     }
     else{
         if(!document.setContent(&file)){
              qDebug()<<"Fail load";
         }
         file.close();
     }
     QDomElement root=document.firstChildElement();
     //ListElements(root,"Line","Number");

     QDomNodeList cells =root.elementsByTagName("Line");
     for(int i=0;i<cells.count();i++){
         QDomNode cellnode= cells.at(i);
         if(cellnode.isElement()){
             QDomElement cell = cellnode.toElement();
             ListElements(i,cell,"Cell","Condition");
         }
     }
     QString style;

     for(int row=0;row<10;row++){
         for(int colum=0;colum<10;colum++){

             switch ( gameArea[row][colum] ) {
             case 5:
               style = StyleHelper::getMountainsStyle();
               changeButtonStyle(row,colum,style);

               break;
             case 4:
                 style = StyleHelper::getWatertStyle();
                 changeButtonStyle(row,colum,style);

               break;
             case 2:
                 style = StyleHelper::getFieldtStyle();
                 changeButtonStyle(row,colum,style);

               break;
             case 3:
                 style = StyleHelper::getForestStyle();
                 changeButtonStyle(row,colum,style);

               break;

             default:

               break;
             }
         }
     }
}
