#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Cell.cpp"


sf::RectangleShape draw_cell(int x, int y, Cell cell, sf::RenderWindow& window){
    
    int coefficient = 10;

    sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(coefficient,coefficient));
    rectangle.setFillColor(cell.get_color());
    rectangle.setPosition(x*coefficient,y*coefficient);

    window.draw(rectangle);
    return rectangle;
}

sf::Color random_color(){
    return sf::Color(rand() % 255,rand() % 255,rand() % 255);
}

void render_grid(sf::RenderWindow &window, std::vector<std::vector<Cell>> &maze, int maze_size){

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
    window.display();
}

void create_grid(sf::RenderWindow& window,std::vector<std::vector<Cell>> &maze, int maze_size){
    
    std::vector<Cell> wall;
    std::vector<Cell> line;

    for (int i=0 ; i < maze_size ; i++){
        Cell temp(-1);
        Cell temp2(0);

        wall.push_back(temp);

        if (i % 2 == 0){
            temp2.set_value(-1);
            line.push_back(temp2);
        }
        else{
            temp2.set_value(0);
            line.push_back(temp2);
        }
            
    }

    for (int i=0 ; i < maze_size ; i++){
        if (i % 2 == 0)
            maze.push_back(wall);
        else
            maze.push_back(line);
    }

    int tmp = 0;

    for (int i=0 ; i < maze_size ; i++){
        for (int j=0 ; j < maze_size ; j++){
            if (maze[i][j].get_value() != -1){
                maze[i][j].set_value(tmp++);
                
            }
        }
    }

    maze[0][1].set_value(0);
    maze[maze_size-1][maze_size-2].set_value(0);

    render_grid(window,  maze, maze_size);

}

