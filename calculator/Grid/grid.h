#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <iomanip>
#include <cassert>
#include "../../!inludes/Wall/wall.h"
#include "../../!inludes/Creature/creature.h"
#include "../../!inludes/Pred/pred.h"
#include "../../!inludes/prey/prey.h"
using namespace std;

class Grid
{
public:
    Grid();

    //big 3
    Grid(const Grid& other);
    Grid& operator=(const Grid& RHS);
    ~Grid();

    void print_grid();
    void fill_grid();
    void step();
    void move();
    void breed();
    void kill();

    int get_type(int i, int j);

    friend ostream& operator <<(ostream& outs, Grid& print_me);
private:
    Creature* _grid[MAX][MAX];
};

#endif // GRID_H
