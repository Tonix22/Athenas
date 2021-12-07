#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <utility> 
using namespace std;


//auto mid = vector.begin() + vector.size() / 2; 
//myvector.insert ( iteretor , valor );
void migue_sort(vector <int>& A)
{
    vector<int> B;
    int Mitad_32    = 0;
    int Inicio_32   = 0;
    int Fin_32      = 0;
    int X           = 0;
    for(int Iterator_32=0; Iterator_32 < A.size(); Iterator_32++)
    {
        if(B.empty())
        {     
            B.push_back(A.back());
            A.pop_back();
        }
        else
        {
            X = A.back();
            Fin_32 = B.size()-1;
            while(Inicio_32 < Fin_32)
            {
                Mitad_32 = (Inicio_32 + (Fin_32 - Inicio_32))>>1;
                /* Ya existe esta madre? */
                if (X == B[Iterator_32])///ERROR
                {
                    B.insert(B.begin()+Iterator_32, A[Iterator_32]);
                }
                /* Checar que A[i] sea menor que B[Mitad] */

                // te vas a la izquierda
                else if (B[Iterator_32] < X) //ERROR
                {
                    Fin_32 =  Mitad_32 - Inicio_32;
                    //1,2,3,4,5,6,7,8,9,10
                    // I, , , ,M, , , , ,F
                    // I, ,M , ,F, , , , ,
                }
                else // te vas a la derecha
                {
                    Inicio_32 += Mitad_32;
                    //1,2,3,4,5,6,7,8,9,10
                     // I, , , ,M, , , , ,F
                     //  , , , ,I, , , , ,F
                }
            }
            Mitad_32 = (Inicio_32 + (Fin_32 - Inicio_32))>>1;
            if(B[Mitad_32]<X)
            {
                B.insert(B.begin()+Mitad_32+1,X);
            }
            else
            {
                B.insert(B.begin()+Mitad_32,X);
            }
        }
    }
    
}

vector<int>::iterator find_insert_pos(vector <int>& B,int valor)
{
    vector<int>::iterator inicio = B.begin(); 
    vector<int>::iterator fin    = B.end()-1; 
    vector<int>::iterator mitad;

    while (inicio <= fin) 
    {
        mitad = inicio + (fin-inicio)/2;
    
        if (*mitad == valor) // Si es numero repetido
            break; 

        if (*mitad < valor) // Recorrer inicio al centro
            inicio = mitad + 1; 

        else // recorrer final hacia la izquierda
            fin    = mitad - 1;
    }
    return mitad;
}

void fastest_sort(vector <int>& A)
{
    std::vector<int> B;
    vector<int>::iterator half;
    int item = 0;

    //Base case
    B.push_back(A.back());
    A.pop_back();

    // Other cases
    while(!A.empty())
    {
        item  = A.back();

        half = find_insert_pos(B,item);//interfaz

        if (*half < item) 
            B.insert (half+1,item);
        else 
            B.insert (half,item);

        A.pop_back();
    }
    A=B;
}


#if PACOYRUTH
//myvector.insert ( it , 200 );
void paco_sort(vector<int>& A)
{
    vector<int> B;
    vector<int>::iterator pick;
    int start = 0;
    int end = B.size()-1;
    while(!A.empty()){
        pick = A.end();
        A.pop_back();
        while(start <= end){ // searching
            int middle =B.begin()+ floor((B.begin()+ B.size())/2); //cambiar begin y end
            if(B.at(middle) < pick){ //at(0) = [0]
                begin = middle+1;
                //B.insert(..);
            }else if(B.at(middle) > pick){
                end = middle-1;
                //B.insert(..);
            }else{
                //B.insert(pick);
            }
        }
    }
    
}


void ruth_sort(vector<int>& A)
{
    vector<int> B;
    vector<int>::iterator pivot;
    int mid = 0, left=0, right=0;
    B.push_back(A[0]);
    A.pop_back();
    pivot = B.begin();
    while(!A.empty()){
        mid = B.begin()+(B.begin()-B.end()) / 2;
        mid = left + (right-left)/2;
       
    }
    
}
#endif
/*
 0 1 2 3 4 5 6 7 8
 0 0 0 0 0 0 0 0 0  CEIL
         |   |    
size = 9
 ceil(size/2) = 5

//begin end 0,8
end-begin/2=4

mitad_indice 4,
insertar 9
begin = 4
end = 8

8-4/2=2
begin = 4+2= 6



*/
/*
Step 0
A={1,4,5,7,6};
B={};
Step 1
    A={4,5,7,6};
    B={1}            [0]
Step 2
    A={5,7,6};
    B={1,4};         [0][1] mitad = 4
Step 3
    A={7,6};
    B={1,4,5};      [0][1][2] mitad = 4

    B={1,4,5};      [0] mitad = 5

    B={1,4,5,7};   

Step 4
    A={6};
    B={1,4,5,7};    [0][1][2][3] // CEIL, FLOOR
Step 4
    A={}; // esta vacio
    B={1,4,5,6,7}
*/

int main(int argc, char const *argv[])
{
    vector<int> V0{5,4,3,2,1,0};
    vector<int> V1{7,2,1,-4,0,9,13,21};
    vector<int> V2{7,2,1,-4,0,9,4,2,3,5,5,1};
    vector<int> V3{0,1,2,3,4,5,6,7,8,9,10,12,13,14,15};
    //migue_sort(V0);
    fastest_sort(V1);
    
    return 0;
}
