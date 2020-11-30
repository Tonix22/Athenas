#include <iostream>
#include <chrono>
#include <algorithm> 
#include <vector> 
#include <ratio>
#include <ctime> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "EdmonKarp.h"
#include "helper.h"
#include "matplotlibcpp.h"


using namespace std::chrono; 
namespace plt = matplotlibcpp;

#define FRAMES 500

std::vector<float> Y_axis;
std::vector<int> X_axis;
std::chrono::duration<double, std::milli> it_ms; 

void Test_grid(int ROWS, int COLS)
{
    CREATE_2D_ARR(GRID);
    Node_Color rand_color ;
    int blacks = 0;
    int black_max = (ROWS*COLS)/3;
    int density = 0;
    int space = 4;

    for(int i=0;i<ROWS;i++)
    {
        for (int j = 0; j < COLS; j++)
        {   
            if(blacks <= black_max && density == 0)
            {
                rand_color = (Node_Color)(rand()&1);
                if(rand_color == Black)
                {
                    blacks++;
                    density++;
                }
            }
            else
            {
                rand_color = White;
                if(density > 0)
                {
                    density++;
                    density %=space;
                }
            }
            GRID[i][j] = Grid_Edge(rand_color);
        }
    }
    //PRINT_MATRIX(GRID);

    // Get starting timepoint 
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    start = std::chrono::system_clock::now(); 

    bool scape = Edmon_karp(GRID,ROWS,COLS);

    end = std::chrono::system_clock::now();

    std::chrono::duration<double, std::milli> fp_ms = end - start;
    it_ms+=fp_ms;
    
    //printf("scape: %d \r\n",scape);

    DESTROY_2D_ARR(GRID);
}



int main(int argc, char const *argv[])
{
    srand (time(NULL));

    for(int i=0;i<FRAMES;i++)
    {
        X_axis.push_back(i);
    }


    for(int i=1;i <= FRAMES;i++)
    {
        it_ms.zero();
        std::cout<<"Frame number: "<<i<<std::endl;
        for (int j = 1; j <= i; j++)
        {
            Test_grid(i,j);
        }
        std::cout << "Test_grid took " << it_ms.count() << " ms, " <<std::endl;
        Y_axis.push_back(it_ms.count());
    }
    
    plt::plot(X_axis, Y_axis);
    plt::show();


    return 0;
}
