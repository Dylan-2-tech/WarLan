#include "map.hpp"
#include <cstdio>

// Constructor
Map::Map(void): _dx(DEFAULT_DIM), _dy(DEFAULT_DIM){
    
    // Initialize the map borders
    for (int i = 0; i < _dx; i++){
        for (int j = 0; j < _dy; j++){
            if (i == 0 || i == _dx-1 || j == 0 || j == _dy-1)
                _grid[i][j] = '#';
            else {
                _grid[i][j] = ' ';
            }
        }
    }
}

// Displays the map
void Map::display(void){
    for (int i = 0; i < _dx; i++){
        for (int j = 0; j < _dy; j++){
            printf("%c", _grid[i][j]);
        }
        printf("\n");
    }
}
