#include <iostream>
#include <string>

using namespace std;

typedef enum {
    DONA,
    CONCHA,
    BOLILLO


}pan_enum_t;


/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class Bakery {
    public:
    virtual ~Bakery(){}; // pues tengo que darles mis ultimas palabras
    virtual string bake() const = 0;  // te prometo que nunca voy a cambiar </3  >:(
    int masa;
};
/**
 * Concrete Products are created by corresponding Concrete Factories.
 */

class Dona : public Bakery{
    public:
    string bake() const override
    {
        return "This is Dona";
    }   
};

class Bolillo : public Bakery{
    public:
    string bake() const override 
    {
        return "This is a Bolillou";
    }
};

class CoffeeShop{
   public:
    virtual ~CoffeeShop(){}; // pues tengo que darles mis ultimas palabras
    virtual string brew() const = 0;  // te prometo que nunca voy a cambiar </3  >:(
    
    virtual std::string Combo(const Bakery &collaborator) const = 0;
};

class Moka : public CoffeeShop{
    public:
    string brew()const override {
        return "Moka blanco para... *Glason*...?";
    }
    string Combo(const Bakery &factory) const override {
        const std::string result = factory.bake();
        return "Combo with ( " + result + " )";
    }
};

class Expresso : public CoffeeShop{
     public:
    string brew()const override {
        return "Expreso bien cargado para ...*tu mama*... :)";
    }

    string Combo (const Bakery &factory) const override{
        const string result = factory.bake();
        return "Combo with (" + result + ")";
    }
};

/**
 * The Abstract Factory interface declares a set of methods that return
 * different abstract products. These products are called a family and are
 * related by a high-level theme or concept. Products of one family are usually
 * able to collaborate among themselves. A family of products may have several
 * variants, but the products of one variant are incompatible with products of
 * another.
 */

class AbstractFactory {
 public:
  virtual Bakery *CreatePanecito() const = 0; // puramente virtuales
  virtual CoffeeShop *CreateBebida() const = 0;
};


/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */

class Starbucks : public AbstractFactory{
    Bakery * CreatePanecito() const override
    {
        return new Bolillo();
    }

    CoffeeShop * CreateBebida() const override
    {
        return new Expresso();
    }
};

class BorraDelCafe : public AbstractFactory{
    Bakery * CreatePanecito() const override
    {
        return new Dona();
    }
    CoffeeShop * CreateBebida() const override
    {
        return new Moka();        
    }
};


void ClientCode(const AbstractFactory &factory) {

  const Bakery * panecito = factory.CreatePanecito();
  const CoffeeShop * cafecito = factory.CreateBebida();
  
  std::cout << panecito->bake() << "\n";
  std::cout << cafecito->brew() << "\n";
  std::cout << cafecito->Combo(*panecito) << "\n";
  delete panecito;
  delete cafecito;
  
}

    
/*
class PancitoWe{
    private:

    public:
    PancitoWe(int tipo_pan){
     switch(tipo_pan){
         case DONA: cout<<"soy una dona"<<endl;
         break;
         case CONCHA: cout<<"soy una concha"<<endl;
         break;
         case BOLILLO: cout<<"soy una bolillo"<<endl;
         break;

     }
    }
};

    //EJERCICIO DUMMY
    //Alocado dinamicamente (RAM), existe hasta que el codigo se corre
    PancitoWe * dona = new PancitoWe(DONA);

    //Alocado staticamente
    PancitoWe bolillo = PancitoWe(BOLILLO);

    PancitoWe conchatumadre(CONCHA);
*/

int main(int argc, char const *argv[])
{   
    std::cout << "Client: Testing client code with the first factory type:\n";
    
    Starbucks *experiencia = new Starbucks();
    ClientCode(*experiencia);
    delete experiencia;

    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    
    BorraDelCafe *cafe = new BorraDelCafe();
    ClientCode(*cafe);
    delete cafe;
    
    return 0;
}
