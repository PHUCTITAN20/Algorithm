#include <stdio.h>
#include <sdtlib.h>

struct SinhVien{
	char MSSV[10];
    char HoTen[50];
    float DLT;
    float DiemTH1;
    float DiemTH2;
};

struct Node{
	SinhVien Element;
	struct Node *Next;
};

typedef Node *Position;
typedef Position List;
