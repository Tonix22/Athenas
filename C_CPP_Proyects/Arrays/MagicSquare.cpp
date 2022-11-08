#include <bits/stdc++.h>
#include <cmath>
#include <algorithm> 
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

bool sum_validate(vector<vector<int>>& s,int& distance,int idx)
{
    int vertical   = 0;
    int horizontal = 0;
    int diag = 0;
    bool cond = false;
    int col = idx%3;
    int row = idx/3;

    for(int i=0; i < 3;i++)
    {
        vertical+= s[(row+i)%3][col];
    }
    for(int i=0;i<3;i++)
    {
        horizontal+= s[row][(col+i)%3];
    }

    if(idx == 0 || idx == 2 || idx == 6 || idx == 8)
    {
        if(idx == 0 || idx == 8)
        {
            diag = s[0][0]+s[1][1]+s[2][2];
        }
        if(idx == 2 || idx == 6)
        {
            diag = s[0][2]+s[1][1]+s[2][0];
        }
        cond = vertical!=15 && horizontal!=15 && diag != 15;
    }
    else // 1,3,5,7
    {
        cond = vertical!=15 && horizontal!=15;
    }
    if(cond)
    {
        int min_distance = INT_MAX;
        min_distance = min(min_distance,15-vertical);
        min_distance = min(min_distance,15-horizontal);
        min_distance = min(min_distance,15-diag);
        s[row][col]  += min_distance;
        distance +=abs(min_distance);
    }
    return cond;

}

int formingMagicSquare(vector<vector<int>> s) {
    
    int distance = 0;
    int idx = 0;
    
    //base case
    if(s[1][1]!=5)
    {
        distance += abs(5-s[1][1]);
        s[1][1] = 5;
    }
    
    //First step
    while(idx <= 8)
    {
        sum_validate(s,distance,idx++);
    }
    
    return distance;

}

int main()
{
   
    vector<vector<int>> s={{4,5,8},{2,4,1},{1,9,7}};
    //14

    int result = formingMagicSquare(s);

    cout << result << "\n";

    return 0;
}