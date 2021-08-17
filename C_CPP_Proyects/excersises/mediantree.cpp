#include <list>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Node_mediantree
{
    int data;
    vector<Node_mediantree*> hijos;
};


int main(int argc, char const *argv[])
{
    set<Node_mediantree*> set1;

    struct Node_mediantree l_root {6,{NULL,NULL}};
    struct Node_mediantree l_ch1 {8,{NULL}};
    struct Node_mediantree l_ch2 {1,{NULL}};

    l_root.hijos.push_back(&l_ch1);
    l_root.hijos.push_back(&l_ch2);
    // ᶘ ᵒᴥᵒᶅ ñamñaramñaramñam ñam ñam ñam ñam!

    struct Node_mediantree r_root {4,{NULL,NULL,NULL}};
    struct Node_mediantree r_ch1 {2,{NULL}};
    struct Node_mediantree r_ch2 {3,{NULL}};
    struct Node_mediantree r_ch3 {9,{NULL}};
    struct Node_mediantree r_ch4 {7,{NULL}};

    r_root.hijos.push_back(&r_ch1);
    r_root.hijos.push_back(&r_ch2);
    r_root.hijos.push_back(&r_ch3);
    r_ch3.hijos.push_back(&r_ch4);

    for(){

    }

    
}