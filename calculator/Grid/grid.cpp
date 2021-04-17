#include "grid.h"
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

Grid::Grid(){
    fill_grid();
}

//big 3
Grid::Grid(const Grid& other){
    cout<<"grid copy ctor fired: "<<endl;
}
Grid& Grid::operator=(const Grid& RHS){
    cout<<"grid assignment fired: "<<endl;
}
Grid::~Grid(){
    cout<<"grid dtor fired: "<<endl;
}

void Grid::print_grid(){
    for(int i=0; i<MAX; i++){
        cout<<"|"<<endl;
        for(int j=0; j<MAX; j++){
            if(_grid[i][j] == nullptr){
                cout<<"| "<<" "<<" ";
            }else{
                //printing walls by finding types
                if(_grid[i][j]->get_type() == WALL){
                    _grid[i][j]->print();
                }else if(_grid[i][j]->get_type() == PRED){
                    _grid[i][j]->print();
                }else if(_grid[i][j]->get_type() == PREY){
                    _grid[i][j]->print();
                }
            }
        }
    }
    cout<<"|"<<endl;
}
void Grid::fill_grid(){
    int row;
    int col;
    srand(time(0));
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //set everything to nullptr
            _grid[i][j] = nullptr;
            //declare walls
            if(i ==0 || i==21){
                _grid[i][j]= new Wall(i,j);
            }
            if(j==0 || j==21){
                _grid[i][j] = new Wall(i,j);
            }
        }
    }
    int amount = 0;
    int i, j;
    i = rand() % 20 ;
    j = rand() % 20 ;

    //declare random amount of prey
    while(amount != 100){
        while(_grid[i][j] != nullptr){
            i = rand() % 20 +1;
            j = rand() % 20 +1;
        }
        _grid[i][j] = new prey(i,j);
        amount ++;
    }
    amount = 0;
    //declare random amount of predators
    while(amount != 10){
        while(_grid[i][j] != nullptr){
            i = rand() % 20 +1;
            j = rand() % 20 +1;
        }
        _grid[i][j] = new Pred(i,j);
        amount ++;
    }
    //    //declare 3 predators
    //    _grid[10][10] = new Pred(10,10);
    //    _grid[10][11] = new Pred(10,11);
    //    _grid[10][12] = new Pred(10,12);

    //    //declare prey
    //    _grid[3][4] = new prey(3,4);
    //    _grid[17][19] = new prey(17,19);
    //    _grid[6][20] = new prey(6,20);
}
void Grid::step(){
    move();
    breed();
    kill();
}
void Grid::move(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(_grid[i][j] != nullptr){
                //make sure walls dont move
                if(_grid[i][j]->get_type() != WALL){
                    _grid[i][j]->move(_grid);
                }
            }
        }
    }
    //call set moved ----- resets move
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(_grid[i][j] != nullptr){
//                cout<<"set moved: "<<endl;
                _grid[i][j]->set_moved(false);
            }
        }
    }
}
void Grid::breed(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(_grid[i][j] != nullptr ){
                if(_grid[i][j]->get_type() == PREY || _grid[i][j]->get_type() == PRED){
                    _grid[i][j]->breed(_grid);
                }
            }
        }
    }
}
void Grid::kill(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            //kill only for predators
            if(_grid[i][j] != nullptr && _grid[i][j]->get_type() == PRED){
                _grid[i][j]->kill(_grid,i,j);
            }
        }
    }
}

ostream& operator <<(ostream& outs, Grid& print_me){
    for(int i=0; i<=MAX; i++){
        for(int j=0; j<=MAX; j++){
            if(print_me._grid[i][j] == nullptr){
                outs<<"[ "<<" "<<" ";
            }else{
                outs<<"] "<< "X" <<" ";
            }
        }
    }
    return outs;
}
int Grid::get_type(int i, int j){
    if(_grid[i][j] != nullptr){
        if(_grid[i][j]->get_type() == WALL){
            return WALL;
        }
        else if(_grid[i][j]->get_type() == PRED){
            return PRED;
        }
        else if(_grid[i][j]->get_type() == PREY){
            return PREY;
        }
    }else{
        return NULLPTR; //NULLPTR is set to int 4
    }
}
