
#include <iostream>
#include <vector>//holi :3 owo xD ( ͡° ͜ʖ ͡°) (´・ω・`)
#include <algorithm> //Funciones locas
#include <functional>
#include <unordered_map>
#include <set>
#include <utility> 
#include <chrono>

#include <unistd.h>
using namespace std;


void ForEach (vector<int>& values, void(*func)(int))
{
    for(int& val: values)
    {
        //func(val);
        (*func)(val);
    }
    cout << endl;
}

void fun(int a) 
{ 
    cout << a << ", ";
} 
void otra(int a)
{
    cout<<a+1<<" /";
}

int main(int argc, const char** argv) 
{
    void (*funcion_prototype)(int) = &fun;

    //(*funcion_prototype)(10);

    //vector de luis
    vector<int> ints = {23, 65, 7, 245, 67, 89, 68, 420, 111, 3, 911};

    vector<int>::iterator it = find_if(ints.begin(),ints.end(), [](int i){return (i>300)&&(i<450);});//Primer valor mayor a 100
    cout << (*it) << endl;


    auto lamda = [](int i){return (i%2==0);};
    int a = count_if(ints.begin()+3,ints.end()-1,lamda);// Cuenta numeros pares
    
    cout<<"numeros pares: " << a <<endl;
    int  var = 3;
    auto lamda2 = [&var](int& i){i+=var;}; //Electric bongaloo

    for_each(ints.begin(), ints.end(), [](int i){cout << i << ", ";});
    cout<<endl;
    for_each(ints.begin(),ints.end(),lamda2);//Aumentar los valores del vector :O
    for_each(ints.begin(), ints.end(), [](int i){cout << i << ", ";});
    cout<< endl;
    
    //PAIRS
    int x =9;
    int y=8;
    pair<int, int> coordenadas;
    coordenadas = make_pair(x,y);
    cout << "Val: "<< coordenadas.first <<endl;
    cout << "Val: "<< coordenadas.second <<endl;
    cout << "Dir x: " << &x <<endl;
    cout << "Dir y: " << &y <<endl;
    cout << "coordenadas.first: "<< &coordenadas.first <<endl;
    cout << "coordenadas.second: "<< &coordenadas.second <<endl;
     // {26, 68, 10, 248, 70, 92, 71, 423, 114, 5, 914};
    sort(ints.begin(), ints.begin()+4); 
    for_each(ints.begin(), ints.end(), [](int i){cout << i << ", ";});
    
    // {26, 68, 10, 248, 70, 92, 71, 423, 114, 5, 914};
    auto rev = ints.rbegin();
    rev++;
    cout<<*rev<<";";

    pair<int, int> two2go = {2,3};
    cout << two2go.first <<endl;
    cout << two2go.second <<endl;
    // {23, 65, 7, 245, 67, 89, 68, 420, 111, 3, 911};
    auto result = minmax_element (ints.begin(),ints.end());//REGRESA MENOR Y MAYOR (en un pair)

    //A pair with an iterator pointing to the element with 
    //the smallest value in the range [first,last) as first element, 
    //and the largest as second.
    cout << *result.first  <<endl;
    cout << *result.second <<endl;

 
    
    
    
    //for(int& i : ints){
    //    cout << i << ", ";
    //}
    //cout << endl;
   
    //vector de lulis
    vector<int> intsLu={2,5,4,6,7};
    //for(int& i : intsLu){
    //    cout << i << ", ";
    //}
    //cout << endl;
    //vector de ruth :)
    vector<int> ints2 = {1,22, 66,8,3,68,39,122,114,56} ;//La revancha
    //cout << "INTS 2 --> ";
    //for(int& i : ints){
    //    cout <<i << ", ";
    //}
    //cout << endl;

    //ForEach(ints,  &fun);
    //ForEach(intsLu,&fun);
    //ForEach(ints2, &fun);
//
    //ForEach(ints,  &otra);
    //ForEach(intsLu,&otra); 
    //ForEach(ints2, &otra);

    //LAMBDA FUNCTIONS :)
    
    //mutable: allows body to modify the objects captured by copy, 
    //and to call their non-const member functions 
    //int  a = 3;//??
    auto lambda =  [](int val)
    {
        //a = 4; //NOT POSIBLE; COPY IS ONLY ALLOWED, 
        //int b = a;
        //b = 6;
        cout<<val<<endl;
    };
    //[]caputre method
    //[] nothing
    //[&] capture all external vars by ref
    //[=] capture by copy, es una promesa de copiar
    //[a]  a by copy
    //[a&] a by reference 
    //ForEach(ints,lambda);
    //(*funcion_prototype)(int)

    return 0;
}