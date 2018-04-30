/********************************************************************************
** Form generated from reading UI file 'drawwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWIDGET_H
#define UI_DRAWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawWidget
{
public:

    void setupUi(QWidget *DrawWidget)
    {
        if (DrawWidget->objectName().isEmpty())
            DrawWidget->setObjectName(QStringLiteral("DrawWidget"));
        DrawWidget->resize(400, 300);

        retranslateUi(DrawWidget);

        QMetaObject::connectSlotsByName(DrawWidget);
    } // setupUi

    void retranslateUi(QWidget *DrawWidget)
    {
        DrawWidget->setWindowTitle(QApplication::translate("DrawWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawWidget: public Ui_DrawWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWIDGET_H
