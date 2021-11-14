#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../../Grid/include/Cell.h"
#include <Windows.h>


using std::vector;


sf::RectangleShape draw_cell(int x, int y, Cell cell, sf::RenderWindow& window);
sf::Color random_color();
int higher_value(int x, int y, vector<vector<Cell>> &maze, int maze_size);
void render_grid(sf::RenderWindow &window, vector<vector<Cell>> &maze, int maze_size);
void update_grid_graphics(sf::RenderWindow &window, vector<vector<Cell>> &maze, int maze_size);

