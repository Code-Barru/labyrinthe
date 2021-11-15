
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <winuser.h>
#include <vector>

#include "../Utils/include/utils.h"
#include "include/Cell.h"

using std::vector;
class Grid {

private:
    vector<vector<Cell>> maze;

public:

    Grid(){
    }

    void init();
    

    vector<vector<Cell>> get_maze(){
        return this->maze;
    }
    
    void set_maze(vector<vector<Cell>> m){
        this->maze = m;
    }
};


void Grid::init(){

    
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    int maze_size = 89;

    sf::RenderWindow window(
        sf::VideoMode(maze_size * 10, maze_size * 10),
        "Labyrinthe",
        sf::Style::Titlebar | sf::Style::Close | !sf::Style::Resize
    );

    window.setVerticalSyncEnabled(true);

    vector<vector<Cell>> maze;

    this->set_maze(maze);

    generate_maze(window,maze,maze_size,true);
    solve_maze(window, maze, maze_size);

    while(window.isOpen()){
        
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

    
    }
}