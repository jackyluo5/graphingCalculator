#ifndef RPN_H
#define RPN_H
#include "../../!inludes/Queue/queue_iterator_Copy.h"
#include "../../!inludes/Token/token.h"
#include "../../!inludes/Stack/stack_iterator_Copy.h"
#include "../../!inludes/Integer/integer.h"
#include "../../!inludes/Operator/operator.h"
#include "../../!inludes/Variable/variable.h"
#include "../../!inludes/function/function.h"
#include <cmath>

class RPN
{
public:
    RPN();
    RPN(Queue<Token*> Q);

    double evaluate(double value);
    //or
    double operator ()(double value);


private:
    Queue<Token*> _t;
};

#endif // RPN_H
