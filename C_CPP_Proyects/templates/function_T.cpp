#include <iostream>
#include <string>
#include <vector>
#define BASIC    (0)
#define DECLTYPE (1)
#define Pointers (1)

using namespace std;

// basic template
#if BASIC
    template<typename T>
    T max_val(T a,T b)
    {
        return (b<a)?a:b;
    }
#endif
// using auto as return parameter
#if DECLTYPE
    template<typename T>
    auto max_val(T a,T b) -> decltype((b<a)?a:b)
    {
        return (b<a)?a:b;
    }
#endif 
// this one soport pointers deferencing them
//std::decay ensure not reference could be returned
#if Pointers
    template<typename T>
    T max_val(T* a, T* b)
    {
        return (*b<*a)? *a:*b;
    }
#endif 


int main(int argc, char const *argv[])
{
    int i = 42;
    string s1 = "math";
    string s2 = "lifeis to short";
    
    cout<<"set by variales"<<endl;
    //parameters after iniitialized
    cout<<max_val(i,13)<<endl;
    cout<<max<string>(s1,s2)<<endl;
    //at the moment
    cout<<"set on the fly"<<endl;
    cout<<max_val<int>(42,13)<<endl;
    cout<<max_val<string>("math","lifeis to short")<<endl;
    
    //Template is overload to get the pointer definitiion 
    int* A = new int (4);
    int* B = new int (2);
    auto m3 = max_val(A,B);
    cout<<"pointer test "<<endl;
    cout<<m3<<endl;

    return 0;
}
