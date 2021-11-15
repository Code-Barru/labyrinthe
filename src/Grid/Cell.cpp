#include <SFML/Graphics.hpp>
#include "include/Cell.h"

sf::Color Cell::get_color(){
    return this->color;
}

void Cell::set_color(sf::Color color){
    this->color = color;
}

int Cell::get_value(){
    return this->value;
}

void Cell::set_value(int value){
    this->value = value;
}

Cell::Cell(int value){
    this->value = value;
}

Cell::Cell(){
    
}

int Cell::getX(){
    return this->x;
}

int Cell::getY(){
    return this->y;
}

void Cell::setX(int x){
    this->x = x;
}

void Cell::setY(int y){
    this->y = y;
}