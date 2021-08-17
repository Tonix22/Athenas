//Input

//["eat","tan","tea","ate","nat","bat"]

//output

//["ate","eat","tea"]
//["nat,"tan"]
//["bat"]


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

void intersection()
{

    std::vector<string> l1 {"eat", "tan", "tea", "ate", "nat","bat"};
    std::vector<string> words;
    std::set <string> myset;
    int suma=0, suma2=0;
    //l1[palabra][caracter]
    int i,j;
    for( i=0; i < l1.size(); i++){

        for( j=0; j<l1[i].size(); j++){
            suma =  suma +l1[i][j];
            
        }
        
        printf("%i\n",suma);
        suma=0;
    }
    
}

int main(int argc, char const *argv[])
{
    intersection();
}