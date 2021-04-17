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
    class Iterator{
    public:
        friend class Stack;
        Iterator(){             //default ctor
            _ptr = nullptr;
        }
        Iterator(node<ITEM_TYPE>* p){      //Point Iterator to where p is pointing to
            _ptr = p;
        }
        operator bool();

        ITEM_TYPE& operator *(){                        //dereference operator
            assert(_ptr);
            return _ptr->_item;
        }
        const ITEM_TYPE& operator *()const{             //dereference operator const
            assert(_ptr);
            return _ptr->_item;
        }
        ITEM_TYPE* operator ->(){                       //member access operator
            assert(_ptr);
            return _ptr;
        }
        const ITEM_TYPE* operator ->()const{
            assert(_ptr);
            return _ptr;
        }

        bool is_null(){                                 //true if _ptr is NULL
            if(_ptr == nullptr){return true;}
            return false;
        }

        friend bool operator !=(const Iterator& left, //true if left != right
                                const Iterator& right){
            return left._ptr != right._ptr;
        }

        friend bool operator ==(const Iterator& left, //true if left == right
                                const Iterator& right){
            return left._ptr == right._ptr;
        }

        Iterator& operator++(){          //member operator: ++it; or ++it = new_value
            _ptr = _ptr->next;
            return *this;
        }

        friend Iterator operator++(Iterator& it,         //friend operator: it++
                                   int unused){
            Iterator hold;
            hold = it;
            ++it;
            return hold;
        }

    private:
        node<ITEM_TYPE>* _ptr;                         //pointer being encapsulated
    };
    Stack();
    //BIG 3
    Stack(const Stack<ITEM_TYPE>& copyThis);
    Stack& operator =(const Stack& other);
    ~Stack();

    ITEM_TYPE pop_back();
    node<ITEM_TYPE>* pop_out();
    node<ITEM_TYPE>* push_in(ITEM_TYPE i);

    ITEM_TYPE tops();
    Iterator top(); //returns top
    Iterator bottom();  //returns bottom
    bool empty() const;   //checks if empty

    void print_stack() const;
private:
    node<ITEM_TYPE>* _head;
    node<ITEM_TYPE>* _rear;
    int _size = 0;
};

template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(){
//    cout<<"base STACK CTOR fired "<<endl;
    _head = nullptr;
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::Stack(const Stack<ITEM_TYPE>& copyThis){
    const bool debug = false;
    if(debug) cout<<"Stack COPY CTOR "<<endl;

    _size = copyThis._size;
    _head = CopyList(copyThis._head);
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>& Stack<ITEM_TYPE>::operator =(const Stack& other){
    const bool debug = false;
    if(debug) cout<<"stack ASSIGNMENT Operator "<<endl;

    _size = other._size;
    _head = CopyList(other._head);
    return *this;
}
template <typename ITEM_TYPE>
Stack<ITEM_TYPE>::~Stack(){
    const bool debug = false;
    if(debug) cout<<"stack DTOR "<<endl;

    ClearList(_head);
}

template <typename ITEM_TYPE>
ITEM_TYPE Stack<ITEM_TYPE>::pop_back(){
    assert(_head != nullptr);
    _size--;
    return remove_head(_head);
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
ITEM_TYPE Stack<ITEM_TYPE>::tops(){
    assert(_head != nullptr);
    return _head->_item;
}

template <typename ITEM_TYPE>
typename Stack<ITEM_TYPE>::Iterator Stack<ITEM_TYPE>::top(){
    return Iterator(_head);
}

template <typename ITEM_TYPE>
typename Stack<ITEM_TYPE>::Iterator Stack<ITEM_TYPE>::bottom(){
    return Iterator(nullptr);
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

