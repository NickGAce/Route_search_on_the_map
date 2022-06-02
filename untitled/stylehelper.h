#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include <QString>

class StyleHelper
{
public:
   static QString getMainWidgetStyle();
   static QString getStartButtonsStyle();

   static QString getLocalLeftButtonsStyle();
   static QString getLocalLeftActiveButtonsStyle();

   static QString getLocalRightButtonsStyle();
   static QString getLocalRightActiveButtonsStyle();

   static QString getTabWidgetStyle();
   static QString getTabStyle();


   static QString getStartActiveButtonsStyle();
   static QString getFinishActiveButtonsStyle();

   static QString getBlankStyle();
   static QString getStartStyle();
   static QString getFinishStyle();
   static QString getMountainsStyle();
   static QString getForestStyle();
   static QString getWatertStyle();
   static QString getFieldtStyle();

   static QString getBlankActiveStyle();
   static QString getBlankErorStyle();
   static QString getMountainsActiveStyle();
   static QString getForestActiveStyle();
   static QString getWatertActiveStyle();
   static QString getFieldtActiveStyle();

   static QString getAboutTextStyle();

};

#endif // STYLEHELPER_H
