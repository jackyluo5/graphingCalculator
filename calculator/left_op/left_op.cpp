#include "left_op.h"


left_op::left_op(string op):Token(LOP)
{
    _lop = op;
}

//accessor
string left_op::op(){
    return _lop;
}

//virtuals
int left_op::type(){
    return LOP;
}
void left_op::print(ostream& outs){
    outs<<_lop;
}
void left_op::info(){

}
