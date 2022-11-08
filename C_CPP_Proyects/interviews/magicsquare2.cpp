#include <vector>
#include <cstdlib>
#include <limits>
#include <iostream>

using namespace std;

int diffMatrix(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    int result = 0;

    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = 0; j < a.size(); ++j)
        {
            result += abs(a[i][j] - b[i][j]);
        }
    }

    return result;
}


int formingMagicSquare(vector<vector<int>> s)
{
    vector<vector<vector<int>>> viii =
    {
        {
            { 8, 1, 6 },
            { 3, 5, 7 },
            { 4, 9, 2 }
        },
        {
            { 6, 1, 8 },
            { 7, 5, 3 },
            { 2, 9, 4 }
        },
        {
            { 4, 9, 2 },
            { 3, 5, 7 },
            { 8, 1, 6 }
        },
        {
            { 2, 9, 4 },
            { 7, 5, 3 },
            { 6, 1, 8 }
        },
        {
            { 8, 3, 4 },
            { 1, 5, 9 },
            { 6, 7, 2 }
        },
        {
            { 4, 3, 8 },
            { 9, 5, 1 },
            { 2, 7, 6 }
        },
        {
            { 6, 7, 2 },
            { 1, 5, 9 },
            { 8, 3, 4 }
        },
        {
            { 2, 7, 6 },
            { 9, 5, 1 },
            { 4, 3, 8 }
        }
    };

    int res = numeric_limits<int>::max();

    for (vector<vector<int>> x : viii)
    {
        res = min(res, diffMatrix(s, x));
    }

    return res;

}
int main(int argc, char const *argv[])
{
    vector<vector<int>> sq1 = {{4,9,2},{3,5,7},{8,1,4}};

    cout<<formingMagicSquare(sq1)<<endl;

    //printMat(sq1);

    vector<vector<int>> sq2 = {{5,3,4},{1,5,8},{6,4,2}};
    return 0;
}
