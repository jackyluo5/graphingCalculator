#ifndef LEFT_OP_H
#define LEFT_OP_H
#include "../../!inludes/Token/token.h"
#include <iostream>
using namespace std;

class left_op: public Token
{
public:
    left_op(string op);

    //accessor
    string op();

    //virtuals
    int type();
    void print(ostream& outs);
    void info();
private:
    string _lop;
};

#endif // LEFT_OP_H
