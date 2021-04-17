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
    class Iterator{
    public:
        friend class Queue;
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
            return &(_ptr->_item);
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
    Queue();
    Queue(const Queue<ITEM_TYPE>& copyThis);
    Queue& operator =(const Queue& other);
    ~Queue();


    ITEM_TYPE pop_back();
    node<ITEM_TYPE>* pop();
    node<ITEM_TYPE>* push(ITEM_TYPE i);

    Iterator End();
    Iterator Begin();

    ITEM_TYPE front();

    int get_size() const;
    bool empty() const;
    void print_queue() const;
    friend ostream& operator <<(ostream& outs, const Queue<ITEM_TYPE>& t);
private:
    node<ITEM_TYPE>* _head2;
    node<ITEM_TYPE>* _tail;
    int _size = 0;
};

template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(){
//    cout<<"base QUEUE ctor fired: "<<endl;
    _head2 = nullptr;
    _tail = nullptr;
}

template <typename ITEM_TYPE>
Queue<ITEM_TYPE>::Queue(const Queue<ITEM_TYPE>& copyThis){
    const bool debug = false;
    if(debug) cout<<"Queue COPY CTOR "<<endl;

    //create an empty list with head
    node<ITEM_TYPE>* copy = nullptr;
//    _head2 = nullptr;

    //copy size
    _size = copyThis._size;
    //set tail to new copied tail
    _tail = _copyList(copyThis._head2, copy);
    _head2 = copy;
}
template <typename ITEM_TYPE>
Queue<ITEM_TYPE>& Queue<ITEM_TYPE>::operator =(const Queue& other){
    const bool debug = false;
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
    const bool debug = false;
    if(debug) cout<<"Queue DTOR "<<endl;

    ClearList(_head2);
}

template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::pop_back(){
    assert(!empty());
    _size--;
    return remove_head(_head2);
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
typename Queue<ITEM_TYPE>::Iterator Queue<ITEM_TYPE>::End(){
//    assert(_tail != nullptr);
    return Iterator(nullptr);
}
template <typename ITEM_TYPE>
typename Queue<ITEM_TYPE>::Iterator Queue<ITEM_TYPE>::Begin(){
//    assert(_head2 != nullptr);
    return Iterator(_head2);
}

template <typename ITEM_TYPE>
ITEM_TYPE Queue<ITEM_TYPE>::front(){
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
