#ifndef Redblack_h
#define Redblack_h
#include <stdbool.h>

typedef enum
{
    Black = 0,
    Red   = 1,
}Paint;

typedef struct node
{
    struct node* left;
    struct node* right;
    struct node* p;
    int key;
    Paint color; 
}node_t;

typedef struct Tree
{
    node_t* nil;
    node_t* root;
}tree_t;


void left_rotate(tree_t* Tree, node_t* x);
void right_rotate(tree_t* Tree,node_t* y);
void create_node(node_t** z, int key);
void destroy_node(node_t** z);
void insertion(tree_t* Tree, node_t* z);
void rb_insert_fixup(tree_t* Tree, node_t* z);
bool find_value(tree_t* Tree,int value);

#endif