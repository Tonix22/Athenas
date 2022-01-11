#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Animal 
{
    public:
    string name;
    // de afuerzitas
    virtual void animal_sound() = 0;
    virtual void eat() = 0;
    // pues te doy chance
    virtual void die_qux()
    {
        std::cout<<"me petate"<<std::endl;
    }
};

/*
(\_(\
(=' :')
c(,(")(")
*/
class Cheniol : public Animal
{
    
    public:
    Cheniol(){};
    ~Cheniol(){};
    void animal_sound()
    {
        cout<<"Es el dia del platano, chi cheniol!!! :3"<<endl;
    }

    void eat()
    {
        cout<<"Platano ( ͡° ͜ʖ ͡°)"<<endl;
    }
    void die_qux()
    {
        cout<<"me modi"<<endl;
    }
};
/*
                /^._
  ,___,--~~~~--' /'~
  `~--~\ )___,)/'    
      (/\\_  (/\\_
*/
class Lobo : public Animal
{
    public:
    Lobo(){};         /*Create a Constructor*/
    ~Lobo(){};        /*Create a Destructor*/

    void animal_sound()
    {
        cout<<"Una loba en el armario, tiene ganas de salir AUUUU!!!"<<endl;
    }

    void eat()
    {
        cout<<"Soy carnivoro JAJA"<<endl; // mente de tiburon >:V
    }
};
/*
       (\_
        ((    _/{  "-;
         )).-' {{ ;'`
        ( (  ;._ \\
*/
class Perro: public Animal
{
    public:
    void animal_sound(){
        cout << "barf" << endl;// wef wef
    }
    void eat(){
        cout << "croqueta" << endl;
    }
};

/*Poner una funcion que 
imprima el sonido de un animal 
y que come*/

void info(Animal *name){
    name->animal_sound();
    name->eat();
    name->die_qux();
}

int main(int argc, char const *argv[])
{
    Cheniol* cheniol = new Cheniol();

    Lobo *lb = new Lobo();
    
    Perro* perro = new Perro();
    
    info(perro);
    info(lb);
    info(cheniol);
    return 0;
}

