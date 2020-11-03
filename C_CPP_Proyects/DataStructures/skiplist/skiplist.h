#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "node.h"

#define is ==
#define not !


bool find(int val, Node** it);
void erase_node(int val);
bool find_value(int val);
bool find(int val, Node** it);
void insert(int val);
void random_level_up(Node* iterator);
void insert_node(Node** temp, Node* it, int* val);
void init_structure(void);
void create_level(Node** level_head);
char flip_coin(void);

#endif