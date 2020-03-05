#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class graph{

    vector<int> heigths;

    public:
    graph(vector<int> h){
        heigths=h;
        heigths.push_back(0);
    }

    void printVector(){

        for(auto i=heigths.begin(); i!=heigths.end(); i++){
            
            cout << *i << " ";

        }

        cout << endl;

    }


    int biggestArea(){
        
        int max=0;
        int area;
        stack<int> index;
        stack<int> values;

        index.push(0);
        values.push(heigths[0]);
        
        for(int i=1; i<heigths.size(); i++){

            if(heigths[i]>values.top()){
                
                index.push(i);
                values.push(heigths[i]);

            }else if(heigths[i]<values.top()){

                area=(i-index.top())*values.top();

                if(area>max){
                    max=area;
                }

                index.pop();
                values.pop();

            }

        }
        
        return max;
    }

};

int main(int argc, char const *argv[]){

    vector<int> test {1, 2, 1, 3, 4, 3, 1, 1, 1, 1};
    graph g(test);
    g.printVector();
    cout << "Area: " << g.biggestArea();

    return 0;
}
