#include <memory>
#include <iostream>
using namespace std;
unique_ptr<int> increment_value(unique_ptr<int>& ref)
{
    (*ref)++;
    return static_cast<unique_ptr<int>&&>(ref);
}

int main(int argc, char const *argv[])
{
    std::unique_ptr<int> smart_int(new int(5));
    std::cout<<"smart_int: "<<*smart_int <<endl;
    smart_int = increment_value(smart_int);
    std::cout<<"smart_int: "<<*smart_int <<endl;
    return 0;
}
