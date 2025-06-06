#ifndef MAP_GAME_1717
#define MAP_GAME_1717

#include <vector>
#include <memory>
#include "pawn.hpp"

#define DEFAULT_WIDTH 22 // 20 playable slots
#define DEFAULT_HEIGHT 22 // 20 playable slots

class Map{
private:
public:
    
    std::vector<std::vector<Pawn*>> _grid;  // Fast O(1) access grid
    std::vector<std::unique_ptr<Pawn>> _pawns;  // Owns all pawns (auto cleanup)

   
    // Constructor
    Map(void);

    // Displays the map
    void display(void);
   
    // Add a new pawn at (x, y)
    void AddPawn(char type, int x, int y);

    // Move a pawn from (fromX, fromY) to (toX, toY)
    bool MovePawn(Pawn p, int toX, int toY);

    // Get pawn at (x,y) (returns nullptr if empty)
    Pawn* GetPawnAt(int x, int y) const;

    // Remove a pawn from the map
    void RemovePawn(int x, int y);

    // Get the _grid
    std::vector<std::vector<Pawn*>> get_grid(void);

    // Get the _pawns
    std::vector<std::unique_ptr<Pawn>> get_pawns(void);
};


#endif // MAP_GAME_1717
