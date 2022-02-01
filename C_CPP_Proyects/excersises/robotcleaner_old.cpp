#include <iostream>
#include <string> 
using namespace std;

/*
PARAMETROS
Filas | Columnas | IPR Fila | IPR Columna | IPS Fila
  n        m            rb          cb
*/
typedef struct Grid_t{
    int x;
    int y;
}Grid;

typedef struct Object_t{
    int x;
    int y;
}Object;

typedef enum
{
    FORWARD,
    BACK,
}State;

bool checkCollision(Object *Robot, Grid* Board, char axis)
{
    if((Robot->x >= Board->x || Robot->x <= 0)  && axis=='X')
    {
        return true;
    }
    if((Robot->y >= Board-> y ||  Robot->y <= 0) && axis == 'Y')
    {
        return true;
    }
    return false;
}

int whereIsMyStar(Grid* Board,Object *Robot, Object* Star){
    int steps   = 0;
    State state_x = FORWARD;
    State state_y = FORWARD;
    
    while (Robot->x != Star->x && Robot->y != Star->y)
    {
        if(state_x == FORWARD)
        {
            Robot->x++;
            if(true == checkCollision(Robot, Board, 'X'))
            {
                state_x = BACK;
            }
        }
        else if(state_x == BACK)
        {
            Robot->x--;
            if(true == checkCollision(Robot, Board,'X'))
            {
                state_x = FORWARD;
            }
        }

        if(state_y == FORWARD)
        {
            Robot->y++;
            if(true == checkCollision(Robot, Board,'Y'))
            {
                state_y = BACK;
            }
        }
        else if(state_y == BACK)
        {
            Robot->y--;
            if(true == checkCollision(Robot, Board,'Y'))
            {
                state_y = FORWARD;
            }
        }
        steps ++;
    }
    return steps;
}

int main()
{
    int result;
    int test_cases = 0;
    Grid g      ; //= {10,10};
    Object bot  ; //= {9,9};
    Object star ; //= {1,1};
    cin>>test_cases;
    while(test_cases!=0)
    {
        scanf("%d %d %d %d %d %d",&g.x,&g.y,&bot.x,&bot.y,&star.x,&star.y);
        result = whereIsMyStar(&g,&bot,&star);
        cout<<result<<endl;
        test_cases--;
    }
    return 0;
}

    