#include <string>
#include <iostream>
using namespace std;
#define ASCII_OFSSET 97
#define ALPHABET_SIZE 24
#define REAL_POS p[i]-ASCII_OFSSET
#define GLORY "YUSH"
#define FAIL "Ño"
struct Hash{
    bool ascii[ALPHABET_SIZE]={0};

    bool repeated(string p)
    {
        int word_size = p.length();
        for(int i=0; i<word_size; i++){
            if(ascii[REAL_POS]){
                printf(GLORY);
                return true;
            }
            else{
                ascii[p[i]-ASCII_OFSSET] = true;
            }
        }

        printf(FAIL);
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Hash test;
    test.repeated("martin");

    return 0;
}
