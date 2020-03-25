//clase vehicuilop
// automovil, agua, aire, terrestre
#include <string>
#include <iostream>
using namespace std;

class carga
{
    int PERSONAS;
    int bienes;
};

class vehiculos : private carga
{
    public:
    int max_speed;
    string target;
};
class terrestre: virtual vehiculos
{
    public:
    bool Has_tires;
    bool Motor;
};
class automovil: virtual terrestre
{

};
int main(int argc, char const *argv[])
{
    automovil scooter;

    vehiculos* generic_Vehicule_p = (vehiculos*)&scooter;
    generic_Vehicule_p->max_speed = 20;
    generic_Vehicule_p->target    = "Guadalajara";
    cout<<"max_speed: "<<generic_Vehicule_p->max_speed<<endl;
    cout<<"target: "<<generic_Vehicule_p->target<<endl;

    /* code */
    return 0;
}
