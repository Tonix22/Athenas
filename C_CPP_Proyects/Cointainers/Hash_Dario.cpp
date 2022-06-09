#include<iostream>
#include<set>
#include <bits/stdc++.h>

using namespace std;

struct tcp_pair
{
    union
    {
        unsigned int ip; 
        unsigned char oct[4];// 32 bit
    }ip_addr;
    int port;
public:
    tcp_pair() {
        port = 0;
        tcp_pair::ip_addr = {.ip = 0};
        
    };
    tcp_pair(int p, unsigned int address)   {
        tcp_pair::port = p; 
        tcp_pair::ip_addr = { address };
    }

};

ostream & operator << (ostream &out,const tcp_pair& c)
{
    /*Printing IP */
    out<<(int)c.ip_addr.oct[3U]<<"."<<(int)c.ip_addr.oct[2U]<<"."<<(int)c.ip_addr.oct[1U]<<"."<<(int)c.ip_addr.oct[0U]
    <<" : "<<c.port<<endl;
    return out;
}


// :)
// Hello aweso
// Compubrody.com


int main()
{
    unsigned int c1= 10;
    unsigned int c2= 47;
    unsigned int c3= 30;
    unsigned int c4= 20;
    
    unsigned int foo = (c4 << 0) | (c3 << 8) | (c2 << 16) | (c1 << 24);
    int port = 4000;
    tcp_pair ip(4000, foo);
    
    cout << ip;

    
    return 0;
}