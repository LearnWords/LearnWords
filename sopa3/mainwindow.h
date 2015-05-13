#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydict.h"
#include "configdialog.h"

class QAction;
class QMenu;
class QPlainTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
	int getLevel();
	QString getDictFile();
public slots:
	void setLevel(int);
	void setDictFile(const QString&);



private slots:
    void configure();
    void start_stop();
	
private:
    void readSettings();
    void writeSettings();
	void readDictionary();

 	QString dictFile;
	int level;
	MyDictionary *dict;
	ConfigDialog dialog;
};

#endif
