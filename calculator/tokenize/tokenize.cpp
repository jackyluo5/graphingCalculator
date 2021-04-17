#include "tokenize.h"

tokenize::tokenize()
{

}
tokenize::tokenize(string equation)
{
    _equate = equation;
}

Queue<Token*> tokenize::get_tokens(string equation){
    Queue<Token*> tokens;

    string temp = "";
    for(int i=0; i<equation.size(); i++){
        if(equation[i] == 's'){
            if(isdigit(equation[i-1])){
                tokens.push(new Operator("*"));
            }
            i++;
            if(equation[i] == 'i'){
                i++;
                if(equation[i] == 'n'){
                    tokens.push(new function("sin"));
                }
            }
        }
        if(equation[i] == 'c'){
            if(isdigit(equation[i-1])){
                tokens.push(new Operator("*"));
            }
            i++;
            if(equation[i] == 'o'){
                i++;
                if(equation[i] == 's'){
                    tokens.push(new function("cos"));
                }
            }
        }
        if(equation[i] == 't'){
            if(isdigit(equation[i-1])){
                tokens.push(new Operator("*"));
            }
            i++;
            if(equation[i] == 'a'){
                i++;
                if(equation[i] == 'n'){
                    tokens.push(new function("tan"));
                }
            }
        }
        if(equation[i] == '*'){
            tokens.push(new Operator("*"));
        }
        if(equation[i] == '/'){
            tokens.push(new Operator("/"));
        }
        if(equation[i] == '+'){
            tokens.push(new Operator("+"));
        }
        if(equation[i] == '-'){
            tokens.push(new Operator("-"));
        }
        if(equation[i] == '^'){
            tokens.push(new Operator("^"));
        }
        if(equation[i] == 'x'){
            if(isdigit(equation[i-1])){
                tokens.push(new Operator("*"));
            }
            tokens.push(new Variable("x"));
        }
        if(equation[i] == '('){
            tokens.push(new left_op("("));
        }
        if(equation[i] == ')'){
            tokens.push(new right_op(")"));
        }
//        if(equation[i] == '1'){
//            tokens.push(new Integer("1"));
//        }
//        if(equation[i] == '2'){
//            tokens.push(new Integer("2"));
//        }
//        if(equation[i] == '3'){
//            tokens.push(new Integer("3"));
//        }
//        if(equation[i] == '4'){
//            tokens.push(new Integer("4"));
//        }
//        if(equation[i] == '5'){
//            tokens.push(new Integer("5"));
//        }
//        if(equation[i] == '6'){
//            tokens.push(new Integer("6"));
//        }
//        if(equation[i] == '7'){
//            tokens.push(new Integer("7"));
//        }
//        if(equation[i] == '8'){
//            tokens.push(new Integer("8"));
//        }
//        if(equation[i] == '9'){
//            tokens.push(new Integer("9"));
//        }

        while(isdigit(equation[i]) && i<equation.length()){
            temp += equation[i];
            i++;
        }
        if(temp.length() > 0){
            tokens.push(new Integer(temp));
            temp.clear();
            i--;
        }
    }
    return tokens;
}
