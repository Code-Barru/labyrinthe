#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell {
    private:
        sf::Color color;
        int value;

    public:
        int x,y;
        Cell(int value);
        Cell();
        
        Cell(sf::Color color, int value);

        sf::Color get_color();
        void set_color(sf::Color color);

        int get_value();
        void set_value(int value);

        int getX();
        int getY();

        void setX(int x);
        void setY(int y);
};

#endif