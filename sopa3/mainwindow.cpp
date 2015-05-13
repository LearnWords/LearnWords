#include <QtWidgets>
#include <QSettings>
#include <iostream>
#include "mainwindow.h"

MainWindow::MainWindow() : level(0), dict(NULL), dialog(this)
{
 //   textEdit = new QPlainTextEdit;
	QWidget *window = new QWidget();
    setCentralWidget(window);

	QVBoxLayout * v  = new QVBoxLayout();
	QWidget * top    = new QWidget;
	QWidget * bottom = new QWidget;
	v->addWidget(top);
	v->addWidget(bottom);
    window->setLayout(v);

	QHBoxLayout *h1 = new QHBoxLayout();
	top->setLayout(h1);
	QPushButton *btnStartStop = new QPushButton("Start");
    QPushButton *btnConfig    = new QPushButton("Config");
	h1->addWidget(btnStartStop);
	h1->addWidget(btnConfig);

	readSettings();

	connect(btnConfig, SIGNAL(clicked()), this, SLOT(configure()));
	


/*    connect(textEdit->document(),
			SIGNAL(contentsChanged()),
            this, 
			SLOT(documentWasModified())
	);
*/
    
}



void MainWindow::readSettings()
{
    QSettings settings("SopaSoft", "SopaLanguageLynx");
	dictFile = settings.value("dict").toString();
	level    = settings.value("level").toInt();
	readDictionary();
}
void MainWindow::configure() 
{
	dialog.exec();

}
void MainWindow::start_stop()
{


}

void MainWindow::writeSettings()
{
    QSettings settings("SopaSoft", "SopaLanguageLynx");
    settings.setValue("dict", dictFile);
    settings.setValue("level", level);
}
void MainWindow::readDictionary()
{
	if(dict) { delete dict; } 
	dict = new MyDictionary(dictFile);
}

int MainWindow::getLevel() { 
	return level; 
}
QString MainWindow::getDictFile() { 
	return dictFile;
}
void MainWindow::setLevel(int x) {
	level = x;
	std::cerr<<"set level " <<x<<std::endl;
}
void MainWindow::setDictFile(const QString& s) 
{
	dictFile=s;
}


