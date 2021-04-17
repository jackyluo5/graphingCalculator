#include "variable.h"


Variable::Variable():Token(3)
{

}
Variable::Variable(string var):Token(VARIABLE)
{
    _var = var;
}

string Variable::var(){
    return _var;
}

//virtuals
int Variable::type(){
    return VARIABLE;
}
void Variable::print(ostream& outs){
    outs<<_var;
}
void Variable::info(){

}
