#include <iostream>
#include <string>
using namespace std;

/*spiral matrix
[
    [1,2,3] (´・ω・`)  <|:^{)
    [4,5,6]
    [7,8,9]

    /)/)
   ( '.')
   c(")(") chi cheñol DIA DEL PLATANO :3

   @..@
  (----)
 ( >__< )
 ^^ -- ^^
    You should return [1,2,3,6,9,8,7,4,5]

    Ruth: ¯\_(ツ)_/¯
    
    7-7
] 
*/ 
void print_spiral_matrix(char** matrix,int x_size,int y_size){
    
}
    /* 
    xi=0
    yi=0
    y=0
    x=0
    for y in range(y_size):
        matrix[xi][yi+y]  
    yi=y
    for x in range(x_size):
        matrix[xi+x][yi]  
    xi=x
    y=0
    for y in range(y_size):
        matrix[xi][yi-y]
    yi=y
    x=0
    for x in range(x_size-1):
        matrix[xi-x][yi]  
    xi=x
    y=0
    for y in range(y_size-1):
        matrix[xi][yi+y]  

    
    */

void printx(int** matrix, int x_start,int x_end, int y_col)
{
    if(x_start > x_end)
    {
        for(int x = x_start; x >= x_end; x--)
        {
        printf("%d",matrix[x][y_col]);
        }
    }
    else
    {
        for(int x = x_start; x <= x_end; x++)
        {
            printf("%d",matrix[x][y_col]);
        }
    }
    
}
void printy(int** matrix, int y_start, int y_end, int x_row)
{
    if(y_start > y_end){
        for(int y = y_start; y <= y_end; y--)
        {
            printf("%d",matrix[x_row][y]);
        }
    }
    else
    {
        for(int y = y_start; y <= y_end; y++)
        {
            printf("%d",matrix[x_row][y]);
        }
    }  
}
void spiral(int** matrix)
{
    printx(matrix, 0, 2, 0);
    printy(matrix, 1, 2, 2);
    printx(matrix, 1, 0, 1);
    printy(matrix, 0, 0, 1);
    printx(matrix, 1, 1, 1);
}
/*int 
func(imprimirint x, int inicio, int final)
for(int x=inicio; x< final;x++)
{
    ///todas las x
}


123
printy()
69
printx()
8,7
printy()
45

*/


void luigisAttempt(int** matrix){
    
    //Anyway, this a way to auto get x and y
    int x = sizeof(matrix[0])/sizeof(matrix[0][0]); // ... how the fuck do I do this? 	ლ(¯ロ¯"ლ)
    int y = sizeof(matrix)/sizeof(matrix[0]);

    int pos = 0;
    bool dir = true; //Whether I am i

    do{
        luigisFunc();
    }while(x < x/2 && y < y/2);
    
}
string luigisFunc(int** matrix, int start, int final, bool xDirection){
    
    string output = "";
    
    if(){
        for(int i=start; start<=final; start++){
            string += matrix[];
        }
    }else{
        
    }
    
    return output;
}

int main(int argc, char const *argv[])
{
    int matrix[3][3]=
    {
        {1,2,3},//matrix[0]  sizeof =  3
        {4,5,6},//matrix[1]
        {7,8,9},//matrix[2]
    };
    int size_of_matrix = sizeof(matrix)/sizeof(int);
    int rect[2][3]=
    {
        {1,2,3},
        {4,5,6},
    };//1,2,3,6,5,4
    int fourbyfoour[4][4]=
    {
        {0,4,8, 12 },
        {1,5,9, 13 },
        {2,6,10,14 },
        {3,7,11,15 },
    };

    spiral(*matrix);
    
    return 0;
}
