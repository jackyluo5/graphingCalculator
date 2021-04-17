#ifndef OPERATOR_H
#define OPERATOR_H
#include "../../!inludes/Token/token.h"

class Operator: public Token
{
public:
    //ctors
    Operator();
    Operator(string op);

    //accessor
    string op();
    int get_prec();

    //virtuals
    int type();
    void print(ostream& outs);
    void info();
    virtual int prec();

private:
    int _precedence;
    string _op;
};

#endif // OPERATOR_H
