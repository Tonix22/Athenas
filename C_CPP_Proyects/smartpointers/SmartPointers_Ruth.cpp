#include <iostream>
#include <memory>
#include <string>

using namespace std;

class MyUnique_ptr {
    public:

    MyUnique_ptr(){
        cout<<"Construyendo"<<endl;
    }

    ~MyUnique_ptr(){
        cout<<"Destruyendo"<<endl;
    }
    
    

};

void increment_unique_ptr(int& i) {
    i = i+1;
}

int main(int argc, char const *argv[])
{
    
    std::unique_ptr<int> p1 (new int(5));
    //scope
    {
    std::unique_ptr<MyUnique_ptr> p1_class (new MyUnique_ptr());
    }
    cout<<*p1<<endl;
    //*p1 = *p1+1;
    increment_unique_ptr(*p1);

    cout<<*p1<<endl;

    return 0;
}
