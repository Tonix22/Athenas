#include <iostream>
#include <string>

using namespace std;

class ComidaCallejera{
    protected:
    bool covid19;
    bool perro;

    public:
    ComidaCallejera(bool perro){
        covid19=1;
        this -> perro = perro;
    }
    ComidaCallejera(){
        covid19=0;
        perro=1;
    }

    bool isPerro(){
        return this -> perro;
    }

    virtual string bark(){
        return (this -> perro)?"bark":"[...]";
    }
};

class Camotes{
    public:
    int precio;
    bool lechera;
    ComidaCallejera cc;

    Camotes(int precio, bool lechera, bool perro):cc(perro){
        this -> precio = precio;
        this -> lechera = lechera;
    }
};

class Tacos: ComidaCallejera{
    public:
    Tacos(){

    }

    string bark(){
        return (this -> perro)?"woof":"[...]";
    }
};

int main(int argc, char const *argv[])
{
    Camotes c(15, 1, 0);
    printf("Tu camote: $%d, %s %s", c.precio, (c.lechera)?" con harta lechera":" sin lechera", (c.cc.isPerro())?" y se llama Firulais":" y no hace guau :v\n");

    cout << c.cc.bark() << endl;
    Tacos t;
    cout << t.bark() << endl;

    return 0;
}