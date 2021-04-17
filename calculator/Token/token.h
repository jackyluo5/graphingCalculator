#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

static const int TOKEN = 0;
static const int INTEGER = 1;
static const int OPERATOR = 2;
static const int VARIABLE = 3;
static const int LOP = 4;
static const int ROP = 5;

static const int FNC = 6;
//static const int COS = 7;
//static const int SIN = 8;
//static const int TAN = 9;



class Token
{
public:
    //ctors
    Token();
    Token(int type);

    //virtuals
    virtual int type();
    virtual void print(ostream& outs);
    virtual void info();

    //friend fnc
    //calls virtual print fnc
    friend ostream& operator <<(ostream& outs, const Token& t);
    friend ostream& operator <<(ostream& outs, Token* t_ptr);
private:
    int _type;
};

#endif // TOKEN_H
