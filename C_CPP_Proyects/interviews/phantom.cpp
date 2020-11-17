#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

int matrixElementsSum(std::vector<std::vector<int>>& matrix) {
    int sum = 0;
    for(auto& n:matrix)
    {
        auto first_zero = find (n.begin(), n.end(), 0);
        
        sum += std::accumulate(n.begin(),first_zero , 0);
    }
    cout<<"suma: "<<sum<<endl;
    return sum;
}

//Nombre debido a este meme https://bit.ly/2Zv2wo0
int puraCreenciaDeGentePendeja(vector<vector<int>>& hotel){

    /*
    int ySize=sizeof(hotel)/sizeof(hotel[0]);
    int xSize=sizeof(hotel[0])/sizeof(hotel[0][0]); //... how the fuck do I do this? 	ლ(¯ロ¯"ლ) --Ref: spiralmatrix.cpp
    */

    int ySize=hotel.size();
    int xSize=hotel[0].size();

    int total=0;
    //4*3 *4 = 48
    //4*4 = 16
    for(int x=0; x<xSize; x++){ //4 
        for(int y=0; y<ySize && hotel[y][x]!=0; y++){ // 3

            total+=hotel[y][x];

            /*
                0,1,1,2  Y = 0, X=0, zero = 0, 2
                0,5,0,0  [0]
                2,0,3,3  [0]
                         [0]

            */

            //cout << *x << ' ';
        }
    }

    return total;
}

int yaentendi_creo(vector<vector<int>>& matrix){
    
    int alto = matrix.size();
    printf("ALTO: %i\n",alto);
    int ancho = matrix[0].size();
    printf("ANCHO: %i\n",ancho);
    int sum = 0;
    
    for(int i=0; i<ancho; i++){
    
        for(int j=0; j<alto; j++){
            if(matrix[j][i] == 0)
                break;
            sum += matrix[j][i];
            printf("suma? = %i",sum);
        }
    }
    printf("\tSUMA = %i\n",sum);
    return sum;
    
}

/*
for(int i=0; i<alto; i++){
    
    for(int j=0; j<ancho; j++){
        if(matrix[j][i]==0)break;
        sum += matrix[j][i];
    }
}

    0,1,1,2
    0,5,0,0
    2,0,3,3
*/
int main(int argc, char const *argv[])
{


//1,3,1,
    std::vector<std::vector<int>> Room1
    {
        {0,0,1,0},
        {0,0,0,0},
        {2,2,2,2},
    };

    std::vector<std::vector<int>> Room2 // expected output 9
    {{0,1,1,2},
     {0,5,0,0},
     {2,0,3,3},
    };

    std::vector<std::vector<int>> depa_lougi // expected output 15
    {{4,0,1},
     {10,7,0},
     {0,0,0},
     {9,1,2},
    };

    std::vector<std::vector<int>> depa_chorizo
    {{2}, 
     {5}, 
     {10},
    };
    //yaentendi_creo(depa_lougi);
    //puraCreenciaDeGentePendeja(Room2);
    //printf("Total: %d\r\n", puraCreenciaDeGentePendeja(depa_chorizo));
    matrixElementsSum(Room2);
    return 0;
}

/*  
          _____________
         |             |                                       _.--,
         |   SPOOKY!   |                                    .-'    /
         |______  _____|      _____                        /  -  - \
            ___ |/           /     \   BOOOOOO!!!         '   e  e  '  '- .,
          .'   \ .-.        / O   O \                    (      ^    )_ .    ' . 
         /  O  O | |       |    U    |                 .'  '.   o   '       ' . '/ _
    ,---'     ^    /       |         \               .'          _         '_    _ . 
    \____         /        \          '--.    .-''---'   .'|                  '''  :
        /       .'          '.            `\ '.  .. -...'  |                      :
       (       |              `'---.       |   '.'          \                    :
        \     .'                   ,_)     /                 \                  :
        /  .-'                      `.___.'                    '._            :
        (.-'                                                   /  '_   __ . -'
                                                            - /      .'
                                                            \______.'


    
*/