
#include <iostream>

using namespace std;
class node
{
    public:
    node* next;
    int value;
    node(node* _next,int _value):next(_next),value(_value) {};
};


void print_list(node nd)
{
    while(nd.next!=nullptr)
    {
        cout<<nd.value<<endl;
        nd = *(nd.next);
    }
    cout<<nd.value<<endl;
}

void reversed_list(node* head)
{
    node* previous = nullptr;
    node* current  = head; 
    node* next     = head->next;
    while(next!=nullptr)
    {
        current->next = previous;
        previous      = current;
        current       = next;
        next          = next->next;
    }
    current->next = previous;
    previous      = current;
}

int main(int argc, char const *argv[])
{
    
    node a = node(nullptr,3);
    node b = node(&a,7);
    node c = node(&b,1);
    node d = node(&c,8);
    node e = node(&d,5);
    node f = node(&e,11);
    print_list(f);
    cout<<"reversed"<<endl;
    reversed_list(&f);
    print_list(a);
    return 0;
}
