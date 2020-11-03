#ifndef NODE_H
#define NODE_H

typedef struct node
{
    struct node* right;
    struct node* left;
    struct node* down;
    struct node* up;
    int val;
}Node;

void insert_node(Node** temp, Node* it, int* val);
void delete_node(Node** temp);
void unlink_node(Node* temp);

#endif