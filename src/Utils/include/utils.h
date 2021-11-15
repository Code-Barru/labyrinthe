#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Grid/include/Cell.h"

using std::vector;


sf::RectangleShape draw_pixel(int x, int y, sf::Color& color, sf::RenderWindow& window);
sf::Color random_color();
void create_grid(sf::RenderWindow& window,vector<vector<Cell>> &maze,int maze_size);
void render_grid(sf::RenderWindow& window,vector<vector<Cell>> maze, int maze_size);
void generate_maze(sf::RenderWindow& window,vector<vector<Cell>> &maze, int maze_size, bool complex);
float distance(Cell cell_1, Cell cell_2);
void solve_maze(sf::RenderWindow &window, vector<vector<Cell>> &maze, int maze_size);


#endif