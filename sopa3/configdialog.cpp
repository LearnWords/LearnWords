#include <QtWidgets>

#include "configdialog.h"
#include "mainwindow.h"


ConfigDialog::ConfigDialog(const MainWindow * x) : mainWindow(x)
{
	
    QWidget *dictEdit  =  new QWidget;
	QWidget *levelEdit =  new QWidget;
	QVBoxLayout * v  = new QVBoxLayout();
	QRadioButton *level0 = new QRadioButton();
	QRadioButton *level1 = new QRadioButton();
	v->addWidget(level0);
	v->addWidget(level1);
	level0->setText("Выбор варианта");
	level1->setText("Свободный ввод");
	levelEdit->setLayout(v);

	QHBoxLayout * h  = new QHBoxLayout();
	QLabel * show_filename = new QLabel();
	QPushButton *file_button = new QPushButton();

	file_button->setText("Выбор словаря");
	
	h->addWidget(show_filename);
	h->addWidget(file_button);

	dictEdit->setLayout(h);

    QSignalMapper* signalMapper = new QSignalMapper();
    signalMapper->setMapping(level0, 0);
    signalMapper->setMapping(level1, 1);
	
	connect(level0, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(level1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	
	connect(signalMapper, SIGNAL(mapped(const int &)),mainWindow, SLOT(setLevel(int)));

	QFormLayout *formLayout = new QFormLayout;
	formLayout->addRow(tr("Словарь"), dictEdit);
	formLayout->addRow(tr("Уровень"), levelEdit);
	setLayout(formLayout);

    setWindowTitle(tr("Настройка"));
	setModal(true);

	
}


