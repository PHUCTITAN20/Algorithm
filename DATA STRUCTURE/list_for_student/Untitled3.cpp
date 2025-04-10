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

void chenCuoi(struct SinhVien S,DanhSach *pL){
	if (pL->n==Maxlength) 
	printf("Danh sach day");
	else{
		pL->A[pL->n]=S;
		pL->n++;
	}
}

void hienthi(DanhSach L){
	Position P=1;
	float Tb;
	while (P!=L.n+1){
		Tb=(L.A[P-1].DLT+L.A[P-1].DiemTH1+L.A[P-1].DiemTH2);
		printf("%s - %s - %.2f - %.2f -%.2f - %.2f\n",L.A[P-1].MSSV,L.A[P-1].HoTen,L.A[P-1].DLT,
  				   	 	  	   	 	  		  					L.A[P-1].DiemTH1,L.A[P-1].DiemTH2,Tb);
		P++; 	  	   	 	  		  					
	}
}

void xoaTai(int P,DanhSach *pL){
	if (pL->n==0) printf("NullList");
	else if ((P<1)||(P>pL->n)) printf("Invalid Position");
		 else {
		 	int Q;
		 	for (Q=P;Q<pL->n;Q++){
		 		pL->A[Q-1]=pL->A[Q];
		 		pL->n--;
			 }	
		 }
}

int tim (char mssv[],DanhSach L){
	int P=1;
	int found=0;
	while ((P!=L.n+1)&&(!found)){
		if (strcmp(L.A[P-1].MSSV,mssv)==0) found=1;
		else P++;	
	}
	return P;
}

int main(){
	DanhSach L = {{{"B1806972","Hoang Minh", 5.0f, 2.5f, 2.0f}}, 1};
	struct SinhVien s = {"B1806973","Thai Anh", 4.5f, 1.25f, 1.0f}; 
	int p,i;
	L.A[1] = s;
	L.n++;
	for(i=0;i<L.n;i++)
	{
	    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
	
	p = tim("B1806974", L);
	if (p > L.n)
	  printf("Tim khong thay");
	else printf("Tim thay o vi tri %d",p);
	return 0;
}


