/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *MainLayout;
    QLineEdit *fieldKey;
    QHBoxLayout *TextGroup;
    QLineEdit *fieldIn;
    QHBoxLayout *TitleGroup;
    QLineEdit *fieldTitle;
    QPushButton *btnSave;
    QFrame *line;
    QHBoxLayout *LoadGroup;
    QPushButton *btnClear;
    QComboBox *Selection;
    QPushButton *btnLoad;
    QLineEdit *fieldOut;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(802, 333);
        verticalLayoutWidget_2 = new QWidget(MainWindow);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 13, 778, 311));
        QFont font;
        font.setFamily(QStringLiteral("Courier 10 Pitch"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        verticalLayoutWidget_2->setFont(font);
        MainLayout = new QVBoxLayout(verticalLayoutWidget_2);
        MainLayout->setObjectName(QStringLiteral("MainLayout"));
        MainLayout->setContentsMargins(0, 0, 0, 0);
        fieldKey = new QLineEdit(verticalLayoutWidget_2);
        fieldKey->setObjectName(QStringLiteral("fieldKey"));
        fieldKey->setFont(font);
        fieldKey->setFrame(true);
        fieldKey->setEchoMode(QLineEdit::Password);
        fieldKey->setAlignment(Qt::AlignCenter);

        MainLayout->addWidget(fieldKey);

        TextGroup = new QHBoxLayout();
        TextGroup->setObjectName(QStringLiteral("TextGroup"));
        fieldIn = new QLineEdit(verticalLayoutWidget_2);
        fieldIn->setObjectName(QStringLiteral("fieldIn"));
        fieldIn->setFont(font);

        TextGroup->addWidget(fieldIn);


        MainLayout->addLayout(TextGroup);

        TitleGroup = new QHBoxLayout();
        TitleGroup->setObjectName(QStringLiteral("TitleGroup"));
        TitleGroup->setSizeConstraint(QLayout::SetDefaultConstraint);
        fieldTitle = new QLineEdit(verticalLayoutWidget_2);
        fieldTitle->setObjectName(QStringLiteral("fieldTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fieldTitle->sizePolicy().hasHeightForWidth());
        fieldTitle->setSizePolicy(sizePolicy);
        fieldTitle->setMinimumSize(QSize(0, 0));
        fieldTitle->setMaximumSize(QSize(16777215, 16777215));
        fieldTitle->setFont(font);

        TitleGroup->addWidget(fieldTitle);

        btnSave = new QPushButton(verticalLayoutWidget_2);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy1);
        btnSave->setFont(font);

        TitleGroup->addWidget(btnSave);


        MainLayout->addLayout(TitleGroup);

        line = new QFrame(verticalLayoutWidget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setFont(font);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(100);
        line->setMidLineWidth(100);
        line->setFrameShape(QFrame::HLine);

        MainLayout->addWidget(line);

        LoadGroup = new QHBoxLayout();
        LoadGroup->setObjectName(QStringLiteral("LoadGroup"));
        btnClear = new QPushButton(verticalLayoutWidget_2);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        LoadGroup->addWidget(btnClear);

        Selection = new QComboBox(verticalLayoutWidget_2);
        Selection->setObjectName(QStringLiteral("Selection"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Selection->sizePolicy().hasHeightForWidth());
        Selection->setSizePolicy(sizePolicy2);
        Selection->setFont(font);
        Selection->setToolTipDuration(-1);
        Selection->setMaxVisibleItems(10);

        LoadGroup->addWidget(Selection);

        btnLoad = new QPushButton(verticalLayoutWidget_2);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setEnabled(false);
        btnLoad->setFont(font);
        btnLoad->setFlat(false);

        LoadGroup->addWidget(btnLoad);


        MainLayout->addLayout(LoadGroup);

        fieldOut = new QLineEdit(verticalLayoutWidget_2);
        fieldOut->setObjectName(QStringLiteral("fieldOut"));
        fieldOut->setEnabled(true);
        fieldOut->setFont(font);
        fieldOut->setAcceptDrops(true);
        fieldOut->setFrame(true);
        fieldOut->setAlignment(Qt::AlignCenter);
        fieldOut->setReadOnly(true);

        MainLayout->addWidget(fieldOut);

        QWidget::setTabOrder(fieldKey, fieldIn);
        QWidget::setTabOrder(fieldIn, fieldTitle);
        QWidget::setTabOrder(fieldTitle, btnSave);
        QWidget::setTabOrder(btnSave, Selection);
        QWidget::setTabOrder(Selection, btnLoad);
        QWidget::setTabOrder(btnLoad, fieldOut);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Text Encrypter", 0));
#ifndef QT_NO_STATUSTIP
        fieldKey->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        fieldKey->setInputMask(QString());
        fieldKey->setPlaceholderText(QApplication::translate("MainWindow", "[Cryptographic Key]", 0));
        fieldIn->setPlaceholderText(QApplication::translate("MainWindow", "[Secret Message]", 0));
        fieldTitle->setPlaceholderText(QApplication::translate("MainWindow", "[Message Title]", 0));
        btnSave->setText(QApplication::translate("MainWindow", "Save/Encrypt", 0));
#ifndef QT_NO_TOOLTIP
        btnClear->setToolTip(QApplication::translate("MainWindow", "Wipe & delete the storage.dat", 0));
#endif // QT_NO_TOOLTIP
        btnClear->setText(QApplication::translate("MainWindow", "Wipe Storage", 0));
#ifndef QT_NO_TOOLTIP
        Selection->setToolTip(QApplication::translate("MainWindow", "Select a message to decrypt.", 0));
#endif // QT_NO_TOOLTIP
        Selection->setCurrentText(QString());
        btnLoad->setText(QApplication::translate("MainWindow", "Load/Decrypt", 0));
        fieldOut->setPlaceholderText(QApplication::translate("MainWindow", "[Decrypted Message]", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
