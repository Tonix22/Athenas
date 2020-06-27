#include <iostream>
using namespace std;

struct Node
{
    void (*foo)();
    Node* next;
};

class DispMenu
{
    public:
    Node* screen;
    DispMenu& operator++(int)
    {
        screen = screen->next;
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


typedef enum{
    IDLE,
    RITH,
    CIRC,
    LEVEL,
    WIFI,
    SYNC,
    ARRAYSIZE,
}Screen_t;


Node screens[ARRAYSIZE] = { {idle_func,&(screens[RITH]) },
                            {rith_func,&(screens[CIRC]) },
                            {circ_func,&(screens[LEVEL])},
                            {leve_func,&(screens[WIFI]) }, 
                            {wifi_func,&(screens[SYNC]) },
                            {sync_func,&(screens[IDLE]) },
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
    DispMenu Menu;
    Menu.screen =  &(screens[IDLE]);

    for(int i=0; i< ARRAYSIZE +1 ;i++)
    {
        Menu.screen->foo();
        Menu++;
    }     
   

    return 0;
}