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

    // Positions
    int x, y;
}

// Constructor used by daugther class
Pawn::Pawn(int power, int hp, int moves, int prod, int cost): _power(power), _hp(hp), _moves(moves), _prod(prod), _cost(cost) {}

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



//~~~~~~~~~~~~~~~~~~~CASTLE METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Castle::Castle(void): Pawn(0, 20, 0, 2, 15){}

//~~~~~~~~~~~~~~~~~~~WARRIOR METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Warrior::Warrior(void): Pawn(5, 10, 3, 0, 10){}

//~~~~~~~~~~~~~~~~~~~FARMER METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Farmer::Farmer(void): Pawn(0, 1, 2, 5, 20){}

//~~~~~~~~~~~~~~~~~~~LORD METHODS~~~~~~~~~~~~~~~~~~~~~~~~~~
Lord::Lord(void): Pawn(3, 5, 1, 0, 10){}
