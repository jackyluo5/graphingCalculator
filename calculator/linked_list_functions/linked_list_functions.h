#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include "../../!inludes/node/node.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

//Linked List General Functions:
template <typename ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head);

template <typename ITEM_TYPE>
void PrintList_backwards(node<ITEM_TYPE> *head);            //recursive fun! :)

template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,          //return ptr to key or NULL
                            ITEM_TYPE key);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,         //insert at the head of list
                            ITEM_TYPE insertThis);

template <typename ITEM_TYPE>
ITEM_TYPE remove_head(node<ITEM_TYPE>*& head);         //remove at the head

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(node<ITEM_TYPE>*& head,        //insert after ptr
                             node<ITEM_TYPE> *afterThis,
                             ITEM_TYPE insertThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,       //insert before ptr
                              node<ITEM_TYPE>* beforeThis,
                              ITEM_TYPE insertThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head,        //ptr to previous node
                              node<ITEM_TYPE>* prevToThis);

template <typename ITEM_TYPE>
ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head,                 //delete, return item
                     node<ITEM_TYPE>* deleteThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head);           //duplicate the list...

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copyList(node<ITEM_TYPE>* head, node<ITEM_TYPE>*& copy);   //duplicate, but returns at end

template <typename ITEM_TYPE>
void ClearList(node<ITEM_TYPE>*& head);                     //delete all the nodes

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos);              //_item at this position

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &head,       //insert
                              ITEM_TYPE item,
                              bool ascending=true);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, //insert or add if a dup
                                      ITEM_TYPE item,
                                      bool ascending=true);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head,         //node after which this
                               ITEM_TYPE item,                //    item goes
                               bool ascending=true);          //order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _LastNode(node<ITEM_TYPE>* head);            //Last Node in the list

//test functions declaration
void test_insert();
void test_insertAfter();
void test_removehead();
void test_wherethisgoest();
void test_insertsorted();
void test_copy();



//Linked List General Functions:
template <typename ITEM_TYPE>
void PrintList(node<ITEM_TYPE>* head){
    node<ITEM_TYPE>* temp = head;
    while(temp != nullptr){
        cout<<"["<<temp->_item<<"]->"<<" ";
        temp = temp->next;
    }
    cout<<"NULL ";
}

template <typename ITEM_TYPE>
void PrintList_backwards(node<ITEM_TYPE> *head){
    node<ITEM_TYPE>* current = head;
    node<ITEM_TYPE>* next = nullptr;
    node<ITEM_TYPE>* prev = nullptr;
    while(current != nullptr){
        //store next
        next = current->next;
        //reverse current's node pointer to point at null
        current->next = prev;
        //increment pointers up one node
        prev = current;
        current = next;
    }
    //head is now at the end
    head = prev;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE key){
    node<ITEM_TYPE>* temp = head;
    while(temp != nullptr){
        if(temp->_item == key){
            return temp;
        }
        temp = temp->next;
    }
//    assert(false);
    return temp;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head, ITEM_TYPE insertThis){
    //create a new node
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);
    //point that node to wherever head is pointing to
    temp->next = head;
    //set temp item to inserted item
    //temp->_item = insertThis;
    //set head to point to new node
    head = temp;

    return head;
}
template <typename ITEM_TYPE>
ITEM_TYPE remove_head(node<ITEM_TYPE>*& head){
    //create new node
    node<ITEM_TYPE>* remove = head;
    ITEM_TYPE item = remove->_item;

    assert(head!=nullptr);
    //point head node to one over head
    head = head->next;
    //delete remove
    delete[] remove;
    //remove->next = nullptr;
    return item;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *afterThis, ITEM_TYPE insertThis){

    if(head == nullptr){
        _InsertHead(head, insertThis);
        return head;
    }
    return _InsertHead(afterThis->next, insertThis);
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);
    //store data into temp node
    //temp->_item = insertThis;
    //make next->temp node the  next->afterThis node
    temp->next = afterThis->next;
    //move next afterThis node to temp
    afterThis->next = temp;
    return temp;
}


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* beforeThis, ITEM_TYPE insertThis){
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);
    node<ITEM_TYPE>* before = PreviousNode(head, beforeThis);

    assert(beforeThis != nullptr);
    if(head == beforeThis){
        _InsertHead(head, insertThis);
        return head;
    }
    if(beforeThis == nullptr){
        return nullptr;
    }
    //store data into temp
    temp->_item = insertThis;
    //point next-> temp to the beforethis node
    temp->next = beforeThis;
    //point the previous node to temp
    before->next = temp;

    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* PreviousNode(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prevToThis){
    node<ITEM_TYPE>* check = head;

    assert(prevToThis != nullptr);

//    if(check == nullptr){
//        return nullptr;
//    }
    //checks if prevToThis is the first node
    if(prevToThis == head){
        return nullptr;
    }
    while(check != nullptr){
        if(check->next == prevToThis){
            return check;
        }
        check = check->next;
    }
    //check if prevToThis is not in list
//    assert(check != nullptr);
    assert(false);
    return check;
}

template <typename ITEM_TYPE>
ITEM_TYPE DeleteNode(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* deleteThis){

    node<ITEM_TYPE>* prev = PreviousNode(head, deleteThis);
//    node<ITEM_TYPE>* after = deleteThis->next;

//    if(head == nullptr){
//        return remove_head(head);
//    }
    //two cases. prev is null or not:
    if(head != nullptr && head == deleteThis){
        cout<<"test2: "<<endl;
        cout<<"deleting head: "<<head->_item<<endl;
        return remove_head(head);
    }
    else{
        cout<<"test: "<<endl;
        cout<<"item deleting: "<<deleteThis->_item<<endl;
        cout<<"actually deleting: "<<prev->next->_item<<endl;
        remove_head(deleteThis);
        prev->next = deleteThis;
    }

    return head->_item;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* CopyList(node<ITEM_TYPE>* head){
    node<ITEM_TYPE>* copyhead = nullptr; //new node<ITEM_TYPE>;  //decalres new node
//    copyhead = nullptr;
    node<ITEM_TYPE>* walkerCopy = copyhead;
    node<ITEM_TYPE>* walker = head; //point to head

    if(walker != nullptr){
        // inserts new node for head to point towards
        walkerCopy = _InsertHead(walkerCopy, walker->_item);
        copyhead = walkerCopy;
        // increments original head to get next item later
        walker = walker->next;
    }
    while(walker != nullptr){
        //insert item into copy node
        _InsertAfter(copyhead, walkerCopy, walker->_item);
        //increment new head
        walkerCopy = walkerCopy->next;
        //increment original head
        walker = walker->next;
    }
    return copyhead;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copyList(node<ITEM_TYPE>* head, node<ITEM_TYPE>*& copy){
    //make sure copy is pointing to nullptr
//    copy = nullptr;
    assert(copy == nullptr);

    node<ITEM_TYPE>* walker = head; //point to head
    node<ITEM_TYPE>* temp = nullptr;

    //run through list
    while(walker != nullptr){
        //insert item into copylist
        temp = _InsertAfter(copy, temp, walker->_item);
        //increment walker
        walker = walker->next;
    }
    return temp;
}

template <typename ITEM_TYPE>
void ClearList(node<ITEM_TYPE>*& head){
    node<ITEM_TYPE>* temp = head;
    node<ITEM_TYPE>* after;

    while(temp != nullptr){
        after = temp->next;
        delete temp;
        temp = after;
    }
    head = nullptr;
}

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos){
    node<ITEM_TYPE>* temp = head;
    int count = 0;

    while(temp != nullptr){
        if(count == pos){
            return temp->_item;
        }
        count++;
        temp = temp->next;
    }
    assert(0);
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted(node<ITEM_TYPE>* &head,  ITEM_TYPE item, bool ascending){
    node <ITEM_TYPE>*temp = WhereThisGoes(head, item, ascending);
    if(temp == nullptr){
        cout<<"---------------------------------test: "<<endl;
        _InsertHead(head, item);
        return head;
    }
    else{
//        cout<<"test2: "<<endl;
        //case if item is bigger than every element
        if(temp->next == nullptr){
            cout<<"biggest number"<<endl;
            _InsertAfter(head, temp, item);
            return temp->next;
        }
        //case if first node and is a copy
        if(temp == head){
            if(temp->_item == item){
                cout<<"number is same as head "<<endl;
                temp->_item = item;
                return temp;
            }
        }
        //case for regular copies
        if(temp->next->_item == item){
            cout<<"copy of item "<<endl;
            temp->next->_item = item;
            return temp->next;
        }
        //if not a copy, insert
        cout<<"not a copy of anything "<<endl;
        _InsertAfter(head, temp, item);
        return temp->next;
    }
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, //insert or add if a dup
                                      ITEM_TYPE item,
                                      bool ascending){
    node <ITEM_TYPE>*temp = WhereThisGoes(head, item, ascending);
//    if(temp == nullptr){
//        cout<<"=============================at nullptr: "<<endl;
//        _InsertHead(head, item);
//        return head;
//    }
//    if(item == temp->next->_item){
//        cout<<"insert sorted and add: "<<item<<endl;
//        temp->next->_item += item;
//        return temp;
//    }
//    else{
//        cout<<"=============================================here:"<<endl;
//        InsertSorted(head, item, ascending);
//        return head;
//    }

    if(temp == nullptr){
//        cout<<"=============================================here:"<<endl;
        _InsertHead(head, item);
        return head;
    }else{
        //case if item is bigger than every element
        if(temp->next == nullptr){
//            cout<<"biggest number"<<endl;
            _InsertAfter(head, temp, item);
            return temp->next;
        }
        //case if first node and is a copy
        if(temp == head){
            if(temp->_item == item){
//                cout<<"number is same as head "<<endl;
                temp->_item += item;
                return temp;
            }
        }
        //case for regular copies
        if(temp->next->_item == item){
//            cout<<"copy of item "<<endl;
            temp->next->_item += item;
            return temp->next;
        }
//        cout<<"not a copy of anything SORTED AND ADD"<<endl;
        _InsertAfter(head, temp, item);
        return temp->next;
    }
}


//assume list is sorted
template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending){
    if(head == nullptr){
        return nullptr;
    }
//    if(head->_item < item){
//        return nullptr;
//    }

    node<ITEM_TYPE>* prev = head;
    node<ITEM_TYPE>* lead = head->next;


    if(ascending){
        //if item is less than head->item
        if(item < head->_item){
            return nullptr;
        }
        while(lead != nullptr){
            if(item <= lead->_item && item >= prev->_item){
//                cout<<"check prev: "<<endl;
                return prev;
            }
            lead = lead->next;
            prev = prev->next;
        }
    }
    else{
        if(item > head->_item){
            return nullptr;
        }
        while(lead != nullptr){
            if(item >= lead->_item && item <= prev->_item){
                return prev;
            }
            lead = lead->next;
            prev = prev->next;
        }
    }
    //if item is bigger than everything
    return prev;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _LastNode(node<ITEM_TYPE>* head){
    node<ITEM_TYPE>* temp = head;
    if(temp == nullptr){
        return nullptr;
    }
    while(temp->next != nullptr){
        cout<<"last : "<<endl;
        temp = temp->next;
    }
    return temp;
}


//=============test functions definitions==================
//void test_wherethisgoest(){
//    node<int>* head = nullptr;
////    for(int i=10; i>0; i--){
////        head = _InsertHead(head, i*10);
////    }
//    for(int i=0; i<10; i++){
//        head = _InsertHead(head, i*10);
//    }
//    PrintList(head);

//    node<int>* hi = WhereThisGoes(head, 120, false);
//    cout<<"where this goes: "<<hi->_item<<endl;

//}
//void test_insertsorted(){
//    node<int>* head = nullptr;
//    //ascend
//    for(int i=10; i>0; i--){
//        head = _InsertHead(head, i*10);
//    }
//    //descend
////    for(int i=0; i<10; i++){
////        head = _InsertHead(head, i*10);
////    }

//    PrintList(head);
////    node<int>* test = InsertSorted(head, 101, true);
//    node<int>* test2 = InsertSorted_and_add(head, 102, true);
//    cout<<endl;
////    PrintList(test);
//    cout<<endl<<endl;
//    PrintList(test2);

//}



//void test_copy(){
//    node<int>* head = nullptr;
//    for(int i=10; i>0; i--){
//        head = _InsertHead(head, i*10);
//    }
//    PrintList(head);
//    CopyList(head);
//    cout<<endl<<endl<<"copied list: "<<endl;
//    PrintList(head);
//    _InsertAfter(head, head, 22);
//    cout<<endl<<endl<<endl;

//    PrintList(head);


//    node<int>* next = nullptr;
//    cout<<endl<<endl<<endl;
//    PrintList(next);
//    next = _copyList(head, next);
//    cout<<endl<<endl<<endl;
//    PrintList(next);
//    _InsertAfter(next, next, 30);
//    cout<<endl<<endl<<endl;

//    PrintList(next);
//}
//void test_insert(){
//    node<int>* head = nullptr;
//    cout<<"test insert HEAD: "<<endl;
////        InsertHead(head, 3);
////        InsertHead(head, 5);
////        InsertHead(head, 8);

//    for(int i=0; i<10; i++){
//        head = _InsertHead(head, i*10);
//    }
//    PrintList(head);


//    if(SearchList(head, 40)){
//        cout<<endl<<"40 is found"<<endl;
//    }
//    else{
//        cout<<endl<<"40 not found"<<endl;
//    }

//    cout<<endl<<"remove head: "<<endl;
//    remove_head(head);

//    PrintList(head);

//    cout<<endl<<"insert after: "<<endl;
//    InsertAfter(head, head->next, 9);

//    PrintList(head);


//    cout<<endl;

//}
//void test_insertAfter(){
//    node<int> * head = nullptr;
//    cout<<"test insert AFTER: "<<endl;
//    for(int i=0; i<10; i++){
//        head = _InsertHead(head, i*10);
//    }
//    PrintList(head);
//    cout<<endl;
//    _InsertAfter(head, head->next, 9);
//    cout<<endl;
//    PrintList(head);
//}
//void test_removehead(){
//    node<int> * head = nullptr;
//    cout<<"tet removed head: "<<endl;

//    for(int i=0; i<10; i++){
//        head = _InsertHead(head, i*10);
//    }
//    PrintList(head);

//    cout<<endl;
//    remove_head(head);
//    cout<<endl;
//    PrintList(head);
//}


#endif // LINKED_LIST_FUNCTIONS_H
