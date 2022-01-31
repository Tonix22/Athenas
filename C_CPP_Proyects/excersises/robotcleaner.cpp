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

int   steps   = 0;
State state_x = FORWARD;
State state_y = FORWARD;

void whereIsMyStar(Grid& Board,Object& Robot, Object& Star){
    steps   = 0;
    state_x = FORWARD;
    state_y = FORWARD;
    
    while (Robot.x != Star.x && Robot.y != Star.y)
    {
        
        if(state_x == FORWARD)
        {
            Robot.x++;
        }
        else if(state_x == BACK)
        {
            Robot.x--;
        }
        if(Robot.x >= Board.x || Robot.x <= 0)
        {
            state_x = (State)(state_x^1);
        }
        if(state_y == FORWARD)
        {
            Robot.y++;
        }
        else if(state_y == BACK)
        {
            Robot.y--;
        }
        if(Robot.y >= Board. y ||  Robot.y <= 0)
        {
            state_y = (State)(state_x^1);
        }
        steps ++;
    }
    cout<<steps<<endl;
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
        cin>>g.x>>g.y>>bot.x>>bot.y>>star.x>>star.y;
        whereIsMyStar(g,bot,star);
        test_cases--;
    }
    return 0;
}

    