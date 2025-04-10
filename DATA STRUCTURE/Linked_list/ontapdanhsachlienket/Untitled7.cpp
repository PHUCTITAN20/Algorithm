#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;

void makenullList (List *pL){
	(*pL)=(struct Node*)malloc(sizeof (struct Node));
	(*pL)->Next=NULL;
}

void append(ElementType X, List *pL){
	Position P=(*pL);
	while (P->Next!=NULL){
		P=P->Next;
	}
	Position t;
	t=(struct Node*)malloc(sizeof (struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}


void addfirst(ElementType X, List *pL){
	Position t;
	t=(struct Node*)malloc(sizeof (struct Node));
	t->Element=X;
	t->Next=(*pL)->Next;
	(*pL)->Next=t;
}


void readList (List *pL){
	makenullList(pL);
	int N;
	ElementType X;
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		scanf("%d",&X);
		append(X,pL);
	}
}


void printList(List L){
	Position P=L;
	while (P->Next!=NULL){
		printf("%d ",P->Next->Element);
		P=P->Next;
	}
	printf("\n");
}

int member(ElementType X, List L){
	Position P;
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element) found=1;
		else
			P=P->Next;
	}
	return found;
}


void  printeven_average(List L){
	Position P=L;
	float S=0;
	int count=0;
	while (P->Next!=NULL){
		if ((P->Next->Element)%2==0){
			S=S+P->Next->Element;
			count++;
			printf("%d ",P->Next->Element);	
		}
		P=P->Next;
	}
	printf("\n");
	printf("%.3f",S/count);

}

int main(){
	List L;
	readList(&L);
	printList(L);
	printeven_average(L);
	return 0;
}


