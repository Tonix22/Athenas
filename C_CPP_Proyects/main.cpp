#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
#define Reverse (0)
using namespace std;
typedef vector<int>::iterator pvector_t;


int max_histogram(vector<int>* bars)
{
    stack <int> pos_saved;
    stack <int> val_saved;

    int max_area  = 0;
    int temp_area = 0;

    pvector_t it  = bars->begin();
    for(int i=0;i<bars->size();i++)
    {
        cout<<"*it  "<<*it <<endl;
        if(val_saved.empty() || *it > val_saved.top())
        {
            val_saved.push(*it);
            pos_saved.push(i);
            cout<<"val_saved.top: "<<val_saved.top()<<endl;
        }
        while(!val_saved.empty() && *it < val_saved.top())
        {
            cout<<"val_saved.top: "<<val_saved.top()<<endl;
            cout<<"pos_saved.top(): "<<pos_saved.top()<<endl;
            temp_area = val_saved.top()*(i-pos_saved.top()); 
            val_saved.pop();
            if(val_saved.empty())
            {
                val_saved.push(*it);
            }
            else
            {
                pos_saved.pop();
            }
            
            if(temp_area > max_area)
            {
                max_area = temp_area;
            }
        }
        it++;
    }
    return max_area;
}

int main(int argc, char const *argv[])
{
    /* code */

    #if Reverse
    vector<int> hist={5,4,3,2,1};
    #else
    vector<int> hist={1,2,1,3,4,3,1};
    #endif
    cout <<"max area: "<< max_histogram(&hist)<<endl;
    return 0;
}
