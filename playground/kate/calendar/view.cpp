#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <qwidget.h>
#include <qpainter.h>
#include <qpen.h>
#include <qcolor.h>
#include <mywidget.cpp>
#include <QtGui>
#include <model.cpp>



void find2(QPushButton *b) {
b->setText("JJJJJ");
}

int main(int argc, char *argv[])
{
    Model *model = new Model;
    QApplication app(argc, argv);
    QWidget mainW;
   // QWidget w;
    MyWidget *wgt1 = new MyWidget();
    wgt1->setModel(model);
   // wgt1.setPaletteBackgroundColor(Qt::blue);
    mainW.resize(400, 300);
    mainW.setWindowTitle("Calendar");
    //wgt1.show();
   // QMainWindow w;
   // w.setWindowTitle("Calendar");
    //w.resize(300, 300);
      //w.setMaximumSize(35,35);
   //app.setMainWidget(&wgt1);
    QVBoxLayout* leftLayout = new QVBoxLayout;
	//leftLayout->addLayout(topLeftLayout);
	//leftLayout->addWidget(caseCheckBox);
	//leftLayout->addWidget(backwardCheckBox);	
	//MyQVBoxLayout* rightLayout = new MyQVBoxLayout;
        //rightLayout->setModel(model);
        //rightLayout->setWidget(wgt1);
       // QPushButton *up = new QPushButton("UP");
        //up->setMaximumSize(35, 35);
        //QPushButton *down = new QPushButton("DOWN");
        //down ->setMaximumSize(35, 35);
        //rightLayout->connect(down, SIGNAL(clicked()), rightLayout, SLOT(find2()));
        //rightLayout->addWidget(&w);
        //up->setText("1111");
	//rightLayout->addWidget(up);
       // rightLayout->addWidget(down);
        leftLayout->addWidget(wgt1);
        //Buttons butt;
        //butt.setMaximumSize(50, 50);
        //leftLayout->addWidget(&butt);
        
        
	//rightLayout->addWidget(closeButton);
	//rightLayout->addStretch();
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	//mainLayout->addLayout(rightLayout);
	mainW.setLayout(mainLayout);
        mainW.show();
    
    return app.exec();
}
