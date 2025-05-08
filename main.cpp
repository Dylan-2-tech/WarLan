#include <cstdio>
#include <cstdlib>

#include "class/pawn.hpp"
#include "class/map.hpp"

int main (void) {
    
    Pawn P;

    Castle * C = new Castle();

    Warrior * W = new Warrior();

    Farmer * F = new Farmer();

    Lord * L = new Lord();

    P.display();
    C->display();
    W->display();
    F->display();
    L->display();
   
    Map * M = new Map();

    M->display();

    return 0;
}
