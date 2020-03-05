#include <stdio.h>

class Map{

    bool** coins;

    typedef struct position{
        int x, y;
    } charPos, coinPos;

    public:

    Map::Map(int s){

        coins=new bool*[s];

        for(int i=0; i<x; i++){
            
            coins[i]=new bool[s];

        }

    }

    Map::genRandCoins(int qty){
        
        srand(time(null));

        int ca;
        int cb;

        for(int i=0; i<qty; i++){
            ca=rand()%10;
            cb=rand()%10;

            this.coins[ca][cb]=1;

        }

    }

    Map::genCharater(position input){

        memcpy(this.charPos, input, sizeof(position));

    }

    coinPos Map::findCoin(){

        coinPos coordenada;

        

        return coordenada;
        
    }

}

int main(int argc, char const *argv[])
{
    

    return 0;
}

