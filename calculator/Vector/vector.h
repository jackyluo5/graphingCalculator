#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include "../../!inludes/add_entry/add_entry.h"
using namespace std;

template <typename T>
class Vector
{
public:
    Vector(int capacity = 5);

    //the big 3 functions:
    Vector(const Vector& other); // copy constructor, allocates new space
    ~Vector();  //deconstructor
    Vector& operator =(const Vector& rhs);  //assignment operator

    //member access functions:
    const T operator [](const int index) const;
    T& operator [](const int index);
    T& at(int index);   //return reference to item at position index
    const T at(int index) const;  //return a const item at position index
    T& front() const;  //return item at position 0.
    T& back() const;  //return item at the last position

    //size and capacity
    void set_size(int size);   //enlarge the vector to this size
    void set_capacity(int capacity);   //allocate this space
    int capacity() const; //returns allocated space of elements
    int size() const; //returns the number of elements in space

    //push and pop functions
    Vector& operator +=(const T& item); //push_back
    void copy(const Vector& item);//copies elements into new allocated array
    void push_back(T item); //sets an item in a position
    T pop_back(); //removes an item from its position

    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_index);  //erase item at position
    int index_of(const T& item);  //search for item. retur index.

    //operators
    friend ostream& operator <<(ostream& outs, const Vector& print_me){
        const int WIDTH = 3;
        for(int i=0; i<print_me._size; i++){
            outs<<setw(WIDTH)<<print_me._v[i];
        }
        return outs;
    }

    bool empty() const;


private:
    int _error;
    int _size;
    int _capacity;
    T* _v;
};


/*
 * Function Definition:
 * arguments: capacity
 * returns: no return type, sets variables
 * notes:
 */
template <typename T>
Vector<T>::Vector(int capacity){
    _error = 0;
    _size = 0;
    _capacity = capacity;
    _v = allocate<T>(_capacity);

}
/*
 * Function Definition:
 * arguments:
 * returns:
 * notes: copy constructor
 *        declares all private variables
 *        allocates new array
 */
template <typename T>
Vector<T>::Vector(const Vector& other){
    const bool debug = false;
    if(debug) cout<<"Vector COPY CTOR "<<endl;

    _error = other._error;
    _size = other._size;
    _capacity = other._capacity;
    _v = allocate<T>(_capacity);

    //shown in copy function
//    for(int i=0; i<other._size; i++){
//        _v[i] = other._v[i];
//    }
    copy(other);
}
/*
 * Function Definition:
 * arguments:
 * returns:
 * notes: destructor
 *        self called when deallocate
 */
template <typename T>
Vector<T>::~Vector(){
    const bool debug = false;
    if(debug) cout<<"~Vector DTOR() "<<endl;

    delete[] _v;
    _v = nullptr;
}
/*
 * Function Definition:
 * arguments: const &rhs
 * returns: *this
 * notes: assignment operator
 */
template <typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& rhs){
    const bool debug = false;
    if(debug) cout<<"Vector ASSIGNMENT operator "<<endl;

    //1 self reference (later)
    //2 clean up the object
    if(_v != nullptr){
        delete[] _v;
    }
    //3, 4 copy and allocate space for dynamic data:
    _error = rhs._error;
    _size = rhs._size;
    _capacity = rhs._capacity;
    _v = allocate<T>(_capacity);
    for (int i= 0; i<_size; i++){
        _v[i] = rhs._v[i];
    }
    //5 return *this
    return *this;
}
/*
 * Function Definition:
 * arguments: const index
 * returns: value at index
 * notes: get or set variables traditional way
 *        select specific elements from the array
 *        passed a const, cannot alter the value in any way
 */
template <typename T>
const T Vector<T>::operator [](const int index) const{
    return _v[index];
}
/*
 * Function Definition:
 * arguments: const index
 * returns: value at index
 * notes: get or set variables traditional way
 *        select specific elements from the array
 */
template <typename T>
T& Vector<T>::operator [](const int index){
    return _v[index];
}
/*
 * Function Definition:
 * arguments:
 * returns: whatever index user gives
 * notes: for debugging purposes
 *        can easily change its value
 *         (not preferred)
 */
template <typename T>
T& Vector<T>::at(int index){
    bool debug = false;
    if(debug) cout<<"Vector at(index) NON_CONST "<<endl;
    return _v[index];
}
/*
 * Function Definition:
 * arguments:
 * returns: whatever index user gives
 * notes: for debugging purposes
 *        const and cannot be changed
 */
template <typename T>
const T Vector<T>::at(int index) const{
    bool debug = false;
    if(debug) cout<<"Vector at(index) CONST "<<endl;
    return _v[index];
}
/*
 * Function Definition:
 * arguments:
 * returns: first position in array
 * notes:
 */
template <typename T>
T& Vector<T>::front() const{
    return _v[0];
}
/*
 * Function Definition:
 * arguments:
 * returns: last position in array
 * notes:
 */
template <typename T>
T& Vector<T>::back() const{
    return _v[_size-1];
}
/*
 * Function Definition:
 * arguments: size
 * returns:
 * notes: size is being declared/changed
 *        able to change with member functions
 */
template <typename T>
void Vector<T>::set_size(int size){
    _size = size;
}
/*
 * Function Definition:
 * arguments: capacity
 * returns:
 * notes: _capacity is being declared/changed
 *        able to change with member functions
 */
template <typename T>
void Vector<T>::set_capacity(int capacity){
    _capacity = capacity;
}
/*
 * Function Definition:
 * arguments:
 * returns: _capacity
 * notes:
 */
template <typename T>
int Vector<T>::capacity() const{
    return _capacity;
}
/*
 * Function Definition:
 * arguments:
 * returns: _size
 * notes:
 */
template <typename T>
int Vector<T>::size() const{
    return _size;
}
/*
 * Function Definition:
 * arguments: const &item
 * returns: the full array
 * notes: operator for push_back
 *        adds element to last position in array
 */
template <typename T>
Vector<T>& Vector<T>::operator +=(const T& item){
    push_back(item);
    return *this;
}
/*
 * Function Definition:
 * arguments:const &item
 * returns:
 * notes: copies over elements when allocating new space
 */
template <typename T>
void Vector<T>::copy(const Vector<T>& item){
    for(int i=0; i<item._size; i++){
        _v[i] = item._v[i];
    }
}
/*
 * Function Definition:
 * arguments: item
 * returns: array with added element to end
 * notes: adds an element to last position
 */
template <typename T>
void Vector<T>::push_back(T item){
    _v = add_entry(_v, item, _size, _capacity);
    //test
    //_v[_size] = item;
//    _size++;
}
/*
 * Function Definition:
 * arguments:
 * returns: array with last value gone
 * notes: removes the very last element in array
 *        size always has to decrease
 */
template <typename T>
T Vector<T>::pop_back(){
    T hold = _v[_size-1];
    _size--;

//    remove_entry(_v, hold, _size, _capacity);
    return hold;  //prints the vector with removed element
}
/*
 * Function Definition:
 * arguments: insert_here, const T& insert_this
 * returns: returns the array with new element
 * notes: insert_here = position, insert_this = item
 *        puts an element into a position, even if
 *        there is an element there. Shifts everything
 *        over to the right
 */
template <typename T>
void Vector<T>::insert(int insert_here, const T& insert_this){
    //shifts right
    for(int i=_size; i>insert_here; i--){
        _v[i] = _v[i-1];
    }
    _v[insert_here] = insert_this;
    _size++;
}
/*
 * Function Definition:
 * arguments: erase_index
 * returns: an array with 1 less element
 * notes: takes an element out of its position
 *        and decreases the size of the array
 */
template <typename T>
void Vector<T>::erase(int erase_index){
    //shifts left
    for(int i=erase_index; i<_size -1; i++){
        _v[i] = _v[i+1];
    }
    _size--;

}
/*
 * Function Definition:
 * arguments: const T& item
 * returns: returns the location of element
 * notes: pointer is pointing at element,
 *        will find its position in search entry
 *        returns that specific index
 */
template <typename T>
int Vector<T>::index_of(const T& item){
    int* p1 = search_entry(_v, item, _size);
    return (p1 - _v);

    //test code
//    for(int i=0; i<_size; i++){
//        if(_v[i] == item){
//            return i;
//        }
//    }
//    return -1;
}
/*
 * Function Definition:
 * arguments: none
 * returns: checks if the array is empty
 * notes: will return true if empty
 */
template <typename T>
bool Vector<T>::empty() const{
    if(_size == 0){
        return true;
    }
    return false;
}



#endif // VECTOR_H
