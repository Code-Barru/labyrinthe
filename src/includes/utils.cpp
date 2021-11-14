#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Cell.cpp"
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

bool is_finished(vector<vector<Cell>> &maze, int maze_size){

    int temp = maze[1][1].get_value();

    for (int i=1 ; i < maze_size - 1 ; i++) {
        for (int j=1 ; j < maze_size - 1 ; j++) {
            if (temp != maze[i][j].get_value() && maze[i][j].get_value() != -1) {
                return false;
            }
        }
    }

    return true;
}



void create_grid(sf::RenderWindow& window,vector<vector<Cell>> &maze, int maze_size){
    
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
}

void generate_maze(sf::RenderWindow& window,vector<vector<Cell>> &maze, int maze_size, bool complex){
    create_grid(window,maze,maze_size);
    render_grid(window,maze,maze_size);

    int loop_id=0;

    while(is_finished(maze,maze_size) == false){

        int x = rand() % (maze_size - 2) + 1;
        int y;

        if (x % 2 == 0)
            y = ((rand() % ((maze_size - 1 ) / 2 ))) * 2 + 1;
        else
            y = ((rand() % ((maze_size - 2 ) / 2 ))) * 2 + 2;

        Cell cell_1;
        Cell cell_2;
        Cell hCell;
        Cell lCell;

        if (maze[x - 1][y].get_value() == -1){

            cell_1 = maze[x][y - 1];
            cell_2 = maze[x][y + 1];
        }
        else {
            cell_1 = maze[x - 1][y];
            cell_2 = maze[x + 1][y];
        }

        if (cell_1.get_value() != cell_2.get_value()) {
            
            maze[x][y].set_value(cell_2.get_value());
            maze[x][y].set_color(cell_2.get_color());

            draw_cell(x, y, maze[x][y], window);

            if (higher_value(cell_1.get_value(), cell_2.get_value(), maze, maze_size) == cell_1.get_value() ){
                hCell.set_value(cell_1.get_value());
                hCell.set_color(cell_1.get_color());

                lCell.set_value(cell_2.get_value());
                lCell.set_color(cell_2.get_color());
            }
                
            else{
                hCell.set_value(cell_2.get_value());
                hCell.set_color(cell_2.get_color());

                lCell.set_value(cell_1.get_value());
                lCell.set_color(cell_1.get_color());
            }
                
            for (int i = 1; i < maze_size - 1 ; i++) {
                for (int j = 1 ; j < maze_size - 1 ; j++){
                    if(maze[i][j].get_value() == lCell.get_value()){

                        maze[i][j].set_value(hCell.get_value());    
                        maze[i][j].set_color(hCell.get_color());

                    } 
                }
            }

            update_grid_graphics(window,maze,maze_size);
        
        }
    }


    for (int i = 0 ; i < maze_size ; i++) {
        for (int j = 0 ; j < maze_size ; j++) {
            if ((i == 0 && j == 1) || (i == maze_size-1 && j == maze_size-2))
                continue;
                if (maze[i][j].get_value() != -1 )
                    maze[i][j].set_value(0);
                
        }
    }

    if (complex){

        for (int i = 0 ; i < maze_size ;i++){
            int x = rand() % (maze_size - 2) + 1;
            int y;

            if (x % 2 == 0)
                y = ((rand() % ((maze_size - 1 ) / 2 ))) * 2 + 1;
            else
                y = ((rand() % ((maze_size - 2 ) / 2 ))) * 2 + 2;
            
            maze[x][y].set_value(0);
            maze[x][y].set_color(maze[1][1].get_color());
        }

        update_grid_graphics(window,maze,maze_size);
    }
}