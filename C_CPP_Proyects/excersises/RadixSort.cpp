#include <iostream>
#include <vector>
using namespace std;

// (N&1<<i)>>i;
void radix_sort(std::vector<int>& values,int bit_size)
{
    for(int b_size = 0; b_size<bit_size; b_size++)
    {
        std::vector<int> zeros;
        std::vector<int> ones;
        for(int& v: values)
        {
            // v -> values[i]
            if((v & (1<<b_size) )>>b_size) // if 1      B->(1)
            {
                ones.push_back(v);
            }
            else // if 0  (0)<-(1)
            {
                zeros.push_back(v);
            }
        }
        values.clear();
        //pegar el de ceros
        values.insert(values.end(),zeros.begin(),zeros.end());
        //pegar el de unos
        values.insert(values.end(),ones.begin(), ones.end());
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> calis {12,6,5,9};
    radix_sort(calis, 4);
    for(int& v: calis)
    {
        std::cout<<v<<endl;
    }
    return 0;
}
