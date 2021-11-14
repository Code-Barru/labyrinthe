#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../Grid/include/Cell.h"
#include <Windows.h>


using std::vector;


sf::RectangleShape draw_cell(int x, int y, Cell cell, sf::RenderWindow& window){
    
    int coefficient = 10;
    

    sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(coefficient,coefficient));
    rectangle.setFillColor(cell.get_color());
    rectangle.setPosition(x*coefficient,y*coefficient);

    window.draw(rectangle);
    return rectangle;
}

sf::Color random_color(){
    return sf::Color(rand() % 255,rand() % 128,rand() % 255);
}

int higher_value(int x, int y, vector<vector<Cell>> &maze, int maze_size){
    int nbX = 0;
    int nbY = 0;

    for (int i=0 ; i < maze_size ; i++){
        for (int j=0 ; j < maze_size ; j++){
            if (maze[i][j].get_value() == x){
                nbX++;
            } else if (maze[i][j].get_value() == y){
                nbY++;
            }
        }
    }

    if (nbX >= nbY)
        return x;
    
    return y;
}

void render_grid(sf::RenderWindow &window, vector<vector<Cell>> &maze, int maze_size){

    window.clear(sf::Color::White);
    
    sf::Color couleur;

    for(int i=0 ; i < maze_size ; i++){
        for (int j=0 ; j < maze_size ; j++){
            
            if (maze[i][j].get_value() == -1){
                maze[i][j].set_color(sf::Color(0,0,0));
            }
            else {
                maze[i][j].set_color(random_color());
            }
            draw_cell(i,j,maze[i][j],window);
        }
    }
    maze[0][1].set_color(sf::Color(0,255,0));
    draw_cell(0,1,maze[0][1],window);

    maze[maze_size-1][maze_size-2].set_color(sf::Color(255,0,0));
    draw_cell(maze_size-1,maze_size-2,maze[maze_size-1][maze_size-2],window);

    window.display();
}

void update_grid_graphics(sf::RenderWindow &window, vector<vector<Cell>> &maze, int maze_size){

    window.clear();

    for (int i = 0 ; i < maze_size ; i++){
        for (int j = 0 ; j < maze_size ; j++){
            draw_cell(i,j,maze[i][j],window);
        }
    }

    window.display();

}