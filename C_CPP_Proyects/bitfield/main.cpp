
#include <iostream>
using namespace std;
//char 8
//short 16
//long 32
//long long 64
//float 32
//double 64

void toggle()
{
    static char a = 0;
    a^=1; //XOR 1
    if(a)
    {
        cout << "1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
}

int main(int argc, char const *argv[])
{
                 //  E
    char a = 23; //0001 0111
                // 0010 0000 // 2pow6
                // 0011 0111



    // setear bit
    a |= (1<<6); // escribiendo el bit 6

    //limpiar bit            
    a &= ~(1<<6); // limpiando el bit 6

    // 0010 0000*
    // 1101 1111
    // 0011 0111 original
    //----------
    // 0001 0111 -> LIMPIAR EL BIT 6

    int x = 5, y = 10;
    
    (x ^= y), (y ^= x), (x ^= y); //trucologia
    
    //1111 X 
    //0101 Y
    //1. x = 1111
    //2. y = 0101
    //3. x = 1010

    // a = 1 XOR 1 = 0
    // a = 0 XOR 1 = 1
    // a = 1 XOR 1 = 0
    // a = 0 XOR 1 = 1

    toggle();//1
    toggle();//0
    toggle();//1

    return 0;
}