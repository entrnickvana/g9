#ifndef G9_CONTROL_H
#define G9_CONTROL_H

#include <QWidget>
#include <iostream>
#include <thread>

class client;

namespace Ui {
class g9_control;
}

class g9_control : public QWidget
{
    Q_OBJECT

public:
    explicit g9_control(QWidget *parent = nullptr);
    ~g9_control();

    int lo_level;
    int mid_level;
    int hi_level;
    int g9_gui_connected;


private slots:
    void on_verticalSlider_sliderReleased();

    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_3_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_radioButton_toggled(bool checked);

private:
    Ui::g9_control* ui;

};

#endif // G9_CONTROL_H
