#include <iostream>
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
int main(int argc, char const *argv[])
{
    {
        SmartPtr ptr(new int()); 
        *ptr = 20; 
        cout << *ptr<<endl;
    }
    return 0;
}
