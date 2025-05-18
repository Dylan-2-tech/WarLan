#include <cstdio>
#include <cstdlib>

#include "class/pawn.hpp"
#include "class/map.hpp"

int main (void) {

    Map * M = new Map();
    M->display();

    // Adding the pawn
    M->AddPawn('C', 2, 2);
    M->AddPawn('W', 2, 3);
    M->AddPawn('F', 3, 2);
    M->AddPawn('L', 3, 3);
    
    M-> display();

    return 0;
}
