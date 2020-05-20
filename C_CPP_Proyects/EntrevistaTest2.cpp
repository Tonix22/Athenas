#include <iostream>
#include <vector>
#include <string>
using namespace std;

void vectorIndef(vector<char> &v){

    int i=v.size()-1;
    while(v[i]=='9' && i>0){
        v[i]='0';
        i--;
    }
    if(i==0){
        v[i]='0';
        v.insert(v.begin(), '1');
    }else{
        v[i]++;
    }

}

int main(int argc, char const *argv[])
{

    vector<char> v { {'9', '9', '9', '9', '9', '9', '9'} };

    vectorIndef(v);

    for(auto &it:v){
        cout << it << ", ";
    }
    cout << endl;
    
    return 0;
}
