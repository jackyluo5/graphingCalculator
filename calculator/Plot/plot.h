#ifndef PLOT_H
#define PLOT_H
//#include <SFML/Graphics.hpp>
#include "../../../../../OneDrive/Desktop/CS3A/!inludes/graph_info_copy/graph_info.h"
#include "../../!inludes/Token/token.h"
#include "../../!inludes/Stack/stack_iterator_Copy.h"
#include "../../!inludes/Integer/integer.h"
#include "../../!inludes/Operator/operator.h"
#include "../../!inludes/Variable/variable.h"
#include "../../!inludes/add_entry/add_entry.h"
#include "../../!inludes/Vector/vector.h"
#include "../../!inludes/RPN/rpn.h"
#include "../../!inludes/shunting_yard/shunting_yard.h"
#include "../../!inludes/tokenize/tokenize.h"

class Plot
{
public:
    Plot();
    Plot(graph_info* temp);

    Vector<sf::Vector2f> get_cords(graph_info* window);
    sf::Vector2f converttoscreen(double screenx, double screeny); //add screen width, screen height

private:
    Queue<Token*> _infix;
    RPN _rpn;
//    Queue<Token*> postfix;
    graph_info* _window;
};

#endif // PLOT_H
