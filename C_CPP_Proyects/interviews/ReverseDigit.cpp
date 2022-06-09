#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

void radix(int A,int size)
{
    int digit = 0;
    queue<int> cola;
    for(int i=0;i<size;i++)
    {
                // limit factor      // filter factor
        digit=(int)A%(int)(pow(10,i+1))/(int)pow(10,i);
        printf("%d",digit);
        //cola.push(digit);
    }

    //while(!cola.empty()){
    //    printf("%d",cola.front());
    //    cola.pop();
    //}
}



int main(int argc, char const *argv[])
{
    int data;
    std::cin>>data;
    //1. Convert to string/ Build a string
    string s = to_string(data);
    //2. Transever string with iterator
    //iterator
    
    //for(string::iterator i= s.end(); i >= s.begin(); --i){
    //    print result
    //    printf("%c",*i );
    //    cout << *i <<endl;
    //}
    //cout<<endl;
    //for(string::reverse_iterator i=s.rbegin();i!=s.rend();i++)
    //{
    //    printf("%c",*i );
    //}
    //cout<<endl;
    radix(data, s.length());
    cout<<endl;
    return 0;
}
