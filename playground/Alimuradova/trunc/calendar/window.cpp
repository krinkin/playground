// File : window.cpp
// Autor : Alimuradova Yana Vidadievna (6352)
// Date: 04.07.2009
// Red.: 1.0

#include <QtGui>
#include "window.h"
#include "WindowDialog.h"

 Window::Window()
 {
     createPreviewGroupBox();
     createGeneralOptionsGroupBox();
     createDateGroupBox();
 
     createSample();
     
     QGridLayout *layout = new QGridLayout;
     layout->addWidget(previewGroupBox, 0, 0);
     layout->addWidget(generalOptionsGroupBox, 1, 0);
     layout->addWidget(dateGroupBox, 2, 0);
     layout->setSizeConstraint(QLayout::SetFixedSize);
     setLayout(layout);

     previewLayout->setRowMinimumHeight(0, calendar->sizeHint().height());
     previewLayout->setColumnMinimumWidth(0, calendar->sizeHint().width());

     setWindowTitle(tr("Calendar"));
 }

 void Window::localeChanged(int index)
 {
     calendar->setLocale(localeCombo->itemData(index).toLocale());
 }

 void Window::firstDayChanged(int index)
 {
     calendar->setFirstDayOfWeek(Qt::DayOfWeek(
                                 firstDayCombo->itemData(index).toInt()));
 }

 void Window::selectionModeChanged(int index)
 {
     calendar->setSelectionMode(QCalendarWidget::SelectionMode(
                                selectionModeCombo->itemData(index).toInt()));
 }

 void Window::selectedDateChanged()
 {
     currentDateEdit->setDate(calendar->selectedDate());
 }

 void Window::createPreviewGroupBox()
 {
     previewGroupBox = new QGroupBox(tr("Preview"));

     calendar = new QCalendarWidget;
     calendar->setMinimumDate(QDate(1900, 1, 1));
     calendar->setMaximumDate(QDate(3000, 1, 1));
     calendar->setGridVisible(true);

     connect(calendar, SIGNAL(currentPageChanged(int, int)),
             this, SLOT(reformatCalendarPage()));

     previewLayout = new QGridLayout;
     previewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
     previewGroupBox->setLayout(previewLayout);
 }

 void Window::createGeneralOptionsGroupBox()
 {
     generalOptionsGroupBox = new QGroupBox(tr("Options"));

     localeCombo = new QComboBox;
     int curLocaleIndex = -1;
     int index = 0;
     for (int _lang = QLocale::C; _lang <= QLocale::LastLanguage; ++_lang) {
         QLocale::Language lang = static_cast<QLocale::Language>(_lang);
         QList<QLocale::Country> countries = QLocale::countriesForLanguage(lang);
         for (int i = 0; i < countries.count(); ++i) {
             QLocale::Country country = countries.at(i);
             QString label = QLocale::languageToString(lang);
             label += QLatin1Char('/');
             label += QLocale::countryToString(country);
             QLocale locale(lang, country);
             if (this->locale().language() == lang && this->locale().country() == country)
                 curLocaleIndex = index;
             localeCombo->addItem(label, locale);
             ++index;
         }
     }
     if (curLocaleIndex != -1)
         localeCombo->setCurrentIndex(curLocaleIndex);
     localeLabel = new QLabel(tr("Locale"));
     localeLabel->setBuddy(localeCombo);

     firstDayCombo = new QComboBox;
     firstDayCombo->addItem(tr("Sunday"), Qt::Sunday);
     firstDayCombo->addItem(tr("Monday"), Qt::Monday);
     
     firstDayLabel = new QLabel(tr("Week starts on"));
     firstDayLabel->setBuddy(firstDayCombo);

     connect(localeCombo, SIGNAL(currentIndexChanged(int)),
             this, SLOT(localeChanged(int)));
     connect(firstDayCombo, SIGNAL(currentIndexChanged(int)),
             this, SLOT(firstDayChanged(int)));
     
     QHBoxLayout *checkBoxLayout = new QHBoxLayout;
     checkBoxLayout->addStretch();
     
     QGridLayout *outerLayout = new QGridLayout;
     outerLayout->addWidget(localeLabel, 0, 0);
     outerLayout->addWidget(localeCombo, 0, 1);
     outerLayout->addWidget(firstDayLabel, 1, 0);
     outerLayout->addWidget(firstDayCombo, 1, 1);
     generalOptionsGroupBox->setLayout(outerLayout);

     firstDayChanged(firstDayCombo->currentIndex());
 }

 void Window::createDateGroupBox()
 {
     dateGroupBox = new QGroupBox(tr("Event"));
     
     currentDateEdit = new QDateEdit;
     currentDateEdit->setDisplayFormat("MMM d yyyy");
     currentDateEdit->setDate(calendar->selectedDate());
     currentDateEdit->setDateRange(calendar->minimumDate(),
                                   calendar->maximumDate());

     currentDateLabel = new QLabel(tr("Current Date:"));
     currentDateLabel->setBuddy(currentDateEdit);

     changeEventButton = new QPushButton(tr("Add/Change Event"));

     connect(currentDateEdit, SIGNAL(dateChanged(const QDate &)),
             calendar, SLOT(setSelectedDate(const QDate &)));
     connect(calendar, SIGNAL(selectionChanged()),
             this, SLOT(selectedDateChanged()));
     connect(changeEventButton, SIGNAL(clicked()),
             this, SLOT(openDialog()));
     
     QGridLayout *dateBoxLayout = new QGridLayout;
     dateBoxLayout->addWidget(currentDateLabel, 1, 0);
     dateBoxLayout->addWidget(currentDateEdit, 1, 1);
     dateBoxLayout->addWidget(changeEventButton, 1, 2);
     dateBoxLayout->setRowStretch(1, 1);

     dateGroupBox->setLayout(dateBoxLayout);
}

 void Window::openDialog()
 {
     WindowDialog dialog(tr("Add/Change Event"), this);
     //dialog.setCurrenDate(dialog.sendEvent()/*calendar->selectedDate()*/);

     if (dialog.exec() == QDialog::Accepted)
         createLetter(dialog.senderEvent()/*dialog.sendEvent()*/);
     //printAction->setEnabled(true);
     /*if (dialog.exec() == QDialog::Accepted)
         createLetter(dialog.senderName(), dialog.senderAddress(),
                      dialog.orderItems(), dialog.sendOffers());*/
 }

 void Window::printFile()
 {
 #ifndef QT_NO_PRINTER
     QTextEdit *editor = static_cast<QTextEdit*>(letters->currentWidget());
     QPrinter printer;

     QPrintDialog *dialog = new QPrintDialog(&printer, this);
     dialog->setWindowTitle(tr("Print Document"));
     if (editor->textCursor().hasSelection())
         dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
     if (dialog->exec() != QDialog::Accepted)
         return;

     editor->print(&printer);
 #endif
 }

void Window::createLetter(const QString &address)
 {
     QTextEdit *editor = new QTextEdit;

     printAction->setEnabled(true);
 }

 void Window::createSample()
 {
     WindowDialog dialog("Default window", this);
  
 }