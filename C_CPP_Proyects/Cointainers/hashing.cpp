#include <set>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct stringEqualbyLen {
public:
    bool operator()(const string& str1,
                    const string& str2) const
    { // if both the lengths are equal then return True else
      // False
        cout<<"we collide"<<endl;
        if (str1.length() == str2.length())
            return true;
        else
            return false;
    }
};
struct StringHashByLen {
public:
    size_t operator()(const string& str) const
    {
        int string_size = str.length();
        return hash<int>()(string_size);
    }
};
struct StringHashByPos {
public:
    size_t operator()(const string& str) const
    {
        int string_size = str.length();
        unsigned long pow  = 1;
        unsigned long acum = 0;
        // 2^64
        // 2^10 leq 1k
        // 2^20 leq 1M
        // 2^30 leq 1G
        // 2^40 leq 1T
        // 2^50 leq 1P
        // 2^60 leq 1E  10^18
        // 2^64 leq 16E 

        // max size string 18
        for(int i = 0;i<str.length();i++,pow*=10) 
        {
            acum+= (str[i]-'a')*pow; // remove offsset
        }

        cout<<" "<<acum<<","<<endl;
        
        return hash<int>()(acum);
    }
};

struct StringHashLyFar {
public:
    size_t operator()(const string& str) const
    {
        int string_size = str.length();
        unsigned long acum = 0;
        // max size string 18
        for(int i = 0;i<str.length();i++) 
        {
            acum+= (str[i]-'a'+1); // remove offsset
        }
        cout<<" "<<acum<<","<<endl;
        
        return hash<int>()(acum);
    }
};
struct stringEqual {
public:
    bool operator()(const string& str1,const string& str2) const
    { // if both the lengths are equal then return True else
      // False
      cout<<"we collide"<<endl;
      return (str1 != str2);
    }
};

int main(int argc, char const *argv[])
{
    unordered_set<string, StringHashLyFar,stringEqual>stringset;
    stringset.insert("aba");
    stringset.insert("d");
    stringset.insert("aba");
    cout << "lista de elementos : " << endl;
    for (string str : stringset)
        cout << str << endl;

    return 0;
}

