#include <iostream>
#include "animate.h"
using namespace std;



/*==================================================

 * CONTROLS: [LEFT KEY]: MOVE LEFT, [RIGHT KEY]: MOVE RIGHT, [UP KEY]: MOVE UP, [DOWN KEY]: MOVE DOWN
 *            [MOUSE]: move and click
 *           [NUM1]: SAVE, [NUM2]: LOAD, [NUM3]: clear, [ESC]: close
 * BOXES ON RIGHT:  SAVE BOX = [NUM1], LOAD BOX = [NUM2]
 *
 * FUNCTIONS: init, print, setAlive, kill, isAlive, countNeighbors, step, random, randomize, save, load,
 * CLASS: token(parent), integer(child), operator(child), function(chold), variable(child), left_op(child), right_op(child),
 *        GRAPH_INFO, RPN, SHUNTING YARD, TOKENIZE, ANIMATE, SIDEBAR, SYSTEM.
 *
 * SFML: Animate, Draw, update, render, ProccessEvents, FillShapes,
 *       sidebar, ShowShapes, Boxes
 * =================================================
 *
 * Process:
 *
 * I started with all the information I've built on classes, linked lists, queues, stacks, vectors, etc.
 * I started with creating a token class that would be able to read functions
 * With that, I created an RPN/SHUNTING YARD class that would be able to take in these token pointers
 *  and give me values. Shunting Yard takes in an infix queue and runs through all the way to RPN
 *  to give a postfix queue of token pointers.
 * With that, I was able to obtain graph points and convert those to screen coordinates in a form
 * of vector2f. This plot is accessible in the animate class where all the graphics are handled and
 * that is because everything is pointing to the graph_info class and its variables.
 * This allows the graphing to take place as a window, domain, amount of points, scale, ratio, origin are set
 * and it gives the vector2f points a clue where to plot.
 * From all this, I was able to graph functions based on the plot and how it runs through rpn/shunting_yard
 * and then I moved to the tokenizer.
 * This is where I allow the user to enter functions based on their free will to change the points on the
 * graph and enter any function they desire.
 * The window, sidebar, buttons, etc. are working in the interface of the program and putting everything together,
 * it works fine like how a graphing calculator should.
 */

int main()
{

    animate game;
    game.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}

