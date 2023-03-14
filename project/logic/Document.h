#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QTextEdit>
#include <QWidget>

class Document : public QWidget
{
    Q_OBJECT
public:
    explicit Document(QWidget *parent = nullptr);

public:
    void rename(const QString& newName);
    void changePath(const QString& newPath);

    QString getText();
    QTextEdit* getTextEdit();

    const QString& getName();
    const QString& getPath();

    int getIndex();
    void setIndex(int newIndex);

private:
    QString name;
    QString path;

    QTextEdit* textEdit;

    int index = 0;

};

#endif // DOCUMENT_H
