#include "pawn.hpp"
#include <cstdio>

//~~~~~~~~~~~~~~~~~~~PAWN METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~

// Void Constructor just in case
Pawn::Pawn(void){
    _power = 0;
    _hp = 0;
    _moves = 0;
    _prod = 0;
    _cost = 0;
}

// Constructor used by daugther class
Pawn::Pawn(int power, int hp, int moves, int prod, int cost, int x, int y): _power(power), _hp(hp), _moves(moves), _prod(prod), _cost(cost){
    setPosition(x,y);
}

// Method to take hp from the called instance of this class
void Pawn::loseHp(int damage){
    this -> _hp -= damage;
    if (this -> _hp < 0)
        this -> _hp = 0;
}

// Display stats
void Pawn::display(void){
    printf("p: %d, hp: %d, m: %d, pro: %d, cost: %d\n", _power, _hp, _moves, _prod, _cost);
}

void Pawn::setPosition(int toX, int toY){
    this -> _pos.x = toX;
    this -> _pos.y = toY;
}

// Get The position
Position Pawn::getPosition(void){
    return this -> _pos;
}


//~~~~~~~~~~~~~~~~~~~CASTLE METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Castle::Castle(int x, int y): Pawn(0, 20, 0, 2, 15, x, y){}

void Castle::getChar(void){
    /*
        * ESC[Text_colour;background_colourm output ESC[m
    */
    printf("\033[0;100mC\033[m");
}

//~~~~~~~~~~~~~~~~~~~WARRIOR METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Warrior::Warrior(int x, int y): Pawn(5, 10, 3, 0, 10, x, y){}

void Warrior::getChar(void){
    /*
        * ESC[Text_colour;background_colourm output ESC[m
    */
    printf("\033[0;41mW\033[m");
}

//~~~~~~~~~~~~~~~~~~~FARMER METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Farmer::Farmer(int x, int y): Pawn(0, 1, 2, 5, 20, x, y){}

void Farmer::getChar(void){
    /*
        * ESC[Text_colour;background_colourm output ESC[m
    */
    printf("\033[30;43mF\033[m");
}

//~~~~~~~~~~~~~~~~~~~LORD METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Lord::Lord(int x, int y): Pawn(3, 5, 1, 0, 10, x, y){}

void Lord::getChar(void){
    /*
        * ESC[Text_colour;background_colourm output ESC[m
    */
    printf("\033[30;107mL\033[m");
}
