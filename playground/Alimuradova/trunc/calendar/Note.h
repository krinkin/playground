// File : Note.h
// Autor : Alimuradova Yana Vidadievna (6352)
// Date: 04.07.2009
// Red.: 1.0

 #ifndef NOTE_H
 #define NOTE_H

 #include <QDate>
 #include <QString>

 class Note  
 {

  private:
      
     QString textEvent;
     QDate dateEvent;
         
  public:

     Note(QDate d, QString t);
 
 };

 #endif