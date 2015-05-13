#include <QtWidgets/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
 //   Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("SopaSoft");
    app.setApplicationName("SopaLanguageLynx");
    MainWindow w;
    w.show();
    return app.exec();
}


