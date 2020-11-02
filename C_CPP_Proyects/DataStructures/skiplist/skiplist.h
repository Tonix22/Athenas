#ifndef SKIPLIST_H
#define SKIPLIST_H

typedef struct node
{
    struct node* right;
    struct node* left;
    struct node* down;
    struct node* up;
    int val;
}Node;
bool find(int val, Node** it);

#endif