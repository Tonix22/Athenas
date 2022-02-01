#include <iostream>
#include <string>
#include <stdint.h>

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
    FORWARD = 1,
    BACK = -1,
}State;

int     steps   = 0;
int32_t state_x = 1;
int32_t state_y = 1;

inline void whereIsMyStar(Grid& Board,Object& Robot, Object& Star){
    steps   = 0;
    state_x = 1;
    state_y = 1;

    while (Robot.x != Star.x && Robot.y != Star.y)
    {
        if(Robot.x >= Board.x || Robot.x <= 0)
        {
            state_x *=-1;
        }
        if(Robot.y >= Board. y ||  Robot.y <= 0)
        {
            state_y *=-1;
        }
        Robot.x+=state_x;
        Robot.y+=state_y;
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

    