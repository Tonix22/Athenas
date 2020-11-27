#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <limits.h>
#include <stdint.h>
#include "helper.h"

#define INF INT_MAX

int32_t Weights[5][5]=
{
    {0  , 3  , 8  , INF, -4 },
    {INF, 0  , INF, 1  , 7  },
    {INF, 4  , 0  , INF, INF},
    {2  , INF, -5 , 0  , INF},
    {INF, INF, INF, 6  , 0  }
};

void Floy_Marshal_I(int32_t* W, int ROWS, int COLS)
{
    int n = ROWS;
    CREATE_2D_ARR(D);
    D_eq_W();
    
    for(int k=0; k < n ; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }
    //PRINT_MATRIX(D);
    DESTROY_2D_ARR(D);
}

int main(int argc, char const *argv[])
{
    /* code */
    Floy_Marshal_I(Weights[0],5,5);
    return 0;
}
