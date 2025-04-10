#include <stdio.h>
#include <conio.h>

typedef int tdata;
typedef struct Tnode{
    tdata data;
    struct Tnode *left;
    struct Tnode *right;
}Tnode;

typedef struct Tnode *TTree;

