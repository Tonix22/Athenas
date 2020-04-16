#include <iostream>
#include <vector>
//TODO #include <URSS.h>
struct Personaje
{
    int ID;  // 32 bits 
    int Edad = 21; //  32 bits 
    int Ranking; //32 bits
    int vida; // 32 bitss
};//128 bits
void hueco_capital()
{
    int* millenial; // solo en la calle
    millenial = new int(4); // pidiendo memoria 
    std::cout << *millenial << std::endl;
    free(millenial); 
    std::cout << *millenial << std::endl;
}
class Duro
{
    int gore;
    public:
    Duro(int intensity)
    {   
        gore = intensity;
        std::cout << "Luis Open and Ready" << std::endl;
    }
    Duro(const Duro& copy)
    {
        gore = copy.gore;
        std::cout << "soy una copia infeciente" << std::endl;
    }
    
    void printMyIntensity()
    {
        //std::cout << "hit me daDDDDY: " << gore<< std::endl;
    }
    ~Duro()
    {
        std::cout << "Luis Closed and destroyed in his *@1" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    struct Personaje* Mario = new (struct Personaje);
    int* OtroPointer = &(Mario->ID);
    OtroPointer++; 
    //std::cout << (*OtroPointer) << std::endl;
    std::vector<Duro> Fun;
    Fun.reserve(3);
    Fun.emplace_back(100);
    Fun.emplace_back(60);
    Fun.emplace_back(20);
    //Fun.push_back({20});
    /*
    {
        Duro BDSM(100);
        BDSM.printMyIntensity();
    }
    {
        Duro* BDSM = new Duro(100);
        BDSM->printMyIntensity();
        delete BDSM;
    }
    */
    return 0;
}
