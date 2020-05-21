
#include <bits/stdc++.h>
#include <stack>
using namespace std;

#ifdef Test0
#define R 3 
#define C 3 
#endif

#ifdef four
#define R 4 
#define C 4 
#endif


#ifdef Test1
#define R 3 
#define C 6 
#endif

void spiralPrint(int row, int col, int a[R][C]) 
{
    //iterators
    int i = 0;
    int j = 0;
    int k = -1;
    int l = 0;
    stack<int> invert;

    int limit_col = 0;
    int limit_row = 0;
    do
    {
        for(i = (k+1); i < (col-limit_col); i++)
        {
            cout<<a[l][i]<<",";
            invert.push(a[l][i]);
        }
        i--;
        for(j = (l+1); j < (row-limit_row) ; j++)
        {
            cout << a[j][i] << ",";
            invert.push(a[j][i]);
        }
        j--;
        if( l!=j )
        {
            for ( k = i-1 ; k >=limit_col ; k--)
            {
                cout << a[j][k] << ",";
                invert.push(a[j][k]);
            }
            k++;///k = 0

            for(l = j-1 ; l >= limit_row + 1  ;l--)
            {
                cout<< a[l][k] << ",";
                invert.push( a[l][k]);
            }
            l++;
            limit_col++;
            limit_row++;
        }

    }while( l!=j );

    cout<<endl<<"spiral inversa"<<endl;
    do
    {
        cout<<invert.top()<<",";//tomar el ultimo disco y anotarlo
        invert.pop();//sacarlo del tubo
    }while(!invert.empty());

}

int main(int argc, char const *argv[])
{
    
    #ifdef Test0
    int a[R][C]=
    {
        {1,2,3},//matrix[0]  sizeof =  3
        {4,5,6},//matrix[1]
        {7,8,9},//matrix[2]
    };
    #endif
    
    #ifdef four
    int a[R][C]=
    {
        {0,  1,  2,  3  },
        {4,  5,  6,  7  },
        {8,  9,  10, 11 },
        {12, 13, 14, 15 },
    };
    #endif
    
    #ifdef Test1
     int a[R][C] = { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 }}; 
    #endif

    spiralPrint(R, C, a); 
    return 0;
}
