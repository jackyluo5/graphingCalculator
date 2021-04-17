#include "operator.h"

Operator::Operator():Token(2)
{

}
Operator::Operator(string op):Token(OPERATOR)
{
    _op = op;

}

int Operator::prec(){

    //exponent, return 3
    if(_op == "^"){
        _precedence = 3;
    }
    //mult, div, return 2
    if(_op == "*" || _op == "/"){
        _precedence = 2;
    }
    //add, sub, return 1
    if(_op == "+" || _op == "-"){
        _precedence = 1;
    }
    return _precedence;
}

string Operator::op(){
    return _op;
}
int Operator::get_prec(){
    return _precedence;
}

int Operator::type(){
    return OPERATOR;
}
void Operator::print(ostream& outs){
    outs<<_op;
}
void Operator::info(){

}
