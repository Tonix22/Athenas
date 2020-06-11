#include <iostream>
#include <string>
using namespace std;


class alumnos
{   
    int IDnumber;
    string nombre;
    mutable int counter = 0;

    public:

        this->nombre = nombre; //-> referencia  . copia 
        this->IDnumber = IDnumber;
    }

    //alumnos b ; --> constructor basico
    //alumnos a = b; -- >constructor por copia
    alumnos(const alumnos& a2)//conctructor por copia
    {
        IDnumber = a2.getID();
        nombre   = a2.getNombre();
        cout<<" copy constructor "<<endl;
    }

    string getNombre() const { // promesa   
        counter++;      
        return nombre;
    }
    void setNombre(string nombre) {  
        this->nombre=nombre;
    }

    char getID() const { // promesa
        return IDnumber;
    }

};

void printClass (const alumnos& a)//juramento inquebrantable a
{
    cout<< a.getNombre()<<endl;
    cout<< a.getID()    <<endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    alumnos pupilos("Mulan", 1);
    printClass(pupilos);
    pupilos.setNombre("MulanCopia");
    alumnos copia = pupilos;
    copia.setNombre("Mulan again");
    printClass(copia);
    printClass(pupilos);
    //copia->setNombre("MulanCopia");
    /*
    int * const  a = new int(5);
    //int * b        = new int;
    *a = 3;
    //a = b;
    //*b = 3;
    cout << *a << endl;
    */
    return 0;
}
