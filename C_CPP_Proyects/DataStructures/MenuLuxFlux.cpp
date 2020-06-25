#include <iostream>
using namespace std;

struct Node
{
    void (*foo)();
    Node* next;
    Node& operator++()
    {
        *this = *(this->next);
        return *this;
    }
};

//Prototypes
void idle_func();
void rith_func();
void circ_func();
void leve_func();
void wifi_func();
void sync_func();

Node* Rooth = NULL;
Node* END   = NULL; // helper pointer
Node* aux   = NULL;

typedef enum{
    IDLE,
    RITH,
    CIRC,
    LEVEL,
    WIFI,
    SYNC,
    ARRAYSIZE,
}Menu_t;


Node menu[ARRAYSIZE] = {{idle_func,&(menu[RITH])},
                        {rith_func,&(menu[CIRC])},
                        {circ_func,&(menu[LEVEL])},
                        {leve_func,&(menu[WIFI])}, 
                        {wifi_func,&(menu[SYNC])},
                        {sync_func,&(menu[IDLE])},

                       };


void idle_func(){
    cout<<"idle_func"<<endl;
}

void rith_func(){
    cout<<"rith_func"<<endl;
}

void circ_func(){
    cout<<"circ_func"<<endl;
}

void leve_func(){
    cout<<"leve_func"<<endl;
}

void wifi_func(){
    cout<<"wifi_func"<<endl;
}

void sync_func(){
    cout<<"sync_func"<<endl;
}



int main(int argc, char const *argv[])
{
    Node* curr_screen = &(menu[IDLE]);
    curr_screen->foo();
    curr_screen++;

    curr_screen->foo();
    curr_screen++;
     
    curr_screen->foo();
    curr_screen++;

     curr_screen->foo(); 
    curr_screen++;   

    curr_screen->foo();
    curr_screen++;

    curr_screen->foo();
    curr_screen++;

    curr_screen->foo();
    curr_screen++;

    return 0;
}