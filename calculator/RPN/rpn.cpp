#include "rpn.h"
#include <casetup.h>
#include <iostream>
#include <iomanip>
using namespace std;

RPN::RPN()
{

}
RPN::RPN(Queue<Token*> Q){
    _t = Q;
}

double RPN::evaluate(double value){
    //declare a stack
    //declare token pointer
    //call empty from queue
    //    while still full
    //    pop queue and assign to token pointer
    //  go into switch case, if variable, push variable into stack
    //                      if integer, push integer into stack
    //                      if operator, pop stack twice, assign it to variable
    //                                   perform operation of +, -, *, /
    // push the answer back into stack
    //after loop, return stack.pop

    //copy a queue to not alter main queue
    Queue<Token*> t = _t;

    Stack<double> store_value;
    Token* hold;

    double first;
    double second;
    double result = 0;

    //while it is not empty
    while(!t.empty()){
        hold = t.pop_back();
        switch(hold->type()){
        case VARIABLE:
            store_value.push_in(value);
            break;
        case INTEGER:
            store_value.push_in(static_cast<Integer*>(hold)->num());
            break;
        case OPERATOR:
            first = store_value.pop_back();
            second = store_value.pop_back();
            if("*" == static_cast<Operator*>(hold)->op()){
                result = first * second;
            }
            if("+" == static_cast<Operator*>(hold)->op()){
                result = first + second;
            }
            if("-" == static_cast<Operator*>(hold)->op()){
                result = first - second;
            }
            if("/" == static_cast<Operator*>(hold)->op()){
                result = second / first;//check order
            }
            if("^" == static_cast<Operator*>(hold)->op()){
                result = pow(second, first);
            }
            store_value.push_in(result);
            break;
        case FNC:
            if("sin" == static_cast<function*>(hold)->fnc()){
                first = store_value.pop_back();
                result = sin(first);
            }
            if("cos" == static_cast<function*>(hold)->fnc()){
                first = store_value.pop_back();
                result = cos(first);
            }
            if("tan" == static_cast<function*>(hold)->fnc()){
                first = store_value.pop_back();
                result = tan(first);
            }
            store_value.push_in(result);
            break;
        }
    }
//    cout<<"finished"<<endl;
//    store_value.print_stack();
    return store_value.pop_back();
}
double RPN::operator ()(double value){
    return evaluate(value);
}
