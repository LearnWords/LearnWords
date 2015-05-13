#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

class MainWindow;

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    ConfigDialog(const MainWindow*);


public slots:


private:
	const MainWindow *mainWindow;

};

#endif
