#include "stylehelper.h"


QString StyleHelper::getMainWidgetStyle()
{
   return "QWidget{"
           "background-image:url(:/resours/images/9bedd654e2f6100d1c635176b829f36d.jpeg);"
          "}";
}

QString StyleHelper::getStartButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "border:none;"
           "border-radius:5px;"
           "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 129));"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
           "}"
    "QPushButton::hover{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(81, 81, 81, 255), stop:1 rgba(0, 0, 0, 129));"
    "}"
    "QPushButton::pressed{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(80, 255, 216, 255));"
           "}";
}

QString StyleHelper::getLocalLeftButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
           "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 129));"
           "border:1px solid #333;"
           "border-top-left-radius:5px;"
           "border-bottom-left-radius:5px;"
           "}";
}

QString StyleHelper::getLocalLeftActiveButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
           "background-color: rgb(43, 42, 42);"
           "border:1px solid #333;"
           "border-top-left-radius:5px;"
           "border-bottom-left-radius:5px;"
           "}";
}

QString StyleHelper::getLocalRightButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
           "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 129));"
           "border:1px solid #333;"
           "border-left:none;"
           "border-top-right-radius:5px;"
           "border-bottom-right-radius:5px;"
           "}";
}

QString StyleHelper::getLocalRightActiveButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
            "background-color: rgb(43, 42, 42);"
           "border:1px solid #333;"
           "border-left:none;"
           "border-top-right-radius:5px;"
           "border-bottom-right-radius:5px;"
           "}";
}

QString StyleHelper::getTabWidgetStyle()
{
     return"QTabWidget{"
           "border:none;"
           "}"
           "QTabWidget::pane{"
            "border:3px solid #222;"
            "border-radius:6px;"
           "}";
}

QString StyleHelper::getTabStyle()
{
    return "QWidget#Map{"
    "background-color: rgb(47, 47, 47);"
           "}";
}

QString StyleHelper::getStartActiveButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
           "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));"
           "border:1px solid #333;"
           "border-top-left-radius:5px;"
           "border-bottom-left-radius:5px;"
           "}";
}

QString StyleHelper::getFinishActiveButtonsStyle()
{
    return "QPushButton{"
           " color:#fff;"
           "background:none;"
           "font-family:'Roboto Medium';"
           "font-size:16px;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
           "border:1px solid #333;"
           "border-left:none;"
           "border-top-right-radius:5px;"
           "border-bottom-right-radius:5px;"
           "}";
}

QString StyleHelper::getBlankStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(65, 65, 65);"
           "}"
           "QPushButton::hover{"
           "background: rgb(75, 75, 75);"
           "}";
}

QString StyleHelper::getStartStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(0, 255, 0) url(:/resours/images/walk.png);"
           "}";
}

QString StyleHelper::getFinishStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(255, 0, 0) url(:/resours/images/black-flag.png);"
           "}";
}

QString StyleHelper::getMountainsStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(65, 65, 65) url(:/resours/images/peaks.png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(75, 75, 75);"
           "}";
}

QString StyleHelper::getForestStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(65, 65, 65) url(:/resours/images/forest(1).png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(75, 75, 75);"
           "}";
}

QString StyleHelper::getWatertStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(65, 65, 65) url(:/resours/images/swamp.png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(75, 75, 75);"
           "}";
}

QString StyleHelper::getFieldtStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(65, 65, 65) url(:/resours/images/grass.png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(75, 75, 75);"
           "}";
}

QString StyleHelper::getBlankActiveStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(0,245,0);"
           "}"
           "QPushButton::hover{"
           "background: rgb(0,255,0);"
           "}";
}

QString StyleHelper::getBlankErorStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(235, 0, 0);"
           "}"
           "QPushButton::hover{"
           "background: rgb(255, 0, 0);"
           "}";
}

QString StyleHelper::getMountainsActiveStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(0,245,0) url(:/resours/images/peaks.png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(0,255,0);"
           "}";
}

QString StyleHelper::getForestActiveStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(0,245,0) url(:/resours/images/forest(1).png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(0,255,0);"
           "}";
}

QString StyleHelper::getWatertActiveStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(0,245,0) url(:/resours/images/swamp.png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(0,255,0);"
           "}";
}

QString StyleHelper::getFieldtActiveStyle()
{
    return "QPushButton{"
           "border-radius:5px;"
           "border:1px solid #333;"
           "background: rgb(0,245,0) url(:/resours/images/grass.png);"
           "}"
           "QPushButton::hover{"
           "background-color: rgb(0,255,0);"
           "}";
}

QString StyleHelper::getAboutTextStyle()
{
    return "Qlabel{"
           "background:none;"
           "}";
}
