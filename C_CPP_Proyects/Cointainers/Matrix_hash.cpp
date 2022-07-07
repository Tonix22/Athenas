#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>
#include "Matrix_hash.h"




struct ipEqual {
public:
    bool operator()(const tcp_pair& p1, const tcp_pair& p2) const
    { // if both the lengths are equal then return True else
      // False
      cout<<"we collide"<<endl;
      return ((p1.ip_addr.ip == p2.ip_addr.ip) && (p1.port == p2.port));
    }
};

int main(int argc, char const *argv[])
{
    srand(time(0));
    unsigned int c1= 10;
    unsigned int c2= 47;
    unsigned int c3= 30;
    unsigned int c4= 40;
    
    unsigned int foo = (c4 << 0) | (c3 << 8) | (c2 << 16) | (c1 << 24);
    int port = 4000;
    tcp_pair miguesIp(4000, foo);

    foo = (15 << 0) | (50 << 8) | (2 << 16) | (1 << 24);
    tcp_pair DariosIP(3000, foo);
    
    foo = (20 << 0) | (10 << 8) | (3 << 16) | (7 << 24);
    tcp_pair TonixIP(8080, foo);
  


    std::unordered_set <tcp_pair, MatrixHashTCP,ipEqual> MySet_s;

    MySet_s.insert(miguesIp);
    MySet_s.insert(DariosIP);
    MySet_s.insert(TonixIP);
    
    
    std::cout<<MySet_s.size()<<std::endl;
   
    return 0;
}
