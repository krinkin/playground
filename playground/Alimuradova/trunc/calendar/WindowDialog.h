// File : windowText.h
// Autor : Alimuradova Yana Vidadievna (6352)
// Date: 04.07.2009
// Red.: 1.0

 #ifndef DETAILSDIALOG_H
 #define DETAILSDIALOG_H

 #include <QDialog>
 #include <QList>
 #include <QPair>
 #include <QString>
 #include <QDate>

 #include "EventList.h"
 #include "Note.h"
 

 class QDialogButtonBox;
 class QLabel;
 class QLineEdit;
 class QTextEdit;
 class QWidget;

 class WindowDialog : public QDialog
 {
     Q_OBJECT

 public:
     WindowDialog(const QString &title, QWidget *parent);
     void setCurrenDate(QDate currentDate);

 public slots:
     void verify();
     QString senderEvent() const;

 public:
     //QList<QPair<QString, int> > orderItems();
     void sendEvent();
     
 private:
    
     QDate curDate;
     QLabel *eventLabel;
     QStringList items;
     QTextEdit *eventEdit;
     QDialogButtonBox *buttonBox;
     
 };

 #endif