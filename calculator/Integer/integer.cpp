#include "integer.h"

Integer::Integer():Token(1){
}
Integer::Integer(double num):Token(INTEGER)
{
    _num = num;
}
Integer::Integer(string num):Token(1)
{
    //converts string to double
    _num = stod(num);
}

double Integer::num(){
    return _num;
}

int Integer::type(){
    return INTEGER;
}
void Integer::print(ostream& outs){
    outs<<_num;
}
void Integer::info(){

}

