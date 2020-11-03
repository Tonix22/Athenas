
#include "skiplist.h"
#include "level.h"
#include "node.h"

Node* Head = NULL;

void init_structure(void)
{
    create_level(&Head);
}

//returns true if success, and closeset iterator in search
bool find(int val, Node** it)
{
    Node* iterator = Head;
    while(1)
    {
        if(val < iterator->right->val)
        {
            if(iterator->down!=NULL)
            {
                iterator = iterator->down;
            }else//not found
            {
                *it = iterator; // reference 
                return false;
            }
        }
        else if(val == iterator->right->val)
        {
            iterator = iterator->right;
            *it = iterator; // reference
            return true;
        }
        else{
            iterator = iterator->right;
        }
    }
}

bool find_value(int val)
{
    Node* it;
    return find(val,&it);
}

void insert(int val)
{
    Node* iterator = NULL;
    Node* temp     = NULL;
    
    if(not find(val,&iterator))
    {
        insert_node(&temp,iterator,&val);
        iterator = temp;
    }
    random_level_up(iterator);
}

void erase_node(int val)
{
    Node* iterator = NULL;
    Node* temp     = NULL;
    bool found     = find(val,&iterator);
    //printf("found: %d", found);
    if(found == true)
    {
        while(iterator != NULL)
        {
            //printf("iterator: %p\r\n",iterator);
            temp     = iterator;
            iterator = iterator->down;

            //printf("unlink: \r\n");
            unlink_node(temp);

            //delete level if needed it
            if(temp->right->val == INT_MAX && temp->left->val == INT_MIN)
            {
                //printf("del lvl\r\n");
                delete_level(temp);
                if(temp == NULL)
                    break;
            }
            //printf("delete node \r\n");
            delete_node(&temp);
        }
        //printf("END LOOP\r\n");
    }
}

/*
    gcc -g -fpic -c skiplist.c node.c levels.c -I /usr/include/python3.6
    ld -relocatable levels.o node.o skiplist.o -o skip.o
    gcc -shared -o skiplist.so skip.o
*/

int main(int argc, char const *argv[])
{
    init_structure();
    insert(493);
    insert(599);

    return 0;
}
