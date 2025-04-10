#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define Maxlength 40

typedef int Position;

struct Sinhvien{
	char MSSV[10];
	char HoTen[50];
	float DLT;
	float DiemTH1;
	float DiemTH2;
};

typedef struct {
	struct Sinhvien A[Maxlength];
	Position n;
}DanhSach;

//khoi tao rong

DanhSach dsRong(){
	DanhSach L;
	L.n=0;
	return L;
}

int ktRong(DanhSach L){
	return L.n==0;
}

void chencuoi(struct Sinhvien s,DanhSach *pL){
	if (pL->n==Maxlength) printf("Full");
	else{
		pL->A[pL->n]=s;
		pL->n++;
	}
}



int tim(char mssv[],DanhSach L){
	int Found=0;
	int p=1;
	while ((p!=L.n+1)&&(!Found)){
		if (strcmp(L.A[p-1].MSSV,mssv))
		   Found=1;
		else p++;	   
	}
	return p;
}


void hienthi(DanhSach L){
	int p=1;
	Sinhvien S;
	while (p!=L.n+1){
		S=L.A[p-1];
		printf("Information of %d-th Sinhvien: ",p);
		printf("%s - %s - %.2f - %.2f - %.2f ",S.MSSV,S.HoTen,S.DLT,S.DiemTH1,S.DiemTH2);
		printf("Tongdiem is= %.2f\n",S.DLT+S.DiemTH1+S.DiemTH2);
		p++;
	}
}


DanhSach nhap(){
    DanhSach L;
    struct Sinhvien sv;
    L=dsRong();
    int N,i;
    char ms[10];
    char ht[50];
    scanf("%d",&N);
	printf("%d\n",N);
    for (i=1; i<=N; i++){
		printf("Sinh vien %d",i);
        gets(ms);
        strcpy(sv.MSSV,ms);
        gets(ht); printf("\n");   
        strcpy(sv.HoTen,ht);
        printf("Nhap diem:");
        scanf("%f%f%f",&sv.DLT,&sv.DiemTH1,&sv.DiemTH2);       
         if (tim(ms,L)==L.n+1){
            chencuoi(sv,&L);
        }
    }
    return L;
}


void xoaTai(int p,DanhSach *pL){
	if (pL->n==Maxlength) printf("Full");
	else if ((p<1)||(p>pL->n))
			printf("Invalid position!");
		else{
			int Q;
			for (Q=p-1;Q<=pL->n-1;Q++)
				pL->A[Q]=pL->A[Q+1];
			pL->n--;
		}	
}

void xoaSinhvien(char MSSV[],DanhSach *pL){
	int p=tim(MSSV,*pL);
	if (p!=pL->n+1)
		xoaTai(p,pL);
}

void hienthidat(DanhSach L){
	int p=1;
	float Tongdiem;
	while(p!=L.n+1){
		Tongdiem=(L.A[p-1].DLT)+(L.A[p-1].DiemTH1)+(L.A[p-1].DiemTH2);
		if (Tongdiem>=4)
			printf(" %s - %s - %.2f - %.2f - %.2f - %.2f ",L.A[p-1].MSSV,L.A[p-1].HoTen,L.A[p-1].DLT,L.A[p-1].DiemTH1,L.A[p-1].DiemTH2,Tongdiem);
	}
}



int main(){
	DanhSach List;
	List=nhap();
	hienthi(List);
	return 0;
}








