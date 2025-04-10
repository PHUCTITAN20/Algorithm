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

void addFirst(ElementType X, List *pL){
	Position t;
	t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=(*pL)->Next;
	(*pL)->Next = t;
}



int member(ElementType X, List L){
	Position P=L;
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element==X) found=1;
		P=P->Next;
	}
	return found;
}



void printList(List L){
	Position P=L;
	while (P->Next!=NULL){
		printf("%d ",P->Next->Element);
		P=P->Next;
	}
	printf("\n");
}


void readList(List *pL){
	int N;
	makenullList(pL);
	ElementType X;
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		scanf("%d",&X);
  		append(X,pL);
	}
}




List intersection(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        if (member(P->Next->Element,L2))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}


//xoa phan tu xuat hien dau tien
void removeFirst(List *pL){
	Position t;
	//t=(struct Node*)malloc(sizeof (struct Node));
	t=(*pL)->Next;
	(*pL)->Next=t->Next;
	free(t);
}

void removeList(ElementType X, List *pL){
	Position P=(*pL);
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element==X) found=1;
		else P=P->Next;
	}
	if (P->Next!=NULL){
        Position t;
		t=P->Next;
		P->Next=t->Next;
		free(t);
	}
}

Position locate(ElementType X, List L){
	Position P=L;
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element==X) found=1;
		else P=P->Next;
	}
	return P;
}

void removeAll(ElementType X, List *pL){
	Position P=locate(X,*pL);
	Position t;
	while (P->Next!=NULL){
 		  {
		  	t=P->Next;
		  	P->Next=t->Next;
		  	free(t);
			  }	
		P=locate(X,*pL); 
	}
}

void 

int main (){
	List L1;
	ElementType X;
	readList(&L1);
	printList(L1);
	printf("Nhap ptu muon xoa: ");
	scanf("%d",&X);
	removeAll(X,&L1);
	printList(L1);
	return 0;
}
