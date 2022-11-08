#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
int matrixDiff(vector<vector<int>>& a, vector<vector<int>>& b);

int formingMagicSquare(vector<vector<int>>& s)
{
    int min_r = INT_MAX;
    vector<vector<int>> solution = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    for(int i = 0; i < 2; ++i)
    {
        for(int  j = 0; j < 4; ++j)
        {

            min_r = min(min_r, matrixDiff(solution, s));
        }
    }
}

void mirror(vector<vector<int>>& mat, int axis)
{
    vector<vector<int>> copy(mat.size(), vector<int>(mat.size(), 0));

    if(axis == 0)
    {
        copy[0] = mat[2];
        copy[1] = mat[1];
        copy[2] = mat[0];
    }
    else
    {
        copy[0][0] = mat[0][2];
        copy[1][0] = mat[1][2];
        copy[2][0] = mat[2][2];

        copy[0][2] = mat[0][0];
        copy[1][2] = mat[1][0];
        copy[2][2] = mat[2][0];

        copy[0][1] = mat[0][1]; 
        copy[1][1] = mat[1][1]; 
        copy[2][1] = mat[2][1];         
    }
    
}

void rotate(vector<vector<int>>& a)
{
    vector<vector<int>> copy(a.size(), vector<int>(0, a.size()));
    copy[0][0] = a[2][0];
    copy[0][1] = a[1][0];
    copy[0][2] = a[0][0];

    copy[0][2] = a[0][0];
    copy[1][2] = a[0][1];
    copy[2][2] = a[0][2];

    copy[2][2] = a[0][2];
    copy[2][1] = a[1][2];
    copy[2][0] = a[2][2];

    copy[2][0] = a[2][2];
    copy[1][0] = a[2][1];
    copy[0][0] = a[2][0];
    a = copy;
}

void printMat(vector<vector<int>> &m)
{
    for(vector<int> x : m)
    {
        for(int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int matrixDiff(vector<vector<int>>& a, vector<vector<int>>& b)
{
    int diff = 0;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            diff += abs(a[i][j] - b[i][j]);
        }
    }
}
    

int main(int argc, char const *argv[])
{
    vector<vector<int>> sq1 = {{4,9,2},{3,5,7},{8,1,4}};

    rotate(sq1);

    printMat(sq1);

    vector<vector<int>> sq2 = {{5,3,4},{1,5,8},{6,4,2}};
    return 0;
}
