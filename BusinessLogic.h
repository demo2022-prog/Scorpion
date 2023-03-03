#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <QWidget>

class Document;

class BusinessLogic : public QWidget
{
    Q_OBJECT
public:
    explicit BusinessLogic(QWidget *parent = nullptr);
    ~BusinessLogic();

signals:
    void newDocument(Document* document);

    void textData(const QString& worlds, const QString& strings);

public slots:
    void showAbout();

    void createNewDocument();

    void openFile();

    void saveFile(Document* document);

    void saveFileAs(Document* document);

    void alignmentLeft(Document* document);

    void alignmentCenter(Document* document);

    void alignmentRight(Document* document);

    void copy(Document* document);

    void paste(Document* document);

    void cut(Document* document);

    void onTextData(Document* document);

private slots:
    void textChanged();

private:
    const QString getNameFromPath(const QString& path);


private:
    class AboutWidget* aboutWgt;

    class QTextEdit* senderTextEdit;

};

#endif // BUSINESSLOGIC_H
