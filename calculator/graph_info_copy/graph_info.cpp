#include "graph_info.h"

graph_info::graph_info()
{
    cout<<"graph info ctor FIRED "<<endl;
    _windowdimension = sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT);
    _origin = sf::Vector2f(WORK_PANEL/2, SCREEN_HEIGHT/2);

    _equation = "sin(x)+cos(x)^2+sin(200x)";

    _domainMIN = -10;
    _domainMAX = 10;

    otherX = 0.0;
    otherY = 0.0;

    _domain = sf::Vector2f(-10, 10);

    _points = 20;
    _grid_delta = WORK_PANEL/_domainMAX;

    _angle = 0;
    _scale = 10;
    _ratio = SCREEN_WIDTH/_points;
}
void graph_info::set_equation(string equation){
    _equation = equation;
}
void graph_info::set_domain(double min, double max){
    _domainMIN += min;
    _domainMAX += max;
}
void graph_info::set_origin(double moveX, double moveY){
    _origin += sf::Vector2f(moveX, moveY);
    otherX += 5.0;
    otherY += 5.0;
}
