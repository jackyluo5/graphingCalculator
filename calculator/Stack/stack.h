#ifndef STACK_H
#define STACK_H
#include <iomanip>
#include <cassert>
#include <iostream>
#include "../../!inludes/linked_list_functions/linked_list_functions.h"


template <typename ITEM_TYPE>
class Stack
{
public:
    Stack();
    //BIG 3
    Stack(const Stack<ITEM_TYPE>& copyThis);
    Stack& operator =(const Stack& other);
    ~Stack();

    node<ITEM_TYPE>* pop_out();
    node<ITEM_TYPE>* push_in(ITEM_TYPE i);

    ITEM_TYPE top(); //returns top
    bool empty() const;   //checks if empty

    void print_stack() const;
private:
    node<ITEM_TYPE>* _head;
    node<ITEM_TYPE>* _rear;
    int _size = 0;
};

template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(){
    _head = nullptr;
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(const Stack<ITEM_TYPE>& copyThis){
    const bool debug = true;
    if(debug) cout<<"Stack COPY CTOR "<<endl;

    _size = copyThis._size;
    _head = CopyList(copyThis._head);
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>& Stack<ITEM_TYPE>::operator =(const Stack& other){
    const bool debug = true;
    if(debug) cout<<"stack ASSIGNMENT Operator "<<endl;

    _size = other._size;
    _head = CopyList(other._head);
    return *this;
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::~Stack(){
    const bool debug = true;
    if(debug) cout<<"stack DTOR "<<endl;

    ClearList(_head);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* Stack<ITEM_TYPE>::pop_out(){
    //pop out at front
    if(empty()){
        return nullptr;
    }
    remove_head(_head);
    _size--;
//    cout<<_size;
    return _head;
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* Stack<ITEM_TYPE>::push_in(ITEM_TYPE i){
    //push in at front
    _size++;
//    cout<<_size;
    return _InsertHead(_head, i);
}

template <typename ITEM_TYPE>
void Stack<ITEM_TYPE>::print_stack() const{
    PrintList(_head);
}

template <typename ITEM_TYPE>
ITEM_TYPE Stack<ITEM_TYPE>::top(){

    return _head->_item;
}

template <typename ITEM_TYPE>
bool Stack<ITEM_TYPE>::empty() const{
    if(_size == 0){
//        cout<<"stack empty: "<<endl;
        return true;
    }
    return false;
}


#endif // STACK_H

