/* 
 * File:   MainWindow.h
 * Author: Kevin
 * Created on April 27, 2018, 6:37 PM
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow : public QDialog {
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();
    void UpdateData();
    void WriteToFile(std::string, std::string);
    void RemoveTitle(std::string);
    std::string GetRaw(std::string);
    std::string asString(int);
private slots:
    void Save();
    void TextEdited();
    void Load();
    void Wipe();
    void Toggle();
private:
    Ui::MainWindow widget;
};

#endif
