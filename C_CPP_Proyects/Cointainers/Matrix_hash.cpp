#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>
#include "Hash_DarioHeader.h"


struct MatrixHashTCP{
private:
    std::vector<int> hashMatrix;
    const int hashSize = 10; // 
    const int number_of_bits_in_key = 32;
    int rows = 0;

public:

    MatrixHashTCP() {
        generate_matrix(hashSize, number_of_bits_in_key);
    }

    size_t operator()(const tcp_pair& tcp_pair) const
    {
        int key = tcp_pair.ip_addr.ip;
        int mult = 0;
        int res  = 0;
        int hash_index = 0;

        for(int i = 0; i < this->rows; ++i)
        {
            
            for(int k = 0; k < rows; ++k, hash_index <<=1)
            {
                // 1010 & 1111 = 1 xor 0 xor 1 xor 0 -> xor
                mult = (hashMatrix[i] & key);
                int mask = 1;
                for(int i = 0;i<number_of_bits_in_key; i++, mask <<= 1)
                {   
                    res ^= (mult & mask) >> i;// 0 or 1
                }
                hash_index |= res; // concatenate last bit
            }
        }        
    
        // https://stackoverflow.com/questions/5889238/why-is-xor-the-default-way-to-combine-hashes
        res ^= (tcp_pair.port + 0x9e3779b9 + (res << 6) + (res >> 2));
        return hash<int>()( res );
    }
    int RandomNumber () { return (std::rand()%100); }

    void generate_matrix(int rows,int number_bits)
    {
        // Generate an array with random numbers
        // 2^Rows = Hash Table size
        // size of array element must be equal to key size.
        this->rows = rows;
        this->hashMatrix.resize(this->rows);
        // fill with random values in range

        std::generate(hashMatrix.begin(), hashMatrix.end(), [&](){ return ((int)rand() % ((1<<(number_bits-1)) - 1));});
        /*
        1 0 1 1 1     key: 1 0 1 1 1   value : 1 1 0 0
        1 0 1 0 1
        1 0 0 1 0
        0 0 0 1 1
        */
    }

};

struct ipEqual {
public:
    bool operator()(const tcp_pair& p1, const tcp_pair& p2) const
    { // if both the lengths are equal then return True else
      // False
      cout<<"we collide"<<endl;
      return (p1.ip_addr.ip == p2.ip_addr.ip);
    }
};

int main(int argc, char const *argv[])
{
    srand(time(0));
    unsigned int c1= 10;
    unsigned int c2= 47;
    unsigned int c3= 30;
    unsigned int c4= 20;
    
    unsigned int foo = (c4 << 0) | (c3 << 8) | (c2 << 16) | (c1 << 24);
    int port = 4000;
    tcp_pair miguesIp(4000, foo);
    
    cout << miguesIp;

    std::unordered_set <tcp_pair, MatrixHashTCP,ipEqual> MySet_s;

    MySet_s.insert(miguesIp);

    
   
    return 0;
}
