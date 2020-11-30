#include "EdmonKarp.h"

int row_size = 0;
int col_size = 0;

bool shore(int row,int col)
{
    if(row == (row_size-1) 
    || col == (col_size-1)
    || row == 0
    || col == 0)
    {
        return true;
    }
    return false;
}


void Explore_Neighborhood(Grid_Edge* V, std::queue<Grid_Edge*>& Neighborhood, Grid_Edge** grid)
{
    Grid_Edge* neighbour;
    int next_x = (V->x)+1;
    int next_y = (V->y)+1;
    int prev_x = (V->x)-1;
    int prev_y = (V->y)-1;

    if(next_x != col_size )
    {
        neighbour = &(grid[V->y][next_x]);
        neighbour->coordinates(V->y,next_x);
        if(IS_CANDIDATE()){
            REGISTER_CANDIDATE();
        }
    }
    if(next_y != row_size )
    {
        neighbour = &(grid[next_y][V->x]);
        neighbour->coordinates(next_y,V->x);
        if(IS_CANDIDATE()){
            REGISTER_CANDIDATE();
        }
    }
    if(prev_x >= 0 )
    {
        neighbour = &(grid[V->y][prev_x]);
        neighbour->coordinates(V->y,prev_x);
        if(IS_CANDIDATE()){
            REGISTER_CANDIDATE();
        }
    }
    if(prev_y >= 0)
    {
        neighbour = &(grid[prev_y][V->x]);
        neighbour->coordinates(prev_y,V->x);
        if(IS_CANDIDATE()){
            REGISTER_CANDIDATE();
        }
    }
}

bool Edmon_karp(Grid_Edge** grid,int ROWS, int COLS)
{
    Grid_Edge* V;
    Grid_Edge* T;
    std::queue<Grid_Edge*> Neighborhood;

    row_size = ROWS;
    col_size = COLS;
    
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            V = &(grid[i][j]);
            V->coordinates(i,j);
            if(V->color == Black)
            {
                V->capacity  = 1;
                Explore_Neighborhood(V,Neighborhood,grid);
                V->capacity = Neighborhood.size();
                if(V->capacity == 0 && !shore(V->y,V->x))
                {
                    return false;
                }
                while(V->capacity!=0 && !Neighborhood.empty())
                {
                    T = Neighborhood.front();
                    Neighborhood.pop();
                    if(!shore(T->y,T->x))
                    {
                        Explore_Neighborhood(T,Neighborhood,grid);
                    }
                    else
                    {
                        while(T!=V)
                        {
                            T->flow      = 1;
                            T->capacity  = 0;
                            T->visited   = false;
                            T = T->parent;
                        }
                        T->flow++;
                        T->capacity--;
                    }
                }
                //EMPTY QUEUE
                while (!Neighborhood.empty())
                {
                    V = Neighborhood.front();
                    while (V->visited == true) // clean backtracing
                    {
                        V->visited = false;
                        T = V->parent;
                        V = T;
                        T = NULL;
                    }
                    Neighborhood.pop();
                }
            }
            
        }
    }
    return true;
}
