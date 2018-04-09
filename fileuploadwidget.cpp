#include "fileuploadwidget.h"

#include <QLineEdit>
#include <QGridLayout>
#include <QShortcut>
#include <QApplication>
#include <QFileDialog>

FileUploadWidget::FileUploadWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Upload File"));
    browseButton.reset(new QPushButton(tr("&Browse"), this));
    connect(browseButton.get(), &QAbstractButton::clicked, this, &FileUploadWidget::select);

    fileNameBox.reset(new QLineEdit());
    fileNameBox->setReadOnly(true);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(browseButton.get(), 0, 0);
    mainLayout->addWidget(fileNameBox.get(), 0, 1, 1, 2);

    connect(new QShortcut(QKeySequence::Quit, this), &QShortcut::activated,
        qApp, &QApplication::quit);
}

FileUploadWidget::~FileUploadWidget()
{
}

void FileUploadWidget::select()
{
    QString fileName = (QFileDialog::getOpenFileName(this, tr("Open File"),
        "/home",
        tr("geometry (*.obj)")));
    file.reset(new QFile(fileName));
    fileNameBox->insert(fileName);
    emit fileSelected(file);
}