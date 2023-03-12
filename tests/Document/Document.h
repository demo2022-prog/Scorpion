#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QTextEdit>
#include <QWidget>

class Document : public QWidget
{
    Q_OBJECT
    friend class Test_Document;
public:
    explicit Document(QWidget *parent = nullptr);

public:
    void rename(const QString& newName);
    void changePath(const QString& newPath);

    QString getText();
    QTextEdit* getTextEdit();

    const QString& getName();
    const QString& getPath();

private:
    QString name;
    QString path;

    QTextEdit* textEdit;

};

#endif // DOCUMENT_H
