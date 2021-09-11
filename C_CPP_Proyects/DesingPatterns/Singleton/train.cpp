#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
//1,2,3,4,5,6,7,8,9
//1,3,6,10,15,21,28,36,45
class Cementerio {
    public:
    static int esqueletos;
    int id;
    string* nombre;
    
};

void suma_acumulativa(int valor)
{
    static int x = 0;
    x+=valor;
    std::cout<<x<<std::endl;
}


int Cementerio::esqueletos = 0; // guardalo en disco

int main(int argc, char const *argv[])
{
    

    Cementerio  me_quiero_morir;
    me_quiero_morir.id = 0;
    me_quiero_morir.nombre = new string("Ruth");
    me_quiero_morir.esqueletos = 666;
    
    std::cout<<"mi tumba id:"<< me_quiero_morir.id << std::endl;
    
    
    Cementerio * spoopy = new Cementerio();
    spoopy -> id = 1;
    std::cout<<"mi tumba id:"<< spoopy -> id << std::endl;

    //*****************
    std::cout << "lougi" << endl;
    std::cout << spoopy->esqueletos <<std::endl;
    
    cout << "ruti" << endl;
    std::cout << me_quiero_morir.esqueletos <<std::endl;
    //*****************
    /*
    for(int i=1;i<10;i++)
    {
        
        suma_acumulativa(i);
    }
    */
    return 0;
}
// :)