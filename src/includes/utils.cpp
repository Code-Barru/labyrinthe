#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>



sf::RectangleShape draw_pixel(int x, int y, sf::Color color, sf::RenderWindow& window){
    
    int coefficient = 10;

    sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(coefficient,coefficient));
    rectangle.setFillColor(color);
    rectangle.setPosition(x*coefficient,y*coefficient);

    window.draw(rectangle);
    return rectangle;
}

sf::Color random_color(){
    return sf::Color(rand() % 255,rand() % 255,rand() % 255);
}

void render_grid(sf::RenderWindow &window, std::vector<std::vector<int>> &maze, int maze_size){

    window.clear(sf::Color::White);
    
    sf::Color couleur;

    for(int i=0 ; i < maze_size ; i++){
        for (int j=0 ; j < maze_size ; j++){
            
            if (maze[i][j] == -1){
                couleur = sf::Color(0,0,0);
            }
            else {
                couleur = random_color();
            }
            
            draw_pixel(i,j,couleur,window);

        }
    }
    window.display();
}

void create_grid(sf::RenderWindow& window,std::vector<std::vector<int>> &maze, int maze_size){
    
    std::vector<int> wall;
    std::vector<int> line;

    for (int i=0 ; i < maze_size ; i++){
        wall.push_back(-1);

        if (i % 2 == 0)
            line.push_back(-1);
        else
            line.push_back(0);
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
            if (maze[i][j] != -1){
                maze[i][j] = tmp++;
                
            }
        }
    }

    maze[0][1] = 0;
    maze[maze_size-1][maze_size-2] = 0;

    render_grid(window,  maze, maze_size);

}

