#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h> 
#include "skiplist.h"

#define is ==
#define not !

Node* Head = NULL;

char flip_coin(void)
{
    static char bit=0;
    static int rd;
    static char val;
    bit%=31;
    if(bit == 0)
    {
        srand(time(0));
        rd =  rand();
        printf("rd: %X\r\n",rd);
    }
    val = (rd&1<<bit)>>bit++;
    printf("%s\r\n",val?("Sello"):("Aguilla"));
    return val;
 
}

void create_level(Node** level_head)
{
    *level_head               = malloc(sizeof(Node));
    (*level_head)->val        = INT_MIN;
    (*level_head)->right      = malloc(sizeof(Node));
    (*level_head)->right->val = INT_MAX;
}
void init_structure(void)
{
    create_level(&Head);
}   

void insert_node(Node** temp, Node* it, int* val)
{
    *temp = malloc(sizeof(Node));
    (*temp)->val   = *val;
    (*temp)->right = it->right;
    (*temp)->right->left = *temp;
    it-> right           = *temp;
    (*temp)->left        = it;
    (*temp)->up          = NULL;
    (*temp)->down        = NULL;
}

void random_level_up(Node* iterator)
{
    bool  insert   = false;
    Node* temp     = NULL;

    Node* levelup  = iterator;
    int val        = iterator->val;

    //Level with coin
    while(iterator != Head && flip_coin())
    {
        insert   = false;
        while(insert is false)
        {
            if(iterator->left->up == NULL)
            {
                iterator = iterator->left;
                if(iterator->val == INT_MIN)
                {
                    create_level(&Head);
                    Head->down   = iterator;
                    iterator->up = Head;
                    iterator = Head;
                    insert_node(&temp,iterator,&val);
                    temp->down        = levelup;
                    levelup->up       = temp;
                    insert  = true;
                }
            }
            else
            {
                iterator = iterator->left->up;
                while(insert is false)
                {   
                    if(val > iterator->right->val) 
                    {   // imposible to reach infinity
                        iterator = iterator->right;
                    }
                    else
                    {
                        insert_node(&temp,iterator,&val);
                        temp->down        = levelup;
                        levelup->up       = temp;
                        levelup  = temp;
                        iterator = temp;
                        temp    = NULL;
                        insert  = true;
                    }
                }
            }
        }
    }
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

void erase_node(int val)
{
    Node* iterator = NULL;
    Node* temp     = NULL;
    Node* lvl_del  = NULL;
    if(find(val,&iterator))
    {
        while(iterator != NULL)
        {
            temp     = iterator;
            iterator = iterator->down;

            temp->left->right = temp->right;
            temp->right->left = temp->left;

            //delete level if needed it
            if(temp->right->val == INT_MAX && temp->left->val == INT_MIN)
            {
                lvl_del = temp->right;
                lvl_del->left = NULL;
                free(lvl_del);
                lvl_del = NULL;

                lvl_del  = temp -> left;
                if(lvl_del->down !=NULL)
                {
                    Head     = lvl_del-> down;
                    Head->up = NULL;
                    lvl_del->down = NULL;
                    free(lvl_del);
                    lvl_del = NULL;
                }

            }
            temp->left  = NULL;
            temp->right = NULL;
            free(temp);
            temp = NULL;  
        }
    }
}



int main(int argc, char const *argv[])
{
    init_structure();
    insert(2);
    insert(18);
    insert(5);
    insert(7);
    insert(10);

    Node* it;
    find(18,&it);
    find(17,&it);
    printf("it->val: %d\r\n",it->val);
    
    erase_node(10);
    erase_node(2);
    erase_node(18);
    erase_node(5);
    erase_node(7);
    return 0;
}
