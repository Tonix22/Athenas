#include <iostream>
#include <string>
#include "class.hpp"
using namespace std;


using IntStack = Stack<int>;//other way to use alias
int main(int argc, char const *argv[])
{

    IntStack StackOfOnts;
    Stack<string> stringStack;
    StackOfOnts.push(7);
    stringStack.push("hello");
    std::cout << StackOfOnts.top() << std::endl;
    std::cout << stringStack.top() << std::endl;
    return 0;
}
