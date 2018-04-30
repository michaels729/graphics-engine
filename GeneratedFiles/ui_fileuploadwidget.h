/********************************************************************************
** Form generated from reading UI file 'fileuploadwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEUPLOADWIDGET_H
#define UI_FILEUPLOADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileUploadWidget
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *FileUploadWidget)
    {
        if (FileUploadWidget->objectName().isEmpty())
            FileUploadWidget->setObjectName(QStringLiteral("FileUploadWidget"));
        FileUploadWidget->resize(400, 44);
        lineEdit = new QLineEdit(FileUploadWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 10, 251, 20));
        pushButton = new QPushButton(FileUploadWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 91, 23));

        retranslateUi(FileUploadWidget);

        QMetaObject::connectSlotsByName(FileUploadWidget);
    } // setupUi

    void retranslateUi(QWidget *FileUploadWidget)
    {
        FileUploadWidget->setWindowTitle(QApplication::translate("FileUploadWidget", "Form", nullptr));
        pushButton->setText(QApplication::translate("FileUploadWidget", "Browse...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileUploadWidget: public Ui_FileUploadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEUPLOADWIDGET_H
