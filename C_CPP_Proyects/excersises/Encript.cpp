#include <iostream>
#include <string>
//the quick brown fox jumps over the lazy dog
//qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald

// HOLA
// IPMB

// a = 0
// b = 1
// c = 2
// d = 3

int main(int argc, char const *argv[])
{
    char caracter ;//ascii 97
    const char *ptr;
    std::string palabra = "qeb nrfzh yoltk clu grjmp lsbo qeb ixwv ald";
    //std::cin>>palabra;
    ptr = palabra.c_str();

    for(char c: palabra)
    {
        if(c != ' ')
        {
            c = c-'a'; // normalización
            c = (c+3)%26; // %26 // z = 122 [0-26]
            c +='a';
            std::cout<<c;
        }
        else
        {
            std::cout<<" ";
        }
    }
    std::cout<<std::endl;

    //Milllares, Centenas, Decenas, Unidades
    //  1           2         3       4
    //                      %100    %10
  //1512
     /*1512 % 10; 
       1512 / 10;*/
    
    /* 101010 & 1*/

    // 1010
    // 


    /*
    // a -> 0
    if(caracter < 'A' && caracter < 'Z')
    {
        std::cout<<"mayuscula"<<std::endl;
    }
    if(caracter < 'a' && caracter < 'z')
    {
        std::cout<<"miniscula"<<std::endl;
    }
    int value = caracter-'a';
    std::cout<<value<<std::endl;
    */
    return 0;
}
