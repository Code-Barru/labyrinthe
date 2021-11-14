#ifndef GRID_H
#define GRID_H

#include "../../Utils/include/utils.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <winuser.h>
#include <vector>
#include "Cell.h"

using std::vector;

class Grid {
    private:
        vector<vector<Cell>> maze;
    
    public:
        void init();

        vector<vector<Cell>> get_maze();
        void set_maze(vector<vector<Cell>> m);
};

#endif