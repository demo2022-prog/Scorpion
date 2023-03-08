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
    explicit ParametersWidget(QWidget *parent = nullptr);
    ~ParametersWidget();

private slots:
    void on_selectStyleBox_activated(int index);

private:
    std::vector<QString> styles;
    QSettings settings;

private:
    void loadStyle();
    void setStyleSheet(int index);

private:
    Ui::ParametersWidget *ui;
};

#endif // PARAMETERSWIDGET_H
