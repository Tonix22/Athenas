#include<stdio.h>
#include<iostream>
#include <chrono>

using namespace std;

int recFib(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }
    return recFib(n-1)+recFib(n-2);
}


int iterativefib(int n)
{
    long res = 1; // caso 0
    long anterior1 = res;// condiciones iniciales
    long anterior2 = res;// condiciones iniciales

    for(int i=1; i<n;i++){
        res = anterior1 + anterior2; // caso 1
        anterior2 = anterior1;
        anterior1 = res;
    }
    return res;
}

int Exercise(int n)
{
    int i;
    int Array[n+1];
    for (int i = 0; i<(n+1); i++)
    {
        Array[i]=0;
    }
    
    Array[0] = 1; // un escalon
    Array[1] = 2; // dos escalon

    for(i=2; i<n; i++)
    {
        Array[i]= Array[i-1] + Array[i-2];
    }

    return Array[n-1];

}

int main(int argc, char const *argv[])
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //recFib(5);
    std::cout<<iterativefib(30)<<std::endl;
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    return 0;
}
