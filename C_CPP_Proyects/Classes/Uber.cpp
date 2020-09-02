#include <iostream>
#include <stdio.h>

/*
La empresa Uber planea tener a la renta cualquier tipo de vehiculo, 
patines, bicis, autos, botes, helicopteros y aviones. Implementa una 
programa que pueda reportar el numero de vehiculos rentados. 
asi como su distancia y tiempo y costo de viaje. Cada vehiculo tiene un tarifa diferente. 
Esta puede ser dinamica o estatica.
*/
#define CONSTRUIR   this-> tarifa = tarifa;\
                    this-> ID = ID;\
                    this-> tiempo = tiempo;\
                    this-> distancia = distancia;\

class vehicle{
    public:
    uint32_t distancia;
    uint32_t tiempo;
    uint32_t costo;
    int ID;
    float tarifa;
    virtual void calcularTarifa () = 0; // pure virtual function

    void printCost(){
        printf("El costo es: $%i \r\n", costo);
    }
    virtual ~vehicle(){};
};

typedef enum
{
    BAJO,
    MEDIO,
    ALTO,
    nivel_max,
}nivel_consumo;
#define BASE_ENERGY 4

class patines : public vehicle{
    public:
    int potencia;
    int consumo[nivel_max] = {1,27,84}; //  kW/h -> $1.00

    patines(float tarifa, int ID, int tiempo, int distancia){
        CONSTRUIR;
    }
    void calcularTarifa(){
        this-> potencia = distancia*tiempo*BASE_ENERGY;

        if(potencia < 27){
            costo = consumo[BAJO] * tiempo;
        }else if(potencia >=27 && potencia <84){
            costo = consumo[MEDIO] * tiempo;
        }else {
            costo = consumo[ALTO] * tiempo;
        } 
        printCost();
    }    
};
class bicis : public vehicle{
    public:
    bicis(float tarifa, int ID, int tiempo, int distancia){
        CONSTRUIR;
    }
    void calcularTarifa(){
        
    }   
};
class autos : public vehicle{
    public:
    autos(float tarifa, int ID, int tiempo, int distancia){
        CONSTRUIR;
    }
    void calcularTarifa(){
        
    }  
};
class bote : public vehicle{
    public:
    bote(float tarifa, int ID, int tiempo, int distancia){
        CONSTRUIR;
    }
    void calcularTarifa(){
        
    }  
};
class helicopteros : public vehicle{
    public:
    helicopteros(float tarifa, int ID, int tiempo, int distancia){
        CONSTRUIR;
    }
    void calcularTarifa(){
        
    }  
};
class aviones : public vehicle{
    public:
    aviones(float tarifa, int ID, int tiempo, int distancia){
        CONSTRUIR;
    }
    
    void calcularTarifa(){
        
    }  
};

void trip(vehicle* generic)
{
    generic->calcularTarifa();
}


//patines, bicis, autos, botes, helicopteros y aviones
int main(int argc, char const *argv[])
{
    patines* pat2 = new patines(1,1, 3600, 5);//dynamic
    trip(pat2);
    
    return 0;

}
