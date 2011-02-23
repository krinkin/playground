// File : window.h
// Autor : Alimuradova Yana Vidadievna (6352)
// Date: 04.07.2009
// Red.: 1.0

 #ifndef WINDOW_H
 #define WINDOW_H

 #include <QWidget>

//
 #include <QList>
 #include <QMainWindow>
 #include <QPair>
 #include "WindowDialog.h"
 class QAction;
 class QTabWidget;
 class WindowDialog; 
//

 class QCalendarWidget;
 class QComboBox;
 class QDate;
 class QDateEdit;
 class QGridLayout;
 class QGroupBox;
 class QLabel;
 class QPushButton;

 class Window : public QWidget
 {
     Q_OBJECT
     
 public:
     Window();
     void createSample(); 

 private slots:
     
     void openDialog();
     void printFile();
     
     void localeChanged(int index);
     void firstDayChanged(int index);
     void selectionModeChanged(int index);
     void selectedDateChanged();
     
 private:
     
     void createPreviewGroupBox();
     void createTextGroupBox();
     void createGeneralOptionsGroupBox();
     void createDateGroupBox();
     
     QGroupBox *previewGroupBox;
     QGridLayout *previewLayout;
     QCalendarWidget *calendar;

     QGroupBox *textGroupBox;
     QGridLayout *textLayout;
     QPushButton *closeButton; 
     

     QGroupBox *generalOptionsGroupBox;
     QLabel *localeLabel;
     QLabel *firstDayLabel;
     QLabel *selectionModeLabel;
     QComboBox *localeCombo;
     QComboBox *firstDayCombo;
     QComboBox *selectionModeCombo;
     QGroupBox *dateGroupBox;
     QLabel *currentDateLabel;
     QDateEdit *currentDateEdit;
     QGroupBox *textFormatsGroupBox;
     QLabel *headerTextFormatLabel;
     QComboBox *headerTextFormatCombo;

     QPushButton *changeEventButton;
     
     //
     void createLetter(const QString &address);

     QAction *printAction;
     QTabWidget *letters;
     //

 };

 #endif