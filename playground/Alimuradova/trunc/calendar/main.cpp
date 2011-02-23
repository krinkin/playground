// File : main.cpp
// Autor : Alimuradova Yana Vidadievna (6352)
// Date: 04.07.2009
// Red.: 1.0

 #include <QtGui>
 #include "window.h"

 int main(int argv, char *args[])
 {
     QApplication app(argv, args);
     Window window;
     window.show();
     return app.exec();
 }




