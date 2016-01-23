#include <QtWidgets>
#include <QResource>
#include "Source/MainWindow.h"

int main(int argc, char * argv[]) {
    QApplication application(argc,argv);

    QResource::registerResource("../Resource/Resource.rcc");

    MainWindow mainWindow;
    mainWindow.show();

    return application.exec();
}