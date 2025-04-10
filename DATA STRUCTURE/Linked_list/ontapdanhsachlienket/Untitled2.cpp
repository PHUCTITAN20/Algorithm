#include <stdio.h>
#include <cstlib.h>

typedef int ElementType
struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;

void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof (struct Node));
	*pL->Next=NULL;
}


void insertList(ElementType X,Position P, List *pL){
	Position *t;
	t=(struct Node*)malloc(sizeof (struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}


void deleteList(Position P,List *pL){
	if (*pL->Next!=NULL){
		Position t;
		t=P->Next;
		P->Next=t->Next;
		free(t);	
	}
}

//tra ve vi tri cua phan tu x
Position locate(ElementType X, List L){
	Position P=L;
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element==X) found=1;
		else
			P=P->Next;
	}
	return P;
}

//add ptu vao vi tri cuoi cung: Dua con tro den cuoi, gan ptu= P->Next->Element

void append(ElementType X, List *pL){
	Position P=*pL;
	while (P->Next!=NULL)
		  P=P->Next;
	insertList(X,P,pL);	  
}

//them ptu vao dau danh sach: chen no vao giua header va ptu dau tien
void addFirst(ElementType X, List *pL){
	Position *t=(struct Node*)malloc(sizeof (struct Node));
	t->Next=*pL->Next;
	t->Element=X;
	*pL->Next=t;
}

void readList (List *pL){
	int N;
	ElementType X;
	makenullList(pL);
	scanf("%d",&N);
	for (i=1;i<=N;i++){
		scanf("%d",&X);
		append(X,pL);
	}
}

//biet element of node va xoa node do // Khong su dung ham locate
void erase(ElementType X, List *pL){
	Position P=(*pL);
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if(P->Next->Element==X){
			found=1;
			deleteList(P,pL);
		}
		else P=P->Next;
	}
}

//de gon hon ta su dung ham locate

void erase(ElementType X,List *pL){
	Position P=locate(X,*pL);
	if (P->Next!=NULL)
	   deleteList(P,pL);
 	else 
 		printf("Not found!\n"); 	 
}

//removeAll dung de xoa tat ca cac Node co mot gia tri Element xac dinh
void removeAll(ElementType X, List *pL){
	Position P=locate(X,*pL);
	while(P->Next!=NULL){
		deleteList(P,pL);
		P=locate(X,*pL);
	}
}

//Chuan hoa du lieu, xoa cac ptu co Element trung nhau
void normolize(List *pL){
	Position P=(*pL),Q;
	while (P->Next!=NULL){
		Q=P->Next;
		while (Q->Next!=NULL){
			if (Q->Next->Element==P->Next->Element)
			    deleteList(Q,pL);
			else   
   			    Q=Q->Next;   //so di phai co else la boi neu xoa mot ptu roi phai giu nguyen vi tri cua Q.
		}
		P=P->Next;
	}
}

//check member

int member(ElementType X, List L){
	Position P=(*pL);
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element==X) found=1;
		else
			P=P->Next;
	}
	return found;
}

void swap(ElementType *a, ElementType *b){
	ElementType t=*a;
	*a=*b;
	*b=t;
}

//sap xep linklist theo phuong phap bubble sort
void sort (List *pL){
	Position P=(*pL),Q;
	while (P->Next!=NULL){
		Q=P->Next;
		while (Q->Next!=NULL){
			if (P->Next->Element>Q->Next->Element)
			   swap(P->Next->Element,Q->Next->Element);
			else
				Q=Q->Next;   
		}
		P=P->Next;
	}
}







