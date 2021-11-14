#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell {
    private:
        sf::Color color;
        int value;

    public:
        Cell(sf::Color color, int value);

        sf::Color get_color();
        void set_color(sf::Color color);

        int get_value();
        void set_value(int value);

        Cell(int value);
        Cell();
};

#endif