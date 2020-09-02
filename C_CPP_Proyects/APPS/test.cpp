/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <list>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <time.h>  

typedef struct 
{
    uint8_t RED;
    uint8_t GREEN;
    uint8_t BLUE;
}RGB;

typedef struct
{
    char pixels;
    RGB  color;
}Block; // 4bytes

typedef struct
{
    std::list<Block> group; 
    uint32_t time; // 4 
}Frame;


std::list<Frame> sequence;


void call(void)
{
    Block* block    = new(Block);
    Frame* frame    = new(Frame);
    srand (time(NULL));
    uint8_t R,G,B;
    for(int i=0;i<10;i++)
    {
        R = rand() % 255;
        G = rand() % 255;
        B = rand() % 255;
        block->pixels   = 4;
        block->color    = RGB{R,G,B};
        frame->group.push_back(*block);
        R = rand() % 255;
        G = rand() % 255;
        B = rand() % 255;
        block->pixels   = 4;
        block->color    = RGB{R,G,B};
        frame->group.push_back(*block);

        frame->time     = 2000;
        sequence.push_back(*frame);

        for(auto &m:frame->group)
        {
            std::cout<< "i: "<< i<<" ";
            std::cout<< "pixels "<<(int)m.pixels << std::endl;
        }

        frame->group.clear();

    }
    
    delete (frame);
    delete (block);
}

int main()
{
    
    call();
    
    //for(auto &m:sequence)
    //{
    //    for(auto &n:m.block)
    //    {
    //        printf("%d(%d,%d,%d)\r\n",m.time,n.color.RED, n.color.GREEN, n.color.BLUE);
    //    }
    //    printf("------\r\n");
    //}

    
    
    
    return 0;
}
