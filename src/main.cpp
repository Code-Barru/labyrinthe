#include "Grid/include/Grid.h"

int main()
{
    Grid* grid = new Grid();
    grid->init();

    delete grid;
    
    return 0;
}