#include "map.hpp"
#include "pawn.hpp"

#include <cstdio>
#include <memory>  // For std::unique_ptr
#include <algorithm>

// Constructor: Initialize empty grid
Map::Map(void): _grid(DEFAULT_WIDTH, std::vector<Pawn*>(DEFAULT_HEIGHT, nullptr)){}

// Displays the map
void Map::display(void){
    for (int i = 0; i < DEFAULT_WIDTH; i++){
        for (int j = 0; j < DEFAULT_HEIGHT; j++){
            if (_grid[i][j])
                _grid[i][j] -> getChar();
            else if(i == 0 || j == 0 || i == DEFAULT_WIDTH - 1 || j == DEFAULT_HEIGHT - 1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

// Add a new pawn at (x, y)
void Map::AddPawn(char type, int x, int y) {

    // Checks if the positions (x, y) are inside the map
    if (x <= 1 || x > DEFAULT_WIDTH - 1 || y <= 1 || y > DEFAULT_HEIGHT - 1){
        printf("Position incorrect :");
        return;
    }

    // Create a pawn depending on it's type and add it to the the grid
    switch(type){

        case('C'):
            _pawns.push_back(std::make_unique<Castle>(x, y));
             // Store raw pointer in grid for fast access
            _grid[x][y] = _pawns.back().get();
            break;
   
        case('W'):
            _pawns.push_back(std::make_unique<Warrior>(x, y));
             // Store raw pointer in grid for fast access
            _grid[x][y] = _pawns.back().get();
            break;
   
        case('F'):
            _pawns.push_back(std::make_unique<Farmer>(x, y));
             // Store raw pointer in grid for fast access
            _grid[x][y] = _pawns.back().get();
            break;
   
        case('L'):
            _pawns.push_back(std::make_unique<Lord>(x, y));
             // Store raw pointer in grid for fast access
            _grid[x][y] = _pawns.back().get();
            break; 
    }

}

// Move a pawn from (fromX, fromY) to (toX, toY)
bool Map::MovePawn(Pawn* pawn, int toX, int toY) {
    // Check if the target cell is empty
    if (_grid[toX][toY] != nullptr) {
        return false;  // Move failed (cell occupied)
    }

    // Verify if the pawn can do the move tox and toy
    
    // get pawn positions
    int px=pawn._x, py=pawn._y;

    // Update grid
    _grid[toX][toY] = pawn;
    _grid[px][py] = nullptr;

    // Update pawn's internal position
    pawn->setPosition(toX, toY);

    return true;
}

// Get pawn at (x,y) (returns nullptr if empty)
Pawn* Map::GetPawnAt(int x, int y) const {
    return _grid[x][y];
}

// Remove a pawn from the map (e.g., when captured)
void Map::RemovePawn(int x, int y) {
    Pawn* pawn = _grid[x][y];
    if (!pawn) return;  // No pawn here

    // Find and erase the pawn from 'pawns_'
    auto it = std::find_if(
        _pawns.begin(), 
        _pawns.end(),
        [pawn](const std::unique_ptr<Pawn>& p) { return p.get() == pawn; }
    );
    
    if (it != _pawns.end()) {
        _pawns.erase(it);  // Automatic memory cleanup
    }

    // Clear grid pointer
    _grid[x][y] = nullptr;
}


// Get the _grid
std::vector<std::vector<Pawn*>> get_grid(void){
    return this -> _grid;
}

// Get the _pawns
std::vector<std::unique_ptr<Pawn>> get_pawns(void){
    return this -> _pawns;
}
