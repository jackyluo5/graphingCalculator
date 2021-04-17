#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../../!inludes/Queue/queue_iterator_Copy.h"
#include "../../!inludes/Token/token.h"
#include "../../!inludes/Stack/stack_iterator_Copy.h"
#include "../../!inludes/Integer/integer.h"
#include "../../!inludes/Operator/operator.h"
#include "../../!inludes/Variable/variable.h"
#include "../../!inludes/left_op/left_op.h"
#include "../../!inludes/right_op/right_op.h"
#include "../../!inludes/function/function.h"

#include <iostream>
using namespace std;

class shunting_yard
{
public:
    shunting_yard();
    shunting_yard(Queue<Token*> t);

    Queue<Token*> infixtopostfix(Queue<Token*> t);
private:
    Queue<Token*> _in;
};

#endif // SHUNTING_YARD_H
