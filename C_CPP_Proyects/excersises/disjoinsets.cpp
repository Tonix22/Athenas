#include <list>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define les_than <
#define gr8tr_than >

void intersection()
{
    std::set <char> myset;

    std::list<char> l1 {4, 3, 2, 5, 1};
    std::list<char> l2 {3, 2, 8, 10, 56, 1, 22,1};
    std::list<char> intersection;

    //min
    auto min_len_it  = l1.size() les_than l2.size() ? l1.begin() : l2.begin();
    auto min_len_end = l1.size() les_than l2.size() ? l1.end()  : l2.end();
    //max
    auto max_len_it  = l1.size() gr8tr_than l2.size() ? l1.begin() : l2.begin();
    auto max_len_end = l1.size() gr8tr_than l2.size() ? l1.end()  : l2.end();

    for(auto it=min_len_it;it!=min_len_end;it++)
    {
        for(auto it2 = max_len_it; it2 != max_len_end; it2++){
            if(*it == *it2){
                myset.insert(*it);
            }
        }
    }  
    
    for_each(myset.begin(), myset.end(), [](int i){cout << i << ", ";});
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    std::set <char> myset;

    std::list<char> l1 {4, 3, 2, 5, 1};
    std::list<char> l2 {3, 2, 8, 10, 56, 1, 22,1};
    std::list<char> intersection;

    //min
    auto min_len_it  = l1.size() les_than l2.size() ? l1.begin() : l2.begin();
    auto min_len_end = l1.size() les_than l2.size() ? l1.end()  : l2.end();
    //max
    auto max_len_it  = l1.size() gr8tr_than l2.size() ? l1.begin() : l2.begin();
    auto max_len_end = l1.size() gr8tr_than l2.size() ? l1.end()  : l2.end();

    for(auto it=min_len_it;it!=min_len_end;it++){
        myset.insert(*it);
    }  
    for(auto it2 = max_len_it; it2 != max_len_end; it2++){
         
        myset.insert(*it2);
    }
    
    for_each(myset.begin(), myset.end(), [](int i){cout << i << ", ";});
    cout<<endl;
    //3
    //2
    //8
 
    //next -> pop

    return 0;
}


//4->3->2->5->1 ....

//3->2->8->10->56->1->1 ...

//3->2->1


