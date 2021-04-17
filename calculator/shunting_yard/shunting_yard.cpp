#include "shunting_yard.h"

shunting_yard::shunting_yard()
{

}
shunting_yard::shunting_yard(Queue<Token*> t){
    t = _in;
}
Queue<Token*> shunting_yard::infixtopostfix(Queue<Token*> t){
    Stack<Token*> operators;    //stack of operators
    Queue<Token*> output; //queue of postfix
    Token* hold;

    //while infix queue is not empty
    while(!t.empty()){
        //check the front token
        hold = t.front();

        switch(hold->type()){
        case INTEGER:
            //push in new Integer into output queue of item popped
            output.push(t.pop_back());
//            output.print_queue();
            break;
        case VARIABLE:
            //push in new Variable into output queue of item popped
            output.push(t.pop_back());
//            output.print_queue();
            break;
        case LOP:
            operators.push_in(t.pop_back());
            break;
        case ROP:
            while(operators.tops()->type() != LOP){
                output.push(operators.pop_back());
            }
            if(operators.tops()->type() == LOP){
                hold = operators.pop_back();
            }
            //pop right paren
            t.pop_back();
            break;
        case OPERATOR:
            //while stack is not empty, infix prec is < stack prec, stack is not (
            while(!operators.empty() && operators.tops()->type() != LOP &&
                  static_cast<Operator*>(hold)->prec() <=
                  static_cast<Operator*>(operators.tops())->prec()
                  ){
                output.push(operators.pop_back());
            }

            operators.push_in(t.pop_back());
//            output.print_queue();
            break;
        case FNC:
            //push in new function into stack
            operators.push_in(t.pop_back());
            break;
        } //switch type
    } //while queue not empty

    //if stack is not empty, pop everything else from stack in
    while(!operators.empty()){
        hold = operators.pop_back();
        output.push(hold);
    }//while stack not empty
    return output;
}
