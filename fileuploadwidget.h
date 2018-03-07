#ifndef FILEUPLOADWIDGET_H
#define FILEUPLOADWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QFile>

#include <memory>

class FileUploadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileUploadWidget(QWidget *parent = nullptr);
    ~FileUploadWidget();

signals:

public slots :
    void select();

private:
    std::unique_ptr<QPushButton> browseButton;
    std::unique_ptr<QLineEdit> fileNameBox;
    std::unique_ptr<QFile> file;
};

#endif // FILEUPLOADWIDGET_H
