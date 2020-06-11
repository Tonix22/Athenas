#include <iostream>
#include <memory>
#include <string>

using namespace std;
class Arte{
    //placeholder virtual method here
    
    public:

    string m;
    Arte(){
        this->m = "art is life";
    }
    Arte(string m){
        
        this->m = m;
    }

    virtual string Mensaje(){
        cout<<"ARTE"<<endl;
        return m;
    }
};
class Musica : public Arte {
    public:
    string Mensaje(){
        
        cout << m << endl;//hi :D
        return m;
    }
    //Holiwis
};
typedef enum 
{
    Terror = 60,
    Comedia,
    Ciencia,
    Acciones,
    Thriller,
}Categoria;

class Peliculas {
    public:
    int muerte[10000];
    int duracion = 90;
    Categoria cat = Thriller;
    string Director = "Guille";
    Peliculas(){
        cout<<"constructor por dafault "<< endl;
    };
    Peliculas(string Director){
        cout<<"constructor parametro "<< endl;
        this->Director = Director;
    };
    Peliculas(const Peliculas &copy)
    {
        duracion = 180;
        cat = copy.cat; // copiar categoria
        Director = copy.Director;
        cout<<"copy constructor "<< endl;
    }

};

void holi(void)
{
    Peliculas* HP3 = new Peliculas("Quaron");
    delete(HP3);

    //Tonix puts the Sexy in Dyslexia
}

int main(int argc, char const *argv[])
{
    /*
    
    Peliculas* HP3 = new Peliculas("Quaron");
    Peliculas Hellboy;
    Peliculas Water = Hellboy;

    Musica* ACDC = new Musica() ;
    Musica* Reggae = (Musica*) new Arte();
    ACDC->Mensaje();
    Reggae->Mensaje();

    Todos_Juntos No ;
    No.a = 3;
    cout<<"El valor de a es : " << No.a <<endl;
    cout<<"El valor de b es : " << No.b <<endl;
    */

    for(;;)
    {
        holi();
    }
    return 0;
}

