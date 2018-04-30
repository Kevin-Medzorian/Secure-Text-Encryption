
/*
 * File:   MainWindow.cpp
 * Author: Kevin
 * Created on April 27, 2018, 6:37 PM
 */

#include "MainWindow.h"
#include "picosha2.h"

#include <QCoreApplication>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> encrypted;
void WriteToFile(string, string);
void UpdateData();

MainWindow::MainWindow() {
    widget.setupUi(this);

    connect(widget.btnSave, &QPushButton::released, this, &MainWindow::Save);
    connect(widget.btnLoad, &QPushButton::released, this, &MainWindow::Load);
    connect(widget.btnClear, &QPushButton::released, this, &MainWindow::Wipe);


    connect(widget.fieldKey, &QLineEdit::textEdited, this, &MainWindow::TextEdited);
    connect(widget.fieldIn, &QLineEdit::textEdited, this, &MainWindow::TextEdited);
    connect(widget.fieldTitle, &QLineEdit::textEdited, this, &MainWindow::TextEdited);

    UpdateData();
    
    widget.line->setFocus();
}

MainWindow::~MainWindow() {
}

void MainWindow::Save() {
    string raw = widget.fieldIn->text().toStdString(),
            key = picosha2::hash256_hex_string(widget.fieldKey->text().toUpper().toStdString()),
            title = widget.fieldTitle->text().toStdString(),
            encrypted = raw;

    
    for (int i = 0, k = key.length() / 2; (unsigned) i < raw.length(); i++) {
        encrypted[i] = raw[i] ^ key[--k] + k - i;

        k = k == 0 ? key.length() : k;
    }

    WriteToFile(title, encrypted);

}

void MainWindow::Load() {
    if ((unsigned) widget.Selection->currentIndex() < encrypted.size()) {
        
        string raw = encrypted[widget.Selection->currentIndex()],
                key = picosha2::hash256_hex_string(widget.fieldKey->text().toUpper().toStdString()),
                decrypted = raw;

        for (int i = 0, k = key.length() / 2; (unsigned) i < raw.length(); i++) {
            decrypted[i] = raw[i] ^ key[--k] + k - i;

            k = k == 0 ? key.length() : k;
        }

        widget.fieldOut->setText(QString::fromStdString(decrypted));
    }
}

void MainWindow::Wipe(){
    remove("storage.dat");
    encrypted.clear();
    widget.Selection->clear();
    widget.fieldOut->clear();
}

bool fileExists(const char *fileName){
    ifstream infile(fileName);
    return infile.good();
}

void MainWindow::WriteToFile(string title, string encryptedText) {
    
    string newline = fileExists("storage.dat") ? "\n" : "";
    
    ofstream storage("storage.dat",  std::ios_base::app);

    storage << newline << title << endl << encryptedText;

    storage.close();
    
    UpdateData();
}

void MainWindow::UpdateData() {
    encrypted.clear();
    widget.Selection->clear();
    
    ifstream storage ("storage.dat");
    string title;

    while (getline(storage, title)) {
        string msg;
        getline(storage, msg);
        
        widget.Selection->addItem(QString::fromStdString(title));
        encrypted.push_back(msg);
    }
    
    storage.close();
}

void MainWindow::TextEdited() {
    widget.btnSave->setEnabled(widget.fieldIn->text().length() > 0 && widget.fieldKey->text().length() > 0 && widget.fieldTitle->text().length() > 0);
    widget.btnLoad->setEnabled(widget.fieldKey->text().length() > 0);
}