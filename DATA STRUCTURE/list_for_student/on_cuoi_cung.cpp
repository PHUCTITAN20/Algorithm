#include <stdio.h>
#include <string.h>
#define MAXLENGTH 40

typedef int Position;

struct sinhvien{
    char ID[10];
    char hoten[50];
    float diemlt,diemth1,diemth2;
};

typedef struct{
    struct sinhvien A[MAXLENGTH];
    Position n;
}danhsach;

//tao ra danh sach sinh vien rong

danhsach rong(){
    danhsach L;
    L.n=0;
    return L;
};


int tim(char ms[],danhsach L){
    int p=1;
    int found=0;
    while ((p!=L.n+1)&&(!found)){
        if (ms)
    }
}
