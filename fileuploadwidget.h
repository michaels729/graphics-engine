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
    void fileSelected(std::shared_ptr<QFile> file);

public slots:
    void select();

private:
    std::unique_ptr<QPushButton> browseButton;
    std::unique_ptr<QLineEdit> fileNameBox;
    std::shared_ptr<QFile> file;
};

#endif // FILEUPLOADWIDGET_H
