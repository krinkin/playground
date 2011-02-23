#ifndef MYWIDGET_CPP
#define MYWIDGET_CPP

#include <qwidget.h>
#include <qpainter.h>
#include <qpen.h>
#include "qfont.h"
#include <qstring.h>
#include "model.cpp"
//#include "qgridlayout.h"
#include "qpushbutton.h"
//#include "qvboxlayout.h"
//#include "qhboxlayout.h"
#include "qinputdialog.h"
#include <QtGui>

class MyWidget: public QWidget {
    private:
        int myTop;
        int myLeft;
        int mySize;
        Model *myModel;


    public:
        MyWidget(QWidget * parent = 0) : QWidget(parent) {
	     myLeft = 30;
	     myTop = 60; 
             mySize = 30;
        }

       void setModel(Model * m) {
           myModel = m;
       }
       
       void mousePressEvent(QMouseEvent *ev) {
           int x = ev->x();
           int y = ev->y();
           if ((x >= (myLeft + mySize * 8 + 15)) && (x <= (myLeft + mySize * 11 + 15)) && (y >= (myTop + mySize * 2)) && (y <= myTop + mySize * 8)) {
              myModel->setUpState();
              repaint();
          }
          if ((x >= (myLeft + mySize * 8 + 15)) && (x <= (myLeft + mySize * 11 + 15)) && (y >= (myTop + mySize * 5)) && (y <= myTop + mySize * 11)) {
              myModel->setDownState();
              repaint();
          }

          if ((x > (myLeft + mySize)) && (x < (myLeft + mySize * 8)) && (y > (myTop + mySize )) && (y < (myTop + mySize * 7))) {
          int i = (x - myLeft - mySize) / 7;
          int j = (y - myLeft - mySize) / 6;
          bool ok;
          QString text = QInputDialog::getText(this, tr("Input"), tr ("Note:"), QLineEdit::Normal, "Data", &ok);
           
          }
  
      }

  
        void paintEvent(QPaintEvent * event) {
            QPainter painter(this);
           // layout->setWidget(&painter, 1, 1, Qt::AlignCenter);
            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
            painter.drawLine(myLeft + mySize, myTop, myLeft + mySize, myTop + 7 * mySize);
            int i;
            for (i = 0; i < 7; i++) {
                painter.drawLine(myLeft + (i + 2) * mySize, myTop + mySize, myLeft + (i + 2) * mySize, myTop + 7 * mySize);
            }
            painter.drawLine(myLeft, myTop + mySize, myLeft + mySize * 8, myTop + mySize);
            for (i = 0; i < 6; i ++) {
                painter.drawLine(myLeft + mySize, myTop + (i + 2) * mySize, myLeft + mySize * 8, myTop + (i + 2) * mySize);
            } 
            painter.setFont(QFont("Times", 11, QFont::Normal));
            painter.drawText(myLeft + mySize * 1 + 3, myTop + mySize - 5, "MON");
            painter.drawText(myLeft + mySize * 2 + 3, myTop + mySize - 5, "TUE");
            painter.drawText(myLeft + mySize * 3 + 3, myTop + mySize - 5, "WED");
            painter.drawText(myLeft + mySize * 4 + 3, myTop + mySize - 5, "THU");
            painter.drawText(myLeft + mySize * 5 + 3, myTop + mySize - 5, "FRI");
            painter.drawText(myLeft + mySize * 6 + 3, myTop + mySize - 5, "SAT");
            painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
            painter.drawText(myLeft + mySize * 7 + 3, myTop + mySize - 5, "SUN"); 
            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
            int* arrayWeek = myModel->getWeeks();
            painter.setFont(QFont("Times", 17, QFont::Normal));
            QString t;
            for (i = 0; i < 6; i++) {
                t = t.setNum(arrayWeek[i]);
                painter.drawText(myLeft + 10, myTop + mySize * (i + 2) - 10, t);
            }
            int j;
            QString s;
            for (i = 0; i < 6; i ++) {
                for (j = 0; j < 7; j++) {
                    int num = myModel->getCell(i,j);
                    s = s.setNum(num);
                    painter.drawText(myLeft + mySize * (j + 1) + mySize / 4, myTop + mySize * (i + 2) - mySize / 3, s);
                }
            }
            QString month;
            switch (myModel->getMonth()) {
                case 1:
                    month = "January";
                    break;
		case 2:
		    month = "Febrary";
		    break;
		case 3:
		    month = "March";
		    break;
		case 4:
		    month = "April";
		    break;
		case 5:
		    month = "May";
		    break;
		case 6:
		    month = "June";
		    break;
		case 7:
		    month = "July";
		    break;
		case 8:
		    month = "August";
		    break;
		case 9:
		    month = "September";
		    break;
		case 10:
		    month = "Octember";
		    break;
		case 11:
		    month = "November";
		    break;
		case 12:
		    month = "December";
		    break;
		default:
		    month = " ";
            }
            painter.setFont(QFont("Times", 30, QFont::Normal));
	    painter.drawText(myLeft, myTop - mySize / 2, month);
            QString year;
            year = year.setNum(myModel->getYear());
            painter.drawText(myLeft + mySize * 6, myTop - mySize / 2, year);
            painter.drawRect(myLeft + mySize * 8 + 15, myTop + mySize * 2, mySize * 3, mySize);
            painter.drawText(myLeft + mySize * 9 + 15, myTop + mySize * 3 - 5, "UP");
            painter.drawRect(myLeft + mySize * 8 + 15, myTop + mySize * 5, mySize * 3, mySize);
            painter.drawText(myLeft + mySize * 8 + 25, myTop + mySize * 6 - 5, "Down");

            
        }
};

#endif;
