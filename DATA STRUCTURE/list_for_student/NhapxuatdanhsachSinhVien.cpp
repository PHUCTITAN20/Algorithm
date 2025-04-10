#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxlength 40
typedef int Position;

struct SinhVien{
    char MSSV[10];
    char HoTen[50];
    float DLT;
    float DiemTH1;
    float DiemTH2;
} ;

typedef struct {
	struct SinhVien A[Maxlength];
	Position    n;
} DanhSach; 

DanhSach dsRong(){
    DanhSach L;
    L.n=0;
    return L;
}

int ktRong(DanhSach L){
    return L.n==0;
}

int tim(char mssv[], DanhSach L){
    int p=1;
    int found=0;
    while (p!=L.n+1 && !found){
        if (strcmp(L.A[p-1].MSSV,mssv)==0)
            found=1;
        else
            p++;
    }
    return p;
}

void chenCuoi(struct SinhVien S,DanhSach *pL){
	if (pL->n==Maxlength) 
	printf("Danh sach day");
	else{
		pL->A[pL->n]=S;
		pL->n++;
	}
}

DanhSach nhap(){
	DanhSach L;
	L=dsRong();
	struct SinhVien S;
	int N,i;
	char ms[10];
	char hoten[50];
	scanf("%d",&N);
	for (i=1;i<=N;i++){
		fgets(ms,10,stdin);
		if (ms[strlen(ms)-1]=='\n')
		   ms[strlen(ms)-1]='\0';
 		strcpy(S.MSSV,ms);
		fgets(hoten,50,stdin);
		if (hoten[strlen(hoten)-1]=='\n')
		   hoten[strlen(hoten)-1]='\0';
		strcpy(S.MSSV,hoten);
		scanf("%f%f%f",&S.DLT,&S.DiemTH1,&S.DiemTH2);
		if (tim(ms,L)==L.n+1)
		   chenCuoi(S,&L);
	}
	return L;
}

DanhSach nhap1(){
	    DanhSach L;
	    struct SinhVien sv;
	    L=dsRong();
	    int N,i;
	    char ms[10];
	    char ht[50];
	    scanf("%d", &N);
	    for (i=1; i<=N; i++){
	        fgets(ms,10,stdin);
	        if (ms[strlen(ms)-1]=='\n')
	           ms[strlen(ms)-1]='\0';
	        strcpy(sv.MSSV,ms);
	        fgets(ht,50,stdin);
	        if (ht[strlen(ht)-1]=='\n')
	           ht[strlen(ht)-1]='\0';       
	        strcpy(sv.HoTen,ht);
	        scanf("%f%f%f ",&sv.DLT,&sv.DiemTH1,&sv.DiemTH2);       
	         if (tim(ms,L)==L.n+1){
	            chenCuoi(sv,&L);
	        }
	    }
	    return L;
	}

void hienthi(DanhSach L){
    int p=1;
    struct SinhVien s;
    while(p!=L.n+1){
        s=L.A[p-1];
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",s.MSSV, s.HoTen, s.DLT, s.DiemTH1, s.DiemTH2, s.DLT+s.DiemTH1+s.DiemTH2);
        p++;
    }
}

int main(){
	DanhSach L;
	L=nhap1();
	hienthi(L);
	return 0;
}
