#include "right_op.h"

right_op::right_op(string op):Token(ROP)
{
    _rop = op;
}

//accessor
string right_op::op(){
    return _rop;
}


//virtuals
int right_op::type(){
    return ROP;
}
void right_op::print(ostream& outs){
    outs<<_rop;
}
void right_op::info(){

}
