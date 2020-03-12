#include <iostream>
#include <string>
using namespace std;

class Ancestral
{
    public:
        virtual string GetName()=0;
};

class Vater : Ancestral
{
    public:
        string GetName() override {return "Vader";}
};

class Sohne: public Vater
{
    protected:
        string m_Name;
    public:
        Sohne(const string& name)
            :m_Name(name){}
        string GetName() override {return m_Name;}
};

class Ren: public Sohne{
    protected:
        string saber;
    public:
        Ren(string const& sith);
        void SetName(string const& sith){m_Name=sith;}
        void lightSaber(string color);
};
Ren::Ren(string const& sith):Sohne(sith){};
void Ren::lightSaber(string color){this->saber=color; cout << this -> saber << endl;}

void printName(Vater* name){
    cout << name -> GetName() << endl;
};

int main(int argc, char const *argv[])
{
    Vater* Vader = new Vater();
    Sohne* Skywalker = new Sohne("Luke");
    Ren* Kylo = new Ren("Ben");

    printName(Vader);
    printName(Skywalker);
    printName(Kylo);

    Kylo -> SetName("Kylo Ren");

    printName(Kylo);

    Kylo -> lightSaber("red");

    //cout << Vader -> GetName() << endl;
    //cout << Skywalker -> GetName() << endl;

    /* code */
    return 0;
}
