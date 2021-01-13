#ifndef _FREQUENCY_H_
#include <stdio.h>
#define NUM_LETTERS 26

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
char* word;
boolean flag;
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;
node* newNode();
#endif