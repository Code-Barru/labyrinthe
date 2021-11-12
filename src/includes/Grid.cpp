#include "utils.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <winuser.h>

class Grid {

private:
    

public:
    std::vector<std::vector<int>> maze;

    void init();

    std::vector<std::vector<int>>& get_maze(){
        return maze;
    }

    void set_maze(std::vector<std::vector<int>> &m){
        maze = m;
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

    std::vector<std::vector<int>> maze0;
    
    
    create_grid(window,maze0,maze_size);

    this->maze = maze0;
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }
}