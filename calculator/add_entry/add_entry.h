#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H

#include <iostream>

using namespace std;

template <typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);
template <typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);
template <typename T>
T* allocate(int capacity);
template <typename T>
void copy_list(T *dest, T* src, int many_to_copy);
template <typename T>
T* search_entry(T* list, const T& find_me, int size);
template <typename T>
T* append(T* arr, int& arr_size, T key);
template <typename T>
T shift_left(T* arr, int& size, T* shift_here);
template <typename T>
void init(T* arr, int size, T item);

template <typename T>
void print_list(T* list, int size);



template <typename T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity){

    //if full, cap*=2, allocate space for cap
    // copy all data to new array
    //add element to end
    //size++
    //return array

    T* p1= list;

    if(size == capacity){
        capacity*=2;
        T* temp = allocate<T>(capacity);
        copy_list(temp, list, size);

        //resets pointer for append
        p1 = temp;
        append(temp, size, new_entry);

        //this deletes list after everything is already copied over
        delete[] list;
    }
    else{
        append(p1,size,new_entry);

    }
    return p1;

}

template <typename T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity){
    //find element
    //shift left
    //reallocate array capacity if capacity is quarter of its size
    //copy items over to a
    T* p1 = list;
    T* item_ptr = search_entry(p1, delete_me, size);
    if (item_ptr != nullptr){
        shift_left(p1, size, item_ptr);
        if(size == capacity/4){
            int new_cap = capacity/2;
            T* temp = allocate<T>(new_cap);
            copy_list(temp, list, size);
            return temp;
        }
    }

    return list;
}

template <typename T>
T* allocate(int capacity){
    //create new capacity for dynamic array
    T* result = new T[capacity];
    return result;
}

template <typename T>
void copy_list(T *dest, T* src, int many_to_copy){
    T* p1;
    T* p2;

    p1 = src;
    p2 = dest;

    T temp;   //variable to copy over to dest array
    for(int i=0; i<many_to_copy; i++){
        temp = *p1;
        *p2 = temp;
        p1++;
        p2++;
    }
}

template <typename T>
T* search_entry(T* list, const T& find_me, int size){
    T* walker;
    walker = list;   //set pointer to beginning of array

    //search any array for a duplicate value
    //if it equals the value, return that value
    //else, keep incr through array
    //if no duplicate, return nullptr
    for(int i=0; i<size; i++){
        if(*walker != find_me){
            walker++;
        }
        else if(*walker == find_me){
            return walker;
        }
    }
    return nullptr;
}

template <typename T>
T* append(T* arr, int& arr_size, T key){
    T* walker = arr;

    //pointer is pointing at first address
    //if called, pointer moves according to size of &arr_size
    //&arr_size is referenced in main
    //increment after appended over
    walker += arr_size;
    *walker = key;
    arr_size++;
//    return walker;
}

template <typename T>
T shift_left(T* arr, int& size, T* shift_here){
    T* p1 = arr;
    //starts at the pointer where I want to shift
    //goes to the end of elements in array
    //shifts everything to the left
    //decr size
    for(T* i = shift_here; i<shift_here+size; i++){
        *i = *(i +1);
    }
    size--;
}
template <typename T>
void init(T* arr, int size, T item){
    T* p2 = arr;  //points to 0 position of array
    for (int i= 0; i<size; i++){
        *p2 = item;
        p2++;
    }
}

template <typename T>
void print_list(T* list, int size){
    T* p1 = list;
    for(int i=0; i<size; i++){
        cout<<*p1<<" "; //prints the value of the pointer
        p1++;
    }
    cout << endl;
}



#endif // ADD_ENTRY_H
