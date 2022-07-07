#include "Hash_DarioHeader.h"

void DectoBin(int dato)
{
    int i;
    for (i = 1U << 7U; i > 0U; i>>=1U)
    {
        printf("%s",(dato&i) ? "1":"0");
    }
}


struct MatrixHashTCP{
private:
    std::vector<int> hashMatrix;
    const int hashSize = 4; // 
    const int number_of_bits_in_key = 8;
    int rows = 4;

public:


    MatrixHashTCP() {
        generate_matrix(hashSize, number_of_bits_in_key);
    }

    size_t operator()(const tcp_pair& tcp_pair) const
    {
        int key = tcp_pair.ip_addr.oct[0];// 192.168.0.1
        int mult = 0;
        int hash_index = 0;
        // 4*4*31 = 496 ciclos de reloj
        // 0(1)
        std::cout<<"key insert: "<<std::endl;
        DectoBin(key);
        std::cout<<" : 0x"<<key<<std::hex<<std::endl;
        //for(int i = 0; i < this->rows; ++i) // 4 times
        //{
        for(int k = 0, mask=1, res=0; k < rows; ++k, hash_index <<=1, mask = 1, res = 0) // 4 times
        {
            // 1010 & 1111 = 1 xor 0 xor 1 xor 0 -> xor
            mult = (hashMatrix[k] & key);
            //count the number of ones and check even or odd
            hash_index |=  __builtin_popcount(mult)&1; // concatenate last bit
        }
        //}
        std::cout<<"hash_index: "<<std::endl;       
        DectoBin(hash_index);
        std::cout<<" : 0x"<<hash_index<<std::hex<<std::endl;
        
        return hash<int>()( hash_index );
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
        std::cout<<"matrix begin"<<std::endl;
        for(int& n : hashMatrix)
        {
            DectoBin(n);
            std::cout<<" : 0x"<<std::hex<<n<<std::endl;
            
        }
        std::cout<<"matrix end"<<std::endl;
    }

};