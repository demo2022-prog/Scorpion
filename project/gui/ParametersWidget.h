#ifndef PARAMETERSWIDGET_H
#define PARAMETERSWIDGET_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class ParametersWidget;
}

class ParametersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersWidget(QSettings *setFile = nullptr, QWidget *parent = nullptr);
    ~ParametersWidget();

    QSettings* setFile;
private slots:
    void on_selectStyleBox_activated(int index);

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    std::vector<QString> styles;

private:
    void loadStyle();
    void setStyleSheet(int index);

private:
    Ui::ParametersWidget *ui;
};

#endif // PARAMETERSWIDGET_H
