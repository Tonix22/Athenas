
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>
using namespace std;
int main(int argc, const char** argv) 
{
    vector<int> values ={1,2,3,4,5,6,7,8,9};
    set<int> first;
    auto it = find_if(values.begin(),values.end(),[&](int value){ 
        first.insert(value);
        return value>3;});
    for (auto it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    
    return 0;
}