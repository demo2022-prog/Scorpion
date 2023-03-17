#ifndef PARAMETERSWIDGET_H
#define PARAMETERSWIDGET_H

#include <QWidget>

namespace Ui {
class ParametersWidget;
}

class ParametersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersWidget(QWidget *parent = nullptr);
    ~ParametersWidget();


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
    class QSettings* settings;
};

#endif // PARAMETERSWIDGET_H
