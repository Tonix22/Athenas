#ifndef LEVEL_H
#define LEVEL_H
#include "skiplist.h"
#include <time.h>
#include <limits.h>

char flip_coin(void);
void create_level(Node** level_head);
void delete_level(Node* temp);
void random_level_up(Node* iterator);

#endif