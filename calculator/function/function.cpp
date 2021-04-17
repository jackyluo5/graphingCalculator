#include "function.h"

function::function():Token(FNC)
{

}
function::function(string fnc):Token(FNC)
{
    _fnc = fnc;
}

//accessor
string function::fnc(){
    return _fnc;
}

int function::prec(){
    //sin, return 11
    if(_fnc == "sin"){
        _prec = 11;
    }
    //cos, return 12
    if(_fnc == "cos"){
        _prec = 12;
    }
    if(_fnc == "tan"){
        _prec = 13;
    }
    return _prec;
}
//virtuals
int function::type(){
    return FNC;
}

void function::info(){

}
void function::print(ostream& outs){
    outs<<_fnc;
}
