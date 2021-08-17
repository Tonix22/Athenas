#include "level.h"
#include "skiplist.h"

extern Node* Head;

char flip_coin(void)
{
    static char bit=0;
    static int rd;
    static char val;
    bit%=31;
    if(bit == 0)
    {
        srand(clock());
        rd =  rand(); // 0--2^32 45633432342 = 101010101111010101
    }
    val = (rd&1<<bit)>>bit++;
    return val;
}

void create_level(Node** level_head)
{
    *level_head               = malloc(sizeof(Node));
    (*level_head)->val        = INT_MIN;
    (*level_head)->right      = malloc(sizeof(Node));
    (*level_head)->right->val = INT_MAX;
    (*level_head)->up   = NULL;
    (*level_head)->down = NULL;

}
void delete_level(Node* temp)
{
    Node* lvl_del  = NULL;
    if(temp->left->down !=NULL)
    {
        lvl_del = temp->right;
        lvl_del->left = NULL;
        free(lvl_del);
        lvl_del = NULL;

        lvl_del  = temp -> left;
        Head     = lvl_del-> down;
        Head->up = NULL;
        lvl_del->down = NULL;
        free(lvl_del);
        lvl_del = NULL;
    }else
    {
        Head = temp->left;
    }
    
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
