#ifndef TOKENIZE_H
#define TOKENIZE_H
#include <iostream>
//#include "../../../../../OneDrive/Desktop/CS3A/!inludes/graph_info_copy/graph_info.h"
#include "../../!inludes/Token/token.h"
#include "../../!inludes/Stack/stack_iterator_Copy.h"
#include "../../!inludes/Integer/integer.h"
#include "../../!inludes/Operator/operator.h"
#include "../../!inludes/Variable/variable.h"
#include "../../!inludes/add_entry/add_entry.h"
#include "../../!inludes/Vector/vector.h"
#include "../../!inludes/RPN/rpn.h"
#include "../../!inludes/shunting_yard/shunting_yard.h"
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <cstring>

using namespace std;

class tokenize: public Token
{
public:
    tokenize();
    tokenize(string equation);

    Queue<Token*> get_tokens(string equation);

private:
    Queue<Token*> _equation;
    string _equate;
};

#endif // TOKENIZE_H
