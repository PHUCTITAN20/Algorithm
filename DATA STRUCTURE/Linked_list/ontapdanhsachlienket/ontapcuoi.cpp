//khai báo cấu trúc danh sách liên kết
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node *Next;
};

typedef struct  Node *Position;
typedef Position List;

//viet lenh makenull

void makenullList(List *pL){
    (*pL)=(struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next=NULL;
}


int member(ElementType X, List L){
    Position P=L;
    int found=0;
    while ((P->Next!=NULL) && (!found)){
        if (P->Next->Element==X) found=1;
        else 
            P=P->Next;
    }
    return found;
}

//Nhap tap hop

void readset(List *pL){
    int n,i;
    ElementType x;
    Position tempt;
    makenullList(pL);
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%d",&x);
        //khoi lenh chen phantu
        if (!member(x,(*pL))){
            tempt=(struct Node*)malloc(sizeof (struct Node));
            tempt->Element=x;
            tempt->Next=(*pL)->Next;
            (*pL)->Next=tempt;
        }
}
}

//in tap hop
void printset(List L){
    Position P=L;
    while (P->Next!=NULL){
        printf("%d ",P->Next->Element);
        P=P->Next;
    }
    printf("\n");
}

//viet ham tìm intersection của hai tập hợp
List intersec(List L1,List L2){
    Position P=L1;
    List L;
    makenullList(&L);
    Position tempt;
    while (P->Next!=NULL){
        if (member(P->Next->Element,L2)){
            tempt=(struct Node*)malloc(sizeof(struct Node));
            tempt->Element=P->Next->Element;
            tempt->Next=L->Next;
            L->Next=tempt;  
        }
        P=P->Next; 
    }
    return L;
}

//viet ham append
void append(ElementType x,List *pL){
    Position P=(*pL);
    Position tempt;
    while(P->Next!=NULL){
        P=P->Next;
    }
    tempt=(struct Node*)malloc(sizeof (struct Node));
    tempt->Element=x;
    tempt->Next=P->Next;
    P->Next=tempt;
}

//viet ham tim union cua hai tap hop
List unionset(List L1, List L2){
    List P=L1;
    List L;
    makenullList(&L);
    Position tempt;
    //L như là một bản sao của L1
    while (P->Next!=NULL){
        tempt=(struct Node*)malloc(sizeof (struct Node));
        tempt->Element=P->Next->Element;
        tempt->Next=L->Next;
        L->Next=tempt;
        P=P->Next;
    }
    P=L2;
    while(P->Next!=NULL){
        if (!member(P->Next->Element,L)){
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
}


//viet ham appfirst
void addfirst(ElementType x, List *pL) {
    Position tempt=(struct Node*)malloc(sizeof (struct Node));
    tempt->Element=x;
    tempt->Next=(*pL)->Next;
    (*pL)->Next=tempt;
}


int main(){
    List L4,L3,L1,L2;
    readset(&L1);
    printset(L1);
    readset(&L2);
    printset(L2);
    printf("Giao cua hai tap hop la: ");
    L3=intersec(L1,L2);
    printset(L3);
    printf("Hop cua hai tap hop la: ");
    L4=unionset(L1,L2);
    printset(L4);
    return 0;
}





