#include "skiplist.h"

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
void delete_node(Node** temp)
{
    (*temp)->left  = NULL;
    (*temp)->right = NULL;
    (*temp)->up    = NULL;
    (*temp)->down  = NULL;
    free(*temp);
    *temp = NULL;  
}
void unlink_node(Node* temp)
{
    temp->left->right = temp->right;
    temp->right->left = temp->left;
}
