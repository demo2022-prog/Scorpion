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

private:
    std::vector<QString> styles;

private:
    void loadStyle();
    void setStyleSheet(int index);

private:
    Ui::ParametersWidget *ui;
};

#endif // PARAMETERSWIDGET_H
