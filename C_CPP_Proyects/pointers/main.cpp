
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
   int* P_init=init;
   int* OtroPointer = &(ref.ID);// apuntar al primer elemento de la estructura
   for(int i=0;i<4;i++)
   {
       *OtroPointer = *P_init;//avanza de 32 en 32
       OtroPointer++;//avanza la estrucutra
       P_init++;// avanza el arreglo
   }
    cout<<"punteros a estructura"<<endl;
    cout<<"Edad: "<<ref.Edad<<endl;
    cout<<"Ranking: "<<ref.Ranking<<endl;
    cout<<"vida: "<<ref.vida<<endl;
    cout<<"ID: "<<ref.ID<<endl;

}
void foo(int a)
{
    cout<<"holi: "<<a<<endl;
}

int main(int argc, char const *argv[])
{

    /*Referencia simple tomada por apuntador*/
    int  Sol       = 3;
    int* Estrella  = &Sol;
    *Estrella=4;
    cout<<"Cambio de apuntador simple"<<endl;
    std::cout << "Sol: " <<*Estrella<< std::endl;
    /*Referencia tomada por funcion*/
    increment_value(&Sol);
    cout<<"Pasar referencia a funcion"<<endl;
    std::cout << "Sol: " <<*Estrella<< std::endl;

    /*Apuntadores arreglos*/
    /*El arreglo es un directorio de direcciones
      por lo tanto cada indice es un apuntador
    */
    int sequence[5]={1,2,7,8,9};
    cout<<"Apuntadores a arreglos"<<endl;
    take_array(sequence);

    /*apuntadores a estructuras*/

    struct Personaje user;
    iniciar_structura(user);
    /*Apuntadores a funciones*/
    /*Permiten hacer arreglos de funciones o guardarlas en otros lados*/
    /*usamos el typded para acortar el tipo de dato*/
    typedef void(*function_point)(int);
    /*creamos arreglo con ese tipo de dato*/
    function_point marrano[3];
    /*apuntamos a la funcion foo*/
    marrano[0]=&foo;
    (*marrano[0])(10);//esta es la funcion

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
