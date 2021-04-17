#ifndef FUNCTION_H
#define FUNCTION_H
#include "../../!inludes/Token/token.h"
#include <iostream>
using namespace std;


class function: public Token
{
public:
    //ctor
    function();
    function(string fnc);

    //accessor
    string fnc();

    //virtuals
    int type();
    void print(ostream& outs);
    void info();
    virtual int prec();


private:
    int _prec;
    string _fnc;
};

#endif // FUNCTION_H
