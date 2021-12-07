#include "vector_clase.h"
#include <iostream>

Alumno::Alumno(string name, int age) : name(name), age(age)
{
    //this->name = name;
    //this->age  = age;
    std::cout<<"Constructor parametros"<<std::endl;
}
Alumno::Alumno(const Alumno& alumno2)
{
    this->age  = alumno2.age;
    this->ID   = alumno2.ID;
    this->name = alumno2.name;
    std::cout<<"Constructor copia"<<std::endl;
}
Alumno::Alumno()
{   
    std::cout<<"Constructor simple"<<std::endl;
}
void Alumno::AlumnoID(int id)
{
    this->ID = id; 
}

Alumno::~Alumno(){
    this->name.clear();
    this->age = 0;
    this->ID = 0;
    std::cout<<"destructor"<<std::endl;
}

int main(int argc, char const *argv[])
{
    Alumno* alumno1 = new Alumno(); // RAM recursos
    Alumno alumno2 = {"alumno",2};//esta en disco
    alumno2.AlumnoID(15);
    alumno1->AlumnoID(15);
    
    Alumno alumno3 = alumno2;
    
    delete alumno1;
   
    return 0;
}
