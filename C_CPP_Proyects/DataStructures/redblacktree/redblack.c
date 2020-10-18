#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "redblack.h"

void left_rotate(tree_t* Tree, node_t* x)
{
    node_t* y = x->right;
    x->right = y->left;
    if (y->left != NULL){y->left->p = x;}

    y->p = x->p;// connect y to parent 
    
    if(x->p == NULL) // if x is the root
    {
        Tree->root = y;    // y becomes the root
    }
    //connect parent to Y 
    else if (x == x->p->left)
    {
        x->p->left = y;
    }
    else
    {
        x->p->right = y;
    }
    //once rotated link y and x 
    y->left = x;
    x->p    = y;
}
void right_rotate(tree_t* Tree,node_t* y)
{
    node_t* x = y->left;
    y->left = x->right;
    if(x->right != NULL){ x->right->p = y;}

    x->p = y->p;// connect y to parent 
    
    if(y->p == NULL) // if y is the root
    {
        Tree->root = x;    // y becomes the root
    }
    //connect parent to X 
    else if (y == y->p->left)
    {
        y->p->left = x;
    }
    else
    {
        y->p->right = x;
    }
    //once rotated link y and x 
    x->right = y;
    y->p     = x;

}
void create_node(node_t** z, int key)
{
    *z = (node_t*) malloc(sizeof(node_t));
    (*z)->left  = NULL;
    (*z)->right = NULL;
    (*z)->p     = NULL;
    (*z)->key   = key;
    (*z)->color = Black;
}
void destroy_node(node_t** z)
{
    free(*z);
}
void insertion(tree_t* Tree, node_t* z)
{
    node_t* y = Tree->nil;
    node_t* x = Tree->root;
    while( x!=Tree->nil) 
    {
        y = x;
        if(z->key < x->key)
        {
            x = x->left;
        }
        else{x = x->right;}
    }
    z->p = y;
    if( y == Tree->nil)
    {
        Tree->root = z;
    }
    else if (z->key <  y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    z->right = Tree->nil;
    z->left  = Tree->nil;
    z->color = Red;
    rb_insert_fixup(Tree,z);
}
void rb_insert_fixup(tree_t* Tree, node_t* z)
{
    node_t* y;
    while(z->p->color == Red)
    {
        if(z->p == z->p->p->left)
        {
            y = z->p->p->right;
            if(y->color == Red) // recolor only Case 1
            {
                z->p->color    = Black;
                y->color       = Black;
                z->p->p->color = Red; // a red one has to black childs
            }
            else if (z == z->p->right) // left rotate Case 2
            {
                z = z->p;
                left_rotate(Tree,z);
            }
            else // right rotate Case 3
            {
                z->p->color = Black;
                z->p->p->color = Red;
                right_rotate(Tree,z->p->p);
            }
        }
        else // z->p == z->p->p->right
        {
            y = z->p->p->left;
            if(y->color == Red) // recolor only Case 1
            {
                z->p->color    = Black;
                y->color       = Black;
                z->p->p->color = Red; // a red one has to black childs
            }
            else if (z == z->p->left) // left rotate Case 2
            {
                z = z->p;
                right_rotate(Tree,z);
            }
            else // right rotate Case 3
            {
                z->p->color    = Black;
                z->p->p->color = Red;
                left_rotate(Tree,z->p->p);
            }
        }
    }
    Tree->root->color = Black;
}
bool find_value(tree_t* Tree,int value)
{
    node_t* x = Tree->root;
    while( x->key != value) 
    {
        if(value < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
        if(x == Tree->nil)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    tree_t tree;
    node_t* nil;
    create_node(&nil,0);
    nil->color = Black;
    
    tree.nil  = nil;
    tree.root = nil;

    node_t* nodes[10];
    int values[10] = {7,5,8,1,2,14,15,11,4,9};
    for(int i=0;i<10;i++)
    {
        create_node(&(nodes[i]),values[i]);
        insertion(&tree,nodes[i]);
    }
    for(int i=0;i<10;i++)
    {
        destroy_node(&(nodes[i]));
    }

    return 0;
}
