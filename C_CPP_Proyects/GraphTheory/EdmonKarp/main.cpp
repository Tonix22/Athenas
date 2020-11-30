#include <iostream>
#include <queue>


typedef enum
{
    Black,
    White
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

#define grid_rows 6
#define y_size grid_rows

#define grid_cols 6
#define x_size grid_cols

#define IS_CANDIDATE() neighbour->capacity !=0 && neighbour!=V->parent && neighbour->visited == false && neighbour->color!=Black

#define REGISTER_CANDIDATE() neighbour->parent  = V;\
                             neighbour->visited = true;\
                             Neighborhood.push(neighbour);
        


Grid_Edge grid [grid_rows][grid_cols]=
{
    {Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White)},
    {Grid_Edge(White),Grid_Edge(Black),Grid_Edge(White),Grid_Edge(Black),Grid_Edge(White),Grid_Edge(Black)},
    {Grid_Edge(Black),Grid_Edge(Black),Grid_Edge(White),Grid_Edge(Black),Grid_Edge(Black),Grid_Edge(Black)},
    {Grid_Edge(White),Grid_Edge(Black),Grid_Edge(White),Grid_Edge(Black),Grid_Edge(White),Grid_Edge(Black)},
    {Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White)},
    {Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White),Grid_Edge(White)},
};

bool shore(int row,int col)
{
    if(row == (grid_rows-1) 
    || col == (grid_cols-1)
    || row == 0
    || col == 0)
    {
        return true;
    }
    return false;
}

void Explore_Neighborhood(Grid_Edge* V, std::queue<Grid_Edge*>& Neighborhood)
{
    Grid_Edge* neighbour;
    int next_x = (V->x)+1;
    int next_y = (V->y)+1;
    int prev_x = (V->x)-1;
    int prev_y = (V->y)-1;

    if(next_x != x_size )
    {
        neighbour = &(grid[V->y][next_x]);
        neighbour->coordinates(V->y,next_x);
        if(IS_CANDIDATE()){
            REGISTER_CANDIDATE();
        }
    }
    if(next_y != y_size )
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

bool Edmon_karp(void)
{
    Grid_Edge* V;
    Grid_Edge* T;
    std::queue<Grid_Edge*> Neighborhood;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            V = &(grid[i][j]);
            V->coordinates(i,j);
            if(V->color == Black)
            {
                V->capacity  = 1;
                Explore_Neighborhood(V,Neighborhood);
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
                        Explore_Neighborhood(T,Neighborhood);
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


int main(int argc, char const *argv[])
{
    Edmon_karp();
    return 0;
}
