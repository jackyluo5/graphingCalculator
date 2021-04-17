#include "vector.h"
#include "../../!inludes/Vector/vector.h"
#include "../../!inludes/add_entry/add_entry.h"

template <typename T>
Vector<T>::Vector()
{
    const bool debug = true;
    if(debug) cout<<"Vector CTOR "<<endl;
    _error = 0;
    _size = 0;
    _capacity = 10;
    _v = new T[_capacity];
}
template <typename T>
Vector<T>::Vector(int capacity){
    _capacity = capacity;
}
template <typename T>
Vector<T>::Vector(const Vector& other){
    const bool debug = true;
    if(debug) cout<<"Vector COPY CTOR "<<endl;

    _error = other._error;
    _size = other._size;
    _capacity = other._capacity;
    _v = new T[_capacity];

    //shown in copy function
//    for(int i=0; i<other._size; i++){
//        _v[i] = other._v[i];
//    }
    copy(other);
}
template <typename T>
Vector<T>::~Vector(){
    const bool debug = true;
    if(debug) cout<<"~Vector DTOR() "<<endl;

    delete[] _v;
    _v = nullptr;
}
template <typename T>
Vector<T>& Vector<T>::operator =(const Vector<T>& rhs){
    const bool debug = true;
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
    _v = new int[_capacity];
    //5 return *this
    return *this;
}

template <typename T>
const T Vector<T>::operator [](const int index) const{

}
template <typename T>
T& Vector<T>::operator [](const int index){

}
//check for errors
template <typename T>
T& Vector<T>::at(int index){
    bool debug = true;
    if(debug) cout<<"Vector at(index) NON_CONST "<<endl;
    return _v[index];
}
template <typename T>
const T Vector<T>::at(int index) const{
    bool debug = true;
    if(debug) cout<<"Vector at(index) CONST "<<endl;
    return _v[index];
}
template <typename T>
T& Vector<T>::front() const{
    return _v[0];
}
template <typename T>
T& Vector<T>::back() const{
    return _v[_size-1];
}


//size and capacity functions
template <typename T>
void Vector<T>::set_size(int size){
    _size = size;
}
template <typename T>
void Vector<T>::set_capacity(int capacity){
    _capacity = capacity;
}
template <typename T>
int Vector<T>::capacity() const{
    return _capacity;
}
template <typename T>
int Vector<T>::size() const{
    return _size;
}

//push and pop functions
template <typename T>
Vector<T>& Vector<T>::operator +=(const T& item){
    push_back(item);
}
template <typename T>
void Vector<T>::copy(const Vector<T>& item){
    for(int i=0; i<item._size; i++){
        _v[i] = item._v[i];
    }
}
template <typename T>
void Vector<T>::push_back(T item){
    _v[_size] = item;
    _size++;

    //add entries
    if(_size == _capacity){
        add_entry(_v, item, _size, _capacity);
    }
}
template <typename T>
int Vector<T>::pop_back(){
    T hold = _v[_size-1];
    _size--;

    //remove entries from pop_back
    erase(hold);
//    remove_entry(_v, hold, _size, _capacity);
    return _v;  //prints the vector with removed element
}

//insert and erase
template <typename T>
void Vector<T>::insert(int insert_here, const T& insert_this){
    //wrong
    add_entry(_v, insert_this, insert_here, _capacity);
}
template <typename T>
void Vector<T>::erase(int erase_index){
    remove_entry(_v, erase_index, _size, _capacity);
}
template <typename T>
int Vector<T>::index_of(const T& item){
    search_entry(_v, item, _size);

}

template <typename T>
bool Vector<T>::empty() const{
    if(_size == 0){
        return true;
    }
    return false;
}

