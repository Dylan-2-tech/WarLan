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
    int _x, _y;

public:

    // Void Constructor just in case
    Pawn(); 

    // Constructor used by daugther class
    Pawn(int power, int hp, int moves, int prod, int cost); // Method to take hp from the called instance of this class

    void loseHp(int damage);

    // Display stats
    void display(void);

    // Set the position of a Pawn
    void setPosition(int toX, int toY);

    // Virtual methods that returns the character of the specific pawn
    virtual void getChar() = 0;
};

// Daugther class Castle of Pawn
class Castle: public Pawn{
public:

    // Castle Constructor using Pawn Constructor
    Castle(void);

    // override getChar to display his character
    void getChar() override;
};

// Daugther class Warrior of Pawn
class Warrior: public Pawn{
public:

    // Warrior Constructor using Pawn Constructor
    Warrior(void);

    // override getChar to display his character
    void getChar() override;
};

// Daugther class Farmer of Pawn
class Farmer: public Pawn{
public:

    // Farmer Constructor using Pawn Constructor
    Farmer(void);

    // override getChar to display his character
    void getChar() override;
};

// Daugther class Lord of Pawn
class Lord: public Pawn{
public:

    // Lord Constructor using Pawn Constructor
    Lord(void);

    // override getChar to display his character
    void getChar() override;
};

#endif // PAWN_GAME_2727

