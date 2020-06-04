#include <iostream>
int main(int argc, char const *argv[])
{
    int n = 300000;
    int c = 2;

    for (int i = 1; i <=n; i *= c) {
        std::cout<< i <<std::endl;
    }
    for (int i = n; i > 0; i /= c) {
        std::cout<< i << std::endl;
    }
    return 0;
}
