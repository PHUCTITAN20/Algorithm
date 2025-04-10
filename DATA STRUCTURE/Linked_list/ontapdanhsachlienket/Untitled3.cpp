#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;


//viet ham append khong su dung ham insert

void append (ElementType X, List *pL){
	Position P=(*pL);
	while (P->Next!=NULL){
		P=P->Next;
	}
	struct Node *t=(struct Node*)malloc(sizeof (struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}

int main(){
	List L;
	Position p;
	L=(struct Node*)malloc(sizeof(struct Node));	
	L->Next=NULL;
		
	append(1, &L);
	append(5, &L);
	append(10, &L);
	append(-10, &L);	
	p=L;
	while(p->Next!=NULL)
	{
		printf("%d ",p->Next->Element);
		p=p->Next;
	}
	printf("\n");
}



