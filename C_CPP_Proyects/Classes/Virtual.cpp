#include  <iostream>
#include  <string>
using namespace std;
class Entity
{
    public: 
        virtual string GetName () const = 0;
};

class Player: public Entity
{
private:
    string  m_Name;
public:
    Player(){};
    Player(const string& name)
        : m_Name(name){}
    string GetName() const override 
    {
        //(const_cast <Player*> (this) )->m_Name="modified";
        return m_Name;
    }
};
void PrintName(Entity* enti)
{
    cout<<enti->GetName() << endl;
}
int main(int argc, char const *argv[])
{
    Player* e = new Player("Cherno");
    PrintName(e);
    //Player* p = new Player("Cherno");
    //PrintName(p);
    return 0;
}
