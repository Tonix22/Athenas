#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include <vector>

using namespace std;
#define INTERES 0.05

float interes_recursivo (int meses,float dinero){
    if(meses == 0){
        return dinero;
    }
    return interes_recursivo(meses-1,dinero)*(1+ INTERES/12.0);
}

double interes_corto(int meses,float dinero){
    return pow((1+ INTERES/12.0),meses)*dinero;
}

int fibonacci_dynamic(int n){
    if(n==0 || n==1)
        return 1;

    return fibonacci_dynamic( n-1) + fibonacci_dynamic(n-2);
}

int greedy_fib(int n)
{
    int f[n+2];
    int i;
    
    f[0] = 1;
    f[1] = 1;

    for( i = 2 ; i<=n ; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int greedy_fib_vector(int n)
{
    vector<int> f;
    f.push_back(1);//f[0]
    f.push_back(1);//f[1]
    int i;
    for( i = 2 ; i<=n ; i++)
    {
        //f[i] = f[i-1] + f[i-2];
        //se genera un nuevo f[i]
        f.push_back(f[0] + f[1]);
        f.erase(f.begin()); // &f[0]
        
    }
    
    //F[2] = F[1]+F[0] i = 2
    //F[0],F[1],F[2]
    //F[1],F[2]
    //F[3] = F[2]+F[1] i = 3
    //F[1],F[2],F[3]


    return f[1];
}

int fibonacci_formulazo (int n){
    double sqrt_5 = sqrt(5);
    n=n+1;
    return ( pow(1 + sqrt_5,n) - pow(1 - sqrt_5,n) ) / ( pow(2,n)*sqrt_5 );
}

int main(int argc, char const *argv[])
{
    printf("\nINTERES RECURSION = %f \n", interes_recursivo(5,1000));
    printf("\nINTERES FORMULAZO = %f \n", interes_corto(5,1000)); 
    printf("\nFIBONNACCI RECURSIVO = %i \n", fibonacci_dynamic(10));  
    printf("\nFIBONNACCI GREEDY = %i \n", greedy_fib(10)); 
    printf("\nFIBONNACCI FORMULAZO = %i \n", fibonacci_formulazo(9));  
    printf("\nFIBONNACCI GREEDY VECTOR = %i \n", greedy_fib_vector(9));  
    
         
    return 0;
}
