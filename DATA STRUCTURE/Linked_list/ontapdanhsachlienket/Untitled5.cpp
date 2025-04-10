#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node *Position;
typedef Position List;


void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof (struct Node));
	(*pL)->Next=NULL;
}

void append (ElementType X, List *pL){
	Position P=(*pL);
	while (P->Next!=NULL)
		  P=P->Next;
	Position tempt;
	tempt=(struct Node*)malloc(sizeof (struct Node));
	tempt->Element=X;
	tempt->Next=P->Next;
	P->Next=tempt;
}

double getAvg(List L){
	Position P=L;
	if (P->Next==NULL) return -10000.000;
	else{
		double S=0;
		int count=0;
		while (P->Next!=NULL){
			S+=P->Next->Element;
			count++;
			P=P->Next;
		}
		return S/count;
	}
}

double getAvg1(List L){
    Position P=L;
    if (P->Next==NULL)
        return -10000.000;
    else {
        double S=0;
        int count=0;
        while (P->Next!=NULL){
            S += P->Next->Element;
            P=P->Next;
            count++;
        }
        return S/count;
    }
}

void deleteList(Position P, List *pL){
	if (P->Next!=NULL){
		 Position tempt;
		tempt=P->Next;
		P->Next=tempt->Next;
		free(tempt);
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

void copyEvenNumbers(List L1, List *pL){
	makenullList(pL);
	Position P=L1,Q=(*pL),tempt;
	while (P->Next!=NULL){
		if (P->Next->Element%2==0){
			tempt=(struct Node*)malloc(sizeof (struct Node));
			tempt->Element=P->Next->Element;
			tempt->Next=Q->Next;
			Q->Next=tempt;
			Q=tempt;			
		}
		P=P->Next;
	}
}

void removeAll(ElementType X, List *pL){
	Position P=locate(X,*pL);
	while (P->Next!=NULL){
		deleteList(P,pL);
		P=locate(X,*pL);
	}
}

int member(ElementType X, List L){
	Position P=L;
	int found = 0;
	while ((P->Next!=NULL)&&(!found)){
		if (P->Next->Element==X) found=1;
		else P=P->Next;
	}
	return found;
}

void copyEvenNumbers1(List L1, List *pL){
	makenullList(pL);
	Position P=L1,Q=*pL;
	while (P->Next!=NULL){
		if (P->Next->Element%2==0){
			append(P->Next->Element,pL);
		}
		P=P->Next;
	}
}



int main(){
	List L;
		
	Position p,q;	
	ElementType x;
		
	L=(struct Node*)malloc(sizeof(struct Node));	
	L->Next=NULL;
	
	p=L;
	q=(struct Node*)malloc(sizeof(struct Node));	
	q->Element=5;
	q->Next=NULL;
	p->Next = q;
		
	p=p->Next;
	
	q=(struct Node*)malloc(sizeof(struct Node));	
	q->Element=50;
	q->Next=NULL;
	p->Next = q;
		
	x=50;
	if (member(x, L))
		printf("%d in L",x);
	else printf("%d not in L",x);
	return 0;
}




