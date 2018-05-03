
/*
 * File:   main.cpp
 * Author: Kevin
 * Created on April 27, 2018, 5:48 PM
 */

#include <QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow mw;
    
    mw.show();
    mw.setFixedSize(mw.size());
    return app.exec();
}
