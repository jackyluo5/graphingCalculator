#ifndef INTEGER_H
#define INTEGER_H
#include "../../!inludes/Token/token.h"
#include <iostream>
using namespace std;

class Integer: public Token
{
public:
    //ctors
    Integer();
    Integer(double num);
    Integer(string num);

    //accessor
    double num();

    //virtuals
    int type();
    void print(ostream& outs);
    void info();

private:
    double _num;
};

#endif // INTEGER_H
