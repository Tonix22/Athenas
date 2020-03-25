#include  <iostream>
#include  <string>
using namespace std;
class Entity
{
    public: 
        virtual string GetName() { return "Entity";}
};

class Player: public Entity
{
private:
    string  m_Name;
public:
    Player(const string& name)
        : m_Name(name){}
    string GetName() override {return m_Name;}
};
void PrintName(Entity* enti)
{
    cout<<enti->GetName() << endl;
}
int main(int argc, char const *argv[])
{
    Entity* e = new Entity();
    PrintName(e);
    Player* p = new Player("Cherno");
    PrintName(p);
    return 0;
}
