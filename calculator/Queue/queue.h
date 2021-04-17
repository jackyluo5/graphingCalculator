#ifndef QUEUE_H
#define QUEUE_H
#include <iomanip>
#include <cassert>
#include <iostream>
#include "../../!inludes/linked_list_functions/linked_list_functions.h"

template <typename ITEM_TYPE>
class Queue
{
public:
    Queue();
    Queue(const Queue<ITEM_TYPE>& copyThis);
    Queue& operator =(const Queue& other);
    ~Queue();

    node<ITEM_TYPE>* pop();
    node<ITEM_TYPE>* push(ITEM_TYPE i);

    ITEM_TYPE get_rear();
    ITEM_TYPE get_head();


    int get_size() const;
    bool empty() const;
    void print_queue() const;
private:
    node<ITEM_TYPE>* _head2;
    node<ITEM_TYPE>* _tail;
    int _size = 0;
};

template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(){
    cout<<"ctor fired: "<<endl;
    _head2 = nullptr;
    _tail = nullptr;
}

template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(const Queue<ITEM_TYPE>& copyThis){
    const bool debug = true;
    if(debug) cout<<"Queue COPY CTOR "<<endl;

    //set tail to new copied tail
    _tail = _copyList(copyThis._head2, _head2);
    //set head to new copied head
    _size = copyThis._size;
}
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>& Queue<ITEM_TYPE>::operator =(const Queue& other){
    const bool debug = true;
    if(debug) cout<<"Queue ASSIGNMENT Operator "<<endl;
    //create new head
    node<ITEM_TYPE>* copy = nullptr;

    //move size with copy
    _size = other._size;
    //set head and tail to copied list pointers
    _tail = _copyList(other._head2, copy);
    _head2 = copy;
    return *this;
}
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::~Queue(){
    const bool debug = true;
    if(debug) cout<<"Queue DTOR "<<endl;

    ClearList(_head2);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* Queue<ITEM_TYPE>::pop(){
    //pops out at front
    if(empty()){
        return nullptr;
    }
    remove_head(_head2);
    _size--;
    return _head2;
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* Queue<ITEM_TYPE>::push(ITEM_TYPE i){
    //pushes element at end
    _tail = _InsertAfter(_head2, _tail, i);
    _size++;
    return _tail;
}

template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::get_rear(){
    assert(_tail != nullptr);
    return _tail->_item;
}
template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::get_head(){
    assert(_head2 != nullptr);
    return _head2->_item;
}

template <typename ITEM_TYPE>
void Queue<ITEM_TYPE>::print_queue() const{
    PrintList(_head2);
}

template <typename ITEM_TYPE>
bool Queue<ITEM_TYPE>::empty() const{
    if(_size ==0){
//        cout<<"queue empty: "<<endl;
        return true;
    }
    return false;
}

template <typename ITEM_TYPE>
int Queue<ITEM_TYPE>::get_size() const{
    return _size;
}
#endif // QUEUE_H
