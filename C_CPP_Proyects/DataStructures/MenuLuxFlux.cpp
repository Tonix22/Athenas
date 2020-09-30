#include <iostream>
using namespace std;

//Definitions
typedef void (*foo_ptr)();
typedef enum{
    IDLE,
    RITH,
    CIRC,
    LEVEL,
    WIFI,
    SYNC,
    ARRAYSIZE,
}Screen_t;

//Prototypes
void idle_func();
void rith_func();
void circ_func();
void leve_func();
void wifi_func();
void sync_func();

template <typename T> 
struct Node
{
    T val;
    Node* next;
};

//class declaration
class DispMenu
{
    Node<foo_ptr> screens[ARRAYSIZE] = 
                        { 
                            {idle_func,&(screens[RITH] ) },
                            {rith_func,&(screens[CIRC] ) },
                            {circ_func,&(screens[LEVEL]) },
                            {level_func,&(screens[WIFI] ) }, 
                            {wifi_func,&(screens[IDLE] ) },
                            {sync_func,&(screens[IDLE] ) },
                        };
    Node<foo_ptr>* screen = &(screens[IDLE]);

    public:
    DispMenu& operator++(int)
    {
        screen = screen->next;
        return *this;
    }
    //a way to acces to a function by index
    void operator[](std::size_t idx)
    {
        this->screen = &(screens[idx]);//update screen
        screens[idx].val(); //go to screen
    }
    void operator ( ) () // Menu()
    {
        this->screen->val();
    }
};

// functions
void idle_func(){
    cout<<"idle_func"<<endl;
}

void rith_func(){
    cout<<"rith_func"<<endl;
}

void circ_func(){
    cout<<"circ_func"<<endl;
}

void level_func(){
    cout<<"level_func"<<endl;
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

    /* 
    This is a way to acces menu directly by index, 
    used to branch to a specific menu function. 
    For example when a button is pressed by 3
    seconds, the fucntion call will be directly like this.
    */
   // Menu[SYNC];// Acces directly to function


    for(int i=0; i< ARRAYSIZE +3 ;i++)
    {
        Menu(); // Jump to function like this
        Menu++; // Incremt position like this
    }     
   
    return 0;
}