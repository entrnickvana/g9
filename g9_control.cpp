#include "g9_control.h"
#include "ui_g9_control.h"

g9_control::g9_control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::g9_control)
{
    ui->setupUi(this);
}

g9_control::~g9_control()
{
    delete ui;
}

void g9_control::on_verticalSlider_sliderReleased()
{}

void g9_control::on_verticalSlider_valueChanged(int value)
{    this->lo_level = value;    std::cout << "lo_level changed: " << lo_level << std::endl;  }

void g9_control::on_verticalSlider_3_valueChanged(int value)
{   this->mid_level = value;    std::cout << "mid_level changed: " << lo_level << std::endl; }

void g9_control::on_verticalSlider_2_valueChanged(int value)
{   this->hi_level = value;     std::cout << "hi_level changed: " << lo_level << std::endl; }
