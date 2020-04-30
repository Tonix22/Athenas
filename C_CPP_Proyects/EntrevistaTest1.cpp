#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    stack<int> hotcake;

    for(int x: v){
        hotcake.push(x);
    }

    int i=0;
    while(!hotcake.empty()){
        v[i]=hotcake.top();
        cout << hotcake.top() << ", ";
        hotcake.pop();
        i++;
    }
    cout << endl;

    pair<int, int> p;
    vector<int> v2{0, 0};
    for(int i=0; i<v.size(); i++){
        v2[(i%2==1)]+=v[i];

        /*
        if(i%2){
            p.second+=v[i];
        }
        else{
            p.first+=v[i];
        }
        */
    }
    cout << v2[0] <<", " << v2[1] << endl;

    return 0;
}
