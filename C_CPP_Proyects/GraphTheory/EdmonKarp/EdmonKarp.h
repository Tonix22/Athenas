#ifndef EDMON_KARP_H
#define EDMON_KARP_H

#include <queue>

#define IS_CANDIDATE() neighbour->capacity !=0 && neighbour!=V->parent && neighbour->visited == false && neighbour->color!=Black

#define REGISTER_CANDIDATE() neighbour->parent  = V;\
                             neighbour->visited = true;\
                             Neighborhood.push(neighbour);
        

#define grid_rows 6
#define y_size grid_rows

#define grid_cols 6
#define x_size grid_cols



typedef enum
{
    White,
    Black
}Node_Color;

class Grid_Edge
{
    public:
        Grid_Edge(){}
        Grid_Edge(Node_Color Black_white)
        {
            this->color = Black_white;
        }
        Node_Color color;
        char capacity  = 1;
        char flow = 0;
        Grid_Edge* parent = NULL;
        bool visited      = false;
        int x = 0;
        int y = 0;
        void coordinates(int row,int col)
        {
            this->x = col;
            this->y = row;
        }
};

bool Edmon_karp(Grid_Edge** grid,int ROWS, int COLS);

#endif