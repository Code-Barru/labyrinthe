#include <SFML/Graphics.hpp>

class Cell {
    private:
        sf::Color color;
        int value;

    public:
        Cell(sf::Color color, int value){
            this->color = color;
            this->value = value;
        }

        sf::Color get_color(){
            return this->color;
        }

        void set_color(sf::Color color){
            this->color = color;
        }

        int get_value(){
            return this->value;
        }

        void set_value(int value){
            this->value = value;
        }

        Cell(int value){
            this->value = value;
        }

        Cell(){
            
        }
};