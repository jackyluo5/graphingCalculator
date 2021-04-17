#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "../../../../../OneDrive/Desktop/CS3A/!inludes/Plot/plot.h"

using namespace std;
class System
{
public:
    System();
    System(graph_info* test);
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& widnow);

private:
//    vector<Particle> system;

    sf::CircleShape shape;
    sf::Vector2f vel;
    graph_info* _test;
};

#endif // SYSTEM_H
