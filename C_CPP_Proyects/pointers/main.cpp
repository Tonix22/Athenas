
#include <iostream>

using namespace std;

void increment_value(int* val)//referenciar a
{
    (*val)++;
}
void take_array(int* p)
{
    for(int i=0;i<5;i++,p++)//incrementa direccion del array
    {
        (*p)++;//incrementa el valor del array
        cout<<(*p)<<", ";//print value
    }
    std::cout << std::endl;
}
struct Personaje
{
    int ID;  // 32 bits 
    int Edad; //  32 bits 
    int Ranking; //32 bits
    int vida; // 32 bitss
};//128 bits
void setvida(int& ref)
{
    ref++;
}
void iniciar_structura(struct Personaje& ref)
{
   int init[4]={22,77,100,4};
   int* P_init=init; // pointer to array
   int* OtroPointer = &(ref.ID);// apuntar al primer elemento de la estructura
   for(int i=0;i<4;i++)
   {
       *OtroPointer = *P_init;//valor de struct = valor de array
       OtroPointer++;//avanza la estrucutra
       P_init++;// avanza el arreglo
   }
    cout<<"punteros a estructura"<<endl;
    cout<<"Edad: "<<ref.Edad<<endl;
    cout<<"Ranking: "<<ref.Ranking<<endl;
    cout<<"vida: "<<ref.vida<<endl;
    cout<<"ID: "<<ref.ID<<endl;

}
void foo(int a) // tiene una direccion
{
    cout<<"holi: "<<a<<endl;
}

int main(int argc, char const *argv[])
{

    /*Referencia simple tomada por apuntador*/
    int  yo       = 3;
    int* Lechero  = &yo;
    *Lechero=4;
    cout<<"Cambio de apuntador simple"<<endl;
    std::cout << "Yo: " <<yo<< std::endl;
    /*Referencia tomada por funcion*/
    increment_value(&yo);//4
    cout<<"Pasar referencia a funcion"<<endl;
    std::cout << "yo: " <<yo<< std::endl;

    /*Apuntadores arreglos*/
    /*El arreglo es un directorio de direcciones
      por lo tanto cada indice es un apuntador
    */
    int sequence[5]={1,2,7,8,9};
    cout<<"Apuntadores a arreglos"<<endl;
    take_array(sequence);
    
    /*apuntadores a estructuras*/

    struct Personaje user; //128 bits
    iniciar_structura(user);
    /*Apuntadores a funciones*/
    /*Permiten hacer arreglos de funciones o guardarlas en otros lados*/
    /*usamos el typded para acortar el tipo de dato*/
    typedef void(*funptr)(int);
    /*creamos arreglo con ese tipo de dato*/
    funptr marrano[3];
    /*apuntamos a la funcion foo*/
    marrano[0]=&foo;
    (*marrano[0])(10);//esta es la funcion
    int x=3;
    if(3 == x)
    {
        cout<<"es tres"<<endl;
    }
    /* 
    Aplicaciones 
    Arreglo de tareas(funciones) que corro cada cierto tiempo

    Clicke muchas veces diferentes lados y se traba la compu
    clicks se almacenan y luego se despachan

    priority queue.

    Sistemas de alarmas
    creas timer
                           name   time  repeat  param    fucntion to point
    xTimer = xTimerCreate("Timer",100,PdTrue,(void*)0,vTimerCallback)
    xTimerStart( xTimers[ x ] ) // triggers de timer when necessary
     */
    return 0;
}
