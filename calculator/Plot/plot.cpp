#include "plot.h"

Plot::Plot()
{
    //store graph info*
    //tokenize equation string to infix queue
    //run infix through shunting_yard to get postfix
    //object to get postfix queue
}

Plot::Plot(graph_info* temp){
    _window = temp;
    tokenize tok(_window->_equation);
    Queue<Token*> infix = tok.get_tokens(_window->_equation);

    //shunting yard to get postfix
    Queue<Token*> postfix;
    shunting_yard shunt(infix);
    postfix = shunt.infixtopostfix(infix);

    //rpn ctor with postfix
    RPN hold(postfix);
    _rpn = hold;
}
Vector<sf::Vector2f> Plot::get_cords(graph_info* window){
    //tokenize
    //run shunting yard
    //rpn evaluate to get a y given a x
    //get screen coordinates
    //return a vector of screen coordinates

    //save points into screen_points
    Vector<sf::Vector2f> screen_points;

    //evaluate through rpn to get screen points
    double y;
    for(double i=window->_domainMIN; i<window->_domainMAX; i+=0.005){
        y = _rpn(i)*window->_ratio;
        //convert to screen
        screen_points.push_back(converttoscreen(i*window->_ratio,-y));
    }

    return screen_points;
}
sf::Vector2f Plot::converttoscreen(double screenx, double screeny){
    sf::Vector2f screenpoint(screenx, screeny);
    //gets a screen x and screen y
    screenpoint += sf::Vector2f(_window->_origin.x, _window->_origin.y);
    //return these coordinates in vector2f for get_cords
    return screenpoint;
}
