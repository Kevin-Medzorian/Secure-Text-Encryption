
/*
 * File:   MainWindow.cpp
 * Author: Kevin
 * Created on April 27, 2018, 6:37 PM
 */

#include "MainWindow.h"
#include "picosha2.h"

#include <QCoreApplication>
#include <QMouseEvent>
#include <fstream>
#include <iostream>
#include <sstream>
#include <valarray>

using namespace std;

vector<string> encrypted;
void WriteToFile(string, string);
void UpdateData();
void RemoveTitle(string);
void Toggle();
string GetRaw(string);
string asString(int);

MainWindow::MainWindow() {
    widget.setupUi(this);
  
    //Register UI Elements to their respective functions
    connect(widget.btnSave, &QPushButton::released, this, &MainWindow::Save);
    connect(widget.btnLoad, &QPushButton::released, this, &MainWindow::Load);
    connect(widget.btnClear, &QPushButton::released, this, &MainWindow::Wipe);
    connect(widget.btnToggle, &QPushButton::released, this, &MainWindow::Toggle);

    connect(widget.fieldKey, &QLineEdit::textEdited, this, &MainWindow::TextEdited);
    connect(widget.fieldIn, &QLineEdit::textEdited, this, &MainWindow::TextEdited);
    connect(widget.fieldTitle, &QLineEdit::textEdited, this, &MainWindow::TextEdited);

    setMouseTracking(true);
    //Run initial data parsing from storage.dat
    UpdateData();

    widget.line->setFocus();
    widget.fieldTitle->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_ ]+"), this));

}

MainWindow::~MainWindow() {
}

void MainWindow::Save() {

    //Read current data from UI and save it to storage.dat
    string raw = widget.fieldIn->text().toStdString(),
            title = widget.fieldTitle->text().toStdString(),
            key = picosha2::hash256_hex_string(picosha2::hash256_hex_string(title) + widget.fieldKey->text().toUpper().toStdString()),
            encrypted = raw;

    for (int i = 0, k = key.length() / 2; (unsigned) i < raw.length(); i++) {
        encrypted[i] = raw[i] ^ key[--k] + k - i;

        k = k == 0 ? key.length() : k;
    }

    widget.fieldIn->clear();
    widget.fieldTitle->clear();

    WriteToFile(title, encrypted);

}

void MainWindow::Load() {
    //Read data from storage.dat and decrypt

    string title = widget.Selection->currentText().toStdString(),
            raw = GetRaw(title),
            key = picosha2::hash256_hex_string(picosha2::hash256_hex_string(title) + widget.fieldKey->text().toUpper().toStdString()),
            decrypted = raw;
    if (raw != "-1") {
        for (int i = 0, k = key.length() / 2; (unsigned) i < raw.length(); i++) {
            decrypted[i] = raw[i] ^ key[--k] + k - i;

            k = k == 0 ? key.length() : k;
        }

        widget.fieldOut->setText(QString::fromStdString(decrypted));
    }
}

void MainWindow::Wipe() {
    remove((widget.Selection->currentText().toStdString() + ".crypt").data());
    RemoveTitle(widget.Selection->currentText().toStdString());
    widget.Selection->removeItem(widget.Selection->currentIndex());

    if (widget.Selection->count() == 0) {
        widget.btnLoad->setEnabled(false);
        widget.btnClear->setEnabled(false);
    }
    
}

bool fileExists(const char *fileName) {
    ifstream infile(fileName);
    return infile.good();
}

void MainWindow::WriteToFile(string title, string encryptedText) {

    //Add to Titles located in TextEncrypter.dat
    ofstream titles("titles.dat", std::ios_base::app);

    titles << title << endl;

    titles.close();


    ofstream storage((title + ".crypt").data(), std::ios_base::trunc);

    storage << encryptedText;

    storage.close();

    widget.btnLoad->setEnabled(true);

    UpdateData();
}

string MainWindow::GetRaw(string title) {
    ifstream raw((title + ".crypt").data());

    string out((std::istreambuf_iterator<char>(raw)),
            std::istreambuf_iterator<char>());

    if (out.empty()) {
        remove((title + ".crypt").data());
        widget.Selection->removeItem(widget.Selection->currentIndex());
        RemoveTitle(title);

        if (widget.Selection->count() == 0) {
            widget.btnLoad->setEnabled(false);
            widget.btnClear->setEnabled(false);
        }
        return "-1";
    }

    return out;
}

void MainWindow::UpdateData() {

    widget.btnClear->setEnabled(false);
    //Refreshes UI elements with data in storage.dat
    widget.Selection->clear();

    ifstream storage("titles.dat");
    string title;

    while (getline(storage, title)) {
        if (widget.Selection->findText(QString::fromStdString(title)) < 0) {
            widget.Selection->addItem(QString::fromStdString(title));
            widget.btnClear->setEnabled(true);
        }
    }

    storage.close();
}

void MainWindow::RemoveTitle(string title) {
    ifstream read("titles.dat");

    string titles = "";

    string line = "";
    while (getline(read, line)) {
        if (line != title)
            titles += line + "\n";
    }

    read.close();

    ofstream write("titles.dat", std::ios_base::trunc);

    write << titles;

    write.close();
}

void MainWindow::Toggle() {
    if (widget.fieldOut->echoMode() == QLineEdit::Password) {
        widget.fieldOut->setEchoMode(QLineEdit::Normal);
        widget.btnToggle->setText(" Hide ");
    } else {
        widget.fieldOut->setEchoMode(QLineEdit::Password);
        widget.btnToggle->setText(" Show ");
    }
}

void MainWindow::TextEdited() {
    widget.btnSave->setEnabled(widget.fieldIn->text().length() > 0 && widget.fieldKey->text().length() > 0 && widget.fieldTitle->text().length() > 0);
    widget.btnLoad->setEnabled(widget.fieldKey->text().length() > 0 && widget.Selection->count() > 0);
}

string MainWindow::asString(int a) {
    ostringstream temp;
    temp << a;
    return temp.str();
}