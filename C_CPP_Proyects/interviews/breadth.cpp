#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

typedef enum
{
    UP = 0,
    LEFT,
    DOWN,
    RIGHT
}AdjPos;

class Coord
{
    public:
    int x = 0;
    int y = 0;
    Coord()
    {
        x = 0;
        y = 0;
    }
    Coord(long unsigned int x,long unsigned int y)
    {
        this->x = x;
        this->y = y; 
    }
    Coord (const Coord& b) // constructor por copia
    {
        x = b.x;
        y = b.y;
    }
};

void clear_queue(std::queue<Coord> &q )
{
   std::queue<Coord> empty;
   std::swap( q, empty );
}

Coord adjecent(int j,Coord src,Coord limit)
{
    Coord dest; 
    if(j == UP) 
    {
        dest.y = max(src.y-1,1);
        dest.x = src.x;
    }
    else if(j == LEFT)
    {
        dest.y = src.y;
        dest.x = max(src.x-1,1);
    }
    else if(j == DOWN)
    {
        dest.y = min(src.y+1,limit.y);
        dest.x = src.x;
    }
    else if(j == RIGHT)
    {
        dest.y = src.y;
        dest.x = min(src.x+1,limit.x);
    }
    return dest;
}

vector<int> nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    
    Coord root;
    Coord explore;
    Coord limit = {A[0].size(),A.size()};
    queue<Coord> ways;
    vector<int> solutions;
    int label = -1;
    for(int i=0;i<B.size();i++)
    {
        root.y = B[i][0];
        root.x = B[i][1];
        if(A[root.y-1][root.x-1] != 1)
            A[root.y-1][root.x-1] = label; // label as explored

        ways.push(root);
        while(ways.empty()==false)
        {
            explore = ways.front();
            ways.pop();
            if(A[explore.y-1][explore.x-1] == 1)
            {
                //  manhathan distance
                int distance = abs(B[i][0]-explore.y)+abs(B[i][1]-explore.x);
                solutions.push_back(distance);
                clear_queue(ways);// clear queue
            }
            else
            {
                for(int j=0;j<4;j++)// check for posible ways
                {
                    Coord leaf = adjecent(j,explore,limit);
                    if(A[leaf.y-1][leaf.x-1]!= label)
                    {
                        ways.push(leaf);// enqueue
                        if(A[leaf.y-1][leaf.x-1] != 1)
                        {
                            A[leaf.y-1][leaf.x-1] = label;// add label
                        }else
                        {
                            break;
                        }
                    }
                }
            }

        }
        label--;
    }
    return solutions;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A {{0,0},{1,0}};
    vector<vector<int>> B {{1,1},{2,1},{1,2}};
    vector<int> res = nearestHotel(A,B);
    for(auto r : res)
    {
        cout<<r<<endl;
    }

    return 0;
}
