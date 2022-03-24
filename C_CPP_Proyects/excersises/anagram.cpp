#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;


bool isAnagram(vector<string>& word)
{
    map <char, int> bucket;
    
    //generate firs work bucket
    for(auto letter : word[0])
    {
        bucket[letter]++; //increment counter/frequency
    }
    for(int i=1; i < word.size(); i++) // over the words
    {
        map<char,int> temp = bucket;
            
        for(auto letter : word[i])
        {
            temp[letter]--;
        }
        //buckts are 0 ?
        for(auto it =temp.begin();it!=temp.end();it++)
        {
            // it->first; // key
            // it->second; // value
            if(it->second != 0)
            {
                return false;
            }
        }
    }

    return true;
} 

int main(int argc, char const *argv[])
{
    std::vector<std::string> anagram1{"loop","polo","pool"};

    std::vector<std::string> anagram2{"madam curie","radium came"};
    
    std::vector<std::string> anagram3{"carets","caters","caster",
                                      "Krates","reacts","recast",
                                      "traces"};

    printf("%s\r\n",(isAnagram(anagram3))?("Is anagram"):("POS NO"));

    return 0;
}
