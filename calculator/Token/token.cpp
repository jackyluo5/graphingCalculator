#include "token.h"


Token::Token(){

}
Token::Token(int type){
    _type = type;
}

//virtuals
int Token::type(){
}
void Token::print(ostream& outs){
}
void Token::info(){
}

//osteram operator
ostream& operator <<(ostream& outs, const Token& t){
    outs<<t;
    return outs;
}
ostream& operator <<(ostream& outs, Token* t_ptr){
    t_ptr->print(outs);
    return outs;
}
