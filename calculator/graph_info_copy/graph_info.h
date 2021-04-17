#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "constants.h"
using namespace std;

struct graph_info
{
public:
    graph_info();
    void set_domain(double min, double max);
    void set_origin(double moveX, double moveY);
    void set_equation(string equation);
    string _equation;

    sf::Vector2f _windowdimension;
    sf::Vector2f _origin;

    sf::Vector2f _grid_width;
    sf::Vector2f _grid_height;

    sf::Vector2f _domain;

    double otherX;
    double otherY;

    double _domainMIN;
    double _domainMAX;

    int _points;
    int _grid_delta;

    double _angle;
    double _scale;
    double _ratio;
};

#endif // GRAPH_INFO_H
