#include<iostream>
#include<set>
#include <bits/stdc++.h>

using namespace std;

struct tcp_pair
{
    union
    {
        unsigned char oct[4];
        unsigned int ip; // 32 bit
    } ip_addr;
    int port;
public:
    tcp_pair() {
        port = 0;
        ip_addr.ip = 0;
        
    }
    tcp_pair(int p) { 
        //ip_addr.ip = (unsigned int)address;
        port = p;
    }
    tcp_pair(int p,unsigned int address) { 
        ip_addr.ip = address;
        port = p;
    }
};

ostream & operator << (ostream &out,const tcp_pair& c)
{
    /*Printing IP */
    out<<c.ip_addr.oct[0U]<<"."<<c.ip_addr.oct[1U]<<"."<<c.ip_addr.oct[2U]<<"."<<c.ip_addr.oct[3U]<<endl;
    /*Printing port*/
    cout<<": "<<c.port<<endl;
    return out;
}


// :)
// Hello aweso
// Compubrody.com
struct MatrixHashTCP{
public:
    size_t operator()(const string& str) const
    {
        int string_size = str.length();
        unsigned long acum = 0;
        // max size string 18
        for(int i = 0;i<str.length();i++) 
        {
            acum+= (str[i]-'a'+1); // remove offsset
        }
        cout<<" "<<acum<<","<<endl;
        
        return hash<int>()(acum);
    }
};

int main()
{
    unsigned int c1= 10;
    unsigned int c2= 47;
    unsigned int c3= 30;
    unsigned int c4= 20;
    
    unsigned int foo = (unsigned int) (c1 << 23) | (c2 << 15) | (c3 << 7) | (c4 << 0);
    tcp_pair ip(4000,foo);
    
    cout << ip;

    
    return 0;
}