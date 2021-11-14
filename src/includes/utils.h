#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "cell.h"

using std::vector;

sf::RectangleShape draw_pixel(int x, int y, sf::Color& color, sf::RenderWindow& window);
sf::Color random_color();
void create_grid(sf::RenderWindow& window,vector<vector<Cell>> &maze,int maze_size);
void render_grid(sf::RenderWindow& window,vector<vector<Cell>> maze, int maze_size);
void generate_maze(sf::RenderWindow& window,vector<vector<Cell>> &maze, int maze_size, bool complex);

#endif