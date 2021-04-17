#ifndef VARIABLE_H
#define VARIABLE_H
#include "../../!inludes/Token/token.h"

#include <iostream>
using namespace std;


class Variable: public Token
{
public:
    Variable();
    Variable(string var);

    //accessor
    string var();

    //virtuals
    int type();
    void print(ostream& outs);
    void info();

private:
    string _var;
};

#endif // VARIABLE_H
