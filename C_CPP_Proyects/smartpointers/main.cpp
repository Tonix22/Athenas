#include <iostream>
#include <string>
#include <memory>
using namespace std;
class SmartPtr { 
    int* ptr; // Actual pointer 
public: 
    // Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/ 
    // for use of explicit keyword 
    explicit SmartPtr(int* p = NULL) { ptr = p; } 
  
    // Destructor 
    ~SmartPtr() { cout<<"delted"<<endl; delete (ptr); } 
  
    // Overloading dereferencing operator 
    int& operator*() { return *ptr; } 
};

class Entity
{
    public:
    Entity()
    {
        std::cout << "create" << std::endl;
    }
    ~Entity()
    {
        std::cout << "destroy" << std::endl;
    }
    void print(){}
};

int main(int argc, char const *argv[])
{
    //typical class with its destructor
    {
        SmartPtr ptr(new int()); 
        *ptr = 20; 
        cout << *ptr<<endl;
    }
    //unique pointer, when it get out of scope it will be deleted
    //cant be passed to a funcion 
    {
        // in constructor dont call new directly, because excpetion safety
        std::unique_ptr<Entity> entity = make_unique<Entity>();
        //std::unique_ptr<Entity> e0 = entity; this is an error
        entity->print();
    }
    std::cout << "**********" << std::endl;
    //shared pointer has a references counter of references, and when the references
    // goes to 0 the reference share pointer will die.
    {    shared_ptr<Entity> e0; 
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            e0= sharedEntity;
        }//refernce counter -1 , not yet destroyed the object, // e0 still live
        std::cout << "still alive" << std::endl;
    }//e0 dies, free memory, counter is 0
    std::cout << "shared die" << std::endl;

    std::cout << "**********" << std::endl;
    //weak pointer just point to shared pointer if the pointer still alive. 
    // but dont increatse ref count
    {    weak_ptr<Entity> e0; 
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            e0= sharedEntity; // it doesnt increase de ref count
        }//shared pointer dies
        std::cout << "ref count to '0" << std::endl;
    }
    return 0;
}
