#ifndef MAP_GAME_1717
#define MAP_GAME_1717

#define DEFAULT_DIM 22 // 20 playable slots

class Map{
private:
    char _grid[DEFAULT_DIM][DEFAULT_DIM];
    int _dx;
    int _dy;

public:
    
    // Constructor
    Map(void);

    // Displays the map
    void display(void);

    // Moves the current pawn
    void move(int x, int y);
};


#endif // MAP_GAME_1717
