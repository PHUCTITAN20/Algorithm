#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
   char ID[10];
   char Na{
	Student Element;
	struct Node *Next;
};

typedef struct Node *List;
me[50];
   float R1, R2, R3;
}Student;


struct Node
List getList(){
	List L;
	L=(struct Node*)malloc(sizeof (struct Node));
	L->Next=NULL;
	return L;
}

struct Node* locate(char[] mssv, List L){
	struct Node *P=L;
	int found=0;
	while ((P->Next!=NULL)&&(!found)){
		if (strcmp(P->Next->Element.ID,mssv)==0)
		   found=1;
		else 
			 P=P->Next;	    
	}
	return P;
}

int append(Student s, List *pL){
	struct Node *P, *temp;
	P=locate(s.ID,(*pL));
	if (P->Next!=NULL){
		return 0;
	}
	else{
		temp=(struct Node*)malloc(sizeof(struct Node));
		temp->Element=s;
		temp->Next=NULL;
		P->Next=temp;
		return 1;
	}	
}

void readList(List *pL){
	
}

List getFailedList(List L){
	List ds;
	Position P=L;
	float Tong;
	while (P->Next!=NULL){
		Tong= P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3;
		if (Tong<4){
			append(P->Next->Element, &ds);
		}
		P=P->Next;
	}
	return ds;
}



int main(){
	List L;
	readList();
	printList(L);
	getFailedList(L);
	printList(L);
	return 0;
}

