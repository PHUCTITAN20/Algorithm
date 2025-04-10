//link list
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node *Position;//la con tro tro den Node
typedef Position List;//List co kieu la Position

void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof (struct Node));
	(*pL)->Next=NULL;
}

void insertList(ElementType X, Position P, List *pL){
	struct Node *t;
	t=(struct Node*)malloc(sizeof (struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}


