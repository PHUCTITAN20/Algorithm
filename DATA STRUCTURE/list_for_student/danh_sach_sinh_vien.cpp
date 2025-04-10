//danh sach lien ket of sinh vien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define sinhvien struct
typedef struct{
    char mssv[10];
    char hoten[50];
    float diemLT, diemTH1, diemTH2;
}sinhvien;

struct Node{
    sinhvien Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef Position danhsach;

//lam rong

void makenullList(danhsach *pL){
    (*pL)=(struct Node*)malloc(sizeof (struct Node));
    (*pL)->Next=NULL;
};

// tao ra danh sach sinh vien rong
danhsach tao_danh_sach_rong(){
    danhsach L;
    L=(struct Node*)malloc(sizeof (struct Node));
    L->Next=NULL;
    return L;
};


//dinh vi thong qua MSSV

Position dinh_vi(char x[] , danhsach L){
    Position P = L;
    int found=0;
    while ((P->Next!=NULL)&&(!found)){
        if (strcmp( x ,P->Next->Element.mssv))
            found=1;
        else
            P=P->Next;
    }
    return P;
};

// them mot dua sinh vien vao
void append(sinhvien x, danhsach *pL){
    Position P=(*pL);
    while (P->Next!=NULL){
        P=P->Next;
    }
    Position tempt=(struct Node*)malloc(sizeof (struct Node));
    tempt->Element=x;
    tempt->Next=P->Next;
    P->Next=tempt;
}

//viet ham nhap vao danh sach cac sinh vien

void nhap(danhsach *pL){
    sinhvien Student;
    char ms[10];
    char ht[50];
    printf("MSSV= ");
    fgets(ms,10,stdin);
    if (ms[strlen(ms)-1]=='\n')
        ms[strlen(ms)-1]='\0'; 
    strcpy(Student.mssv,ms);
    fgets(ht,50,stdin);
    if (ht[strlen(ht)-1]=='\n')
        ht[strlen(ht)-1]='\0';
    strcpy(Student.hoten,ht);
    printf("Nhap diem: ");
    scanf("%f%f%f",&(Student.diemLT),&(Student.diemTH1),&(Student.diemTH2));
    //if (dinh_vi(ms,L)->Next==NULL)//neu chua co ai giong
    append(Student,pL);
    //}
};

void in_ra(danhsach L){
    Position P=L;
    while(P->Next!=NULL){
        printf("%s - %s - %.2f - %.2f - %.2f\n",P->Next->Element.mssv,P->Next->Element.hoten,
                    P->Next->Element.diemLT,P->Next->Element.diemTH1,P->Next->Element.diemTH2);
        P=P->Next;            
    }
}


int main(){
    danhsach L;
    nhap(&L);
    in_ra(L);
    return 0;
}







