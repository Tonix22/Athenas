#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Coordenada{
    public:
    float x, y, w;

    Coordenada(){
        this -> x = 0;
        this -> y = 0;
        this -> w = 0;
    };
    Coordenada(float x, float y, float w){
        this -> x = x;
        this -> y = y;
        this -> w = w;
    };

    void operator+= (Coordenada c){
        this -> x += c.x*c.w;
        this -> y += c.y*c.w;
        this -> w += c.w;
    };

    /*
    void operator<< (Coordenada c){
        cout << "(" << c.x << ", " << c.y << ")";
    };
    */

    friend ostream &operator<<( ostream &output, const Coordenada &c ) { 
        output << "(" << c.x << ", " << c.y << ")";
        return output;
    }

};

Coordenada centro(vector<Coordenada> &c){
    Coordenada aux;

    for(Coordenada i: c){
        aux.x+=i.x;
        aux.y+=i.y;
    }

    aux.x=aux.x/c.size();
    aux.y=aux.y/c.size();

    cout << "(" << aux.x << ", " << aux.y << ")" << endl;
    return aux;

}

Coordenada centroW(vector<Coordenada> &c){
    Coordenada aux;

    for(Coordenada i: c){
        aux+=i; //REPLAZA LO DE ABAJO

        /*
        aux.x+=i.x*i.w;
        aux.y+=i.y*i.w;
        aux.w+=i.w;
        */
    }

    aux.x=aux.x/aux.w;
    aux.y=aux.y/aux.w;

    return aux;

}

int main(int argc, char const *argv[])
{
    Coordenada c1(-12, 34, 98);
    Coordenada c2(24, -15, 69);
    Coordenada c3(-29, 2, 78);

    vector<Coordenada> v{c1, c2, c3};

    centro(v);

    cout << centroW(v) << endl;

    return 0;
}
