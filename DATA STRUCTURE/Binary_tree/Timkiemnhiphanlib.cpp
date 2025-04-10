#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef int KeyType;
typedef char Tdata;
typedef struct Node
{
	KeyType Key;
	Node* Left;
	Node* Right;
} Node;
typedef struct Node* TTree;

/*=== Tao cay rong ===*/
void MakeNull_Tree(TTree *T)
{
 (*T)=NULL;
}

/*=== Kiem tra cay rong ===*/
int EmptyTree(TTree T)
{
 return (T==NULL);
}














