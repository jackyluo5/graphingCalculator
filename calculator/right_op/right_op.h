#ifndef RIGHT_OP_H
#define RIGHT_OP_H
#include <iostream>
#include "../../!inludes/Token/token.h"


class right_op: public Token
{
public:
    right_op(string op);

    //accessor
    string op();

    //virtuals
    int type();
    void print(ostream& outs);
    void info();
private:
    string _rop;
};

#endif // RIGHT_OP_H
