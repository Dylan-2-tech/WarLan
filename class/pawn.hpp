#ifndef PAWN_GAME_2727
#define PAWN_GAME_2727

// Mother Class of Pawn
class Pawn{
private:

    int _power;
    int _hp;
    int _moves;
    int _prod;
    int _cost;

public:

    // Void Constructor just in case
    Pawn(void); 

    // Constructor used by daugther class
    Pawn(int power, int hp, int moves, int prod, int cost); // Method to take hp from the called instance of this class

    void loseHp(int damage);

    // Display stats
    void display(void); 
};

// Daugther class Castle of Pawn
class Castle: public Pawn{
public:

    // Castle Constructor using Pawn Constructor
    Castle(void);
};

// Daugther class Warrior of Pawn
class Warrior: public Pawn{
public:

    // Warrior Constructor using Pawn Constructor
    Warrior(void);
};

// Daugther class Farmer of Pawn
class Farmer: public Pawn{
public:

    // Farmer Constructor using Pawn Constructor
    Farmer(void);
};

// Daugther class Lord of Pawn
class Lord: public Pawn{
public:

    // Lord Constructor using Pawn Constructor
    Lord(void);
};
#endif // PAWN_GAME_2727

