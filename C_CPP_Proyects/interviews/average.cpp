#include <utility>
#include <vector>
#include <map>
#include <limits.h>
#include <algorithm>
#include <cmath>

using namespace std;


int highestScore(vector<vector<string> > &A) {
    
    int max_p = INT_MIN;
    map<string,pair<int,int>> avg;
    for(int i=0;i<A.size();i++)
    {
        if (avg.find(A[i][0]) == avg.end())
        {
            avg[A[i][0]] = make_pair(stoi(A[i][1]),1); // buil new key
        }
        else // add values and cnt
        {
            avg[A[i][0]].first+=stoi(A[i][1]);
            avg[A[i][0]].second++;
        }
    }
    for (auto iter = avg.begin(); iter != avg.end(); ++iter){
        
        max_p = max(max_p,iter->second.first/iter->second.second);
    }
    
    return max_p;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
