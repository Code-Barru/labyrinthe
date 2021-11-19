#include "Grid/include/Grid.h"

int main()
{
    while(true){
        Grid* grid = new Grid();
        grid->init();

        delete grid;
    }

    
    return 0;
}