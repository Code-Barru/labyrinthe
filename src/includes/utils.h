#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <vector>

sf::RectangleShape draw_pixel(int x, int y, sf::Color& color, sf::RenderWindow& window);
void create_grid(sf::RenderWindow& window,std::vector<std::vector<int>> &maze,int maze_size);
void render_grid(sf::RenderWindow& window,std::vector<std::vector<int>> maze, int maze_size);
sf::Color random_color();

#endif