// File : window.cpp
// Autor : Alimuradova Yana Vidadievna (6352)
// Date: 04.07.2009
// Red.: 1.0

 #include <QtGui>

 #include "WindowDialog.h"
 #include "EventList.h"
 #include "Note.h"

 WindowDialog::WindowDialog(const QString &title, QWidget *parent)
     : QDialog(parent)
 {
     eventLabel = new QLabel(tr("Event:"));
     eventLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);

     eventEdit = new QTextEdit;

     buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                      | QDialogButtonBox::Cancel);

     connect(buttonBox, SIGNAL(accepted()), this, SLOT(verify()));
     connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

     QGridLayout *mainLayout = new QGridLayout;
     mainLayout->addWidget(eventLabel, 0, 0);
     mainLayout->addWidget(eventEdit, 0, 1);
     mainLayout->addWidget(buttonBox, 3, 0, 1, 3);
     setLayout(mainLayout);
     setWindowTitle(title);
 }
/*
 QList<QPair<QString, int> > WindowDialog::orderItems()
 {
     QList<QPair<QString, int> > orderList;

     for (int row = 0; row < items.count(); ++row) {
         QPair<QString, int> item;
         //item.first = itemsTable->item(row, 0)->text();
         //int quantity = itemsTable->item(row, 1)->data(Qt::DisplayRole).toInt();
         //item.second = qMax(0, quantity);
         orderList.append(item);
     }

     return orderList;
 }
*/
 void WindowDialog::sendEvent() 
 {
  QString St = eventEdit->toPlainText();
  Note *newNote = new Note(curDate, St);     
//return eventEdit->toPlainText();
 }

 void WindowDialog::verify()
 {
     if (!eventEdit->toPlainText().isEmpty()) {
         accept();
         return;
     }

/*     QMessageBox::StandardButton answer;
     answer = QMessageBox::warning(this, tr("Incomplete Form"),
         tr("The form does not contain all the necessary information.\n"
            "Do you want to discard it?"),
         QMessageBox::Yes | QMessageBox::No);
*/
     //if (answer == QMessageBox::Yes)
       //  verify();//reject()
 }

 void WindowDialog::setCurrenDate(QDate currentDate1)
 { 
  curDate=currentDate1;
 }

 QString WindowDialog::senderEvent() const
 {
     return eventEdit->toPlainText();
 }