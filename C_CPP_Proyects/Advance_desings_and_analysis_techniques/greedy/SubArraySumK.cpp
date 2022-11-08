#include <vector>
#include <iostream>     // std::cout
#include <numeric>      // std::partial_sum
#include <algorithm>
#include <map>

using namespace std;
int myop (int x, int y) {return x+y+1;}

int subarraySum(vector<int>& nums, int k) 
{
    int counter = 0;
    int size   = nums.size();
    vector<int> result (size);
    map<int,int> sum_si;
    sum_si[0]++;
    
    partial_sum (nums.begin(), nums.end(), & result[0]);//Sumas acumuladas
    for (int i = 0; i < size; i++)
    {
        // Si - k = Sj
        if(sum_si.find(result[i] - k) != sum_si.end())
        {
            counter+=sum_si[result[i] - k];  
        }
        sum_si[result[i]] ++;  
    }

    return counter;
}

int MiguesubarraySum(vector<int>& nums, int k) 
{
    int size    = nums.size();
    int counter = 0U;

    for(int Iterator = 0U; Iterator<size; Iterator++)
    {
       int Sum = nums[Iterator];
        if(Sum == k)
        {
            counter++;
        }

        for(int Jterator = Iterator + 1; Jterator < size; Jterator++)
        {
            Sum +=nums[Jterator] ;
            if(k == Sum)
            {
                counter++;
            }
            else
            {
                /* MISRA RULE*/
            }
        }
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    
    int res = 0U;
    vector<int> array = {10,2,-2,-20,10};
    int k = -10;
    //vector<int> array = {7,9,10,11,25,5,30};
    //int k = 30;
    //vector<int> array = {1,2,3};
    //int k= 3;
    res   =  subarraySum(array, k);
    std::cout<<"Result: "<<res<<endl;

    return 0;
}
