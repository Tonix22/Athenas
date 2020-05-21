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

void printx(int matrix[][3], int x_start,int x_end, int y_col)
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
void printy(int matrix[][3], int y_start, int y_end, int x_row)
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
void spiral(int array[][3])
{
    printx(array, 0, 2, 0);
    printy(array, 1, 2, 2);
    printx(array, 1, 0, 1);
    printy(array, 0, 0, 1);
    printx(array, 1, 1, 1);
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

/*************************************************************************/
string luigisAttempt(int** matrix){
    
    //Anyway, this a way to auto get x and y
    int xSize = sizeof(matrix[0])/sizeof(matrix[0][0]); // ... how the fuck do I do this? 	ლ(¯ロ¯"ლ)
    int ySize = sizeof(matrix)/sizeof(matrix[0]);

    int posx = 0;
    int posy = 0;
    bool dir = true; //Whether I am moving on X or Y

    string output="";

    do{
        if(dir && posx < xSize){

            for(int i=posx; i <= xSize; i++){
                
                output += matrix[posy][i];

            }

            dir = !dir;
            
        }
        else if(dir && posx >= xSize){

            for(int i=posx; i >= xSize-posx; i--){
                            
                output += matrix[posy][i];
                xSize-=1;

            }

            dir = !dir;

        }
        else if(dir && posy < ySize){

            for(int i=posy; i <= ySize; i++){
                
                output += matrix[i][posx];

            }

            dir = !dir;
            
        }
        else if(dir && posy >= ySize){

            for(int i=posy; i > ySize-posy; i--){
                            
                output += matrix[i][posx];
                ySize-=1;

            }

            dir = !dir;

        }
    }while(posx < xSize/2 && posy < ySize/2); //el DoWhile elimina la necesidad de hacer <=
    
    return output;

}
/*
string luigisFunc(int** matrix, int x, int y, bool direction){
    
    string output = "";
    
    if(direction && start<final){
        for(int i=start; start<=final; start++){
            //string += matrix[];
        }
    }else if(direction && start>final){
        
    }else{
        
    }
    
    return output;
}
*/
/*************************************************************************/

/*************************************************************************/
int main(int argc, char const *argv[])
{
    int matrix[][3]=
    {
        {1,2,3},//matrix[0]  sizeof =  3
        {4,5,6},//matrix[1]
        {7,8,9},//matrix[2]
    };
    int size_of_matrix = sizeof(matrix)/sizeof(int);
    int rect[][3]=
    {
        {1,2,3},
        {4,5,6},
    };//1,2,3,6,5,4
    int fourbyfoour[][4]=
    {
        {0,4,8, 12 },
        {1,5,9, 13 },
        {2,6,10,14 },
        {3,7,11,15 },
    };
    spiral(matrix);

    //Luigi's Attempt
    printf("%s", luigisAttempt(fourbyfoour**));
    
    return 0;
}
/*************************************************************************/