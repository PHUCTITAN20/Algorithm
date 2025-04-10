#define maxlength 100
#define nil -1
#include <stdio.h>
typedef char datatype;
typedef int Node;
typedef struct
{
    datatype data[maxlength];
    Node parent[maxlength];
    int maxnode;
} Tree;
//Tree T;
void makenull_tree(Tree *T)
{
    (*T).maxnode=0;
}

Node emptytree(Tree T)
{
    return (T.maxnode==0);
}

Node chacuanut(Node n, Tree T)
{
    if(emptytree(T) || (n>T.maxnode-1))
    {
        return nil;
    }
    else
    {
        return T.parent[n];
    }
}
void ReadTree(Tree *T){
	int i;
	makenull_tree(&T);

	do{
   	printf("Cay co bao nhieu nut?:");
   	scanf("%d",&(*T).maxnode);
	} while (((*T).maxnode<1) || ((*T).maxnode>maxlength));
    fflush(stdin);

	printf("Nhap nhan cua nut goc ");
	scanf("%c",&(*T).data[0]);
	(*T).parent[0]=nil;
	for (i=1;i<=(*T).maxnode-1;i++){
   		printf("Nhap cha cua nut %d ",i);
   		scanf("%d",&(*T).parent[i]);
   		fflush(stdin);
   		printf("Nhap nhan cua nut %d ",i);
   		scanf("%c",&(*T).data[i]);
	}

}
Node Root(Tree T)
{
    if(!emptytree(T))
        return 0;
    else    return nil;
}

Node LeftMostChild(Node n,Tree T)
{

    int found=0;;
    if(n<0) return nil;
    Node i=n+1;
    while(i<T.maxnode && !found)
    {
        if(T.parent[i]==n)
            found=1;
        else
            i++;
    }
    if(found)
        return i;
    else
        return nil;
}
Node RightSibling(Node n,Tree T)
{
    Node cha,i;
    if(n<0) return nil;
    cha = T.parent[n];
    i=n+1;
    int found=0;
    while(i<T.maxnode && !found)
    {
        if(T.parent[i]==cha)
            found=1;
        else
            i++;
    }
    if(found)
        return i;
    else
        return nil;


}
datatype Label_Node(Node n, Tree T)
{
    if (!emptytree(T) && (n<=T.maxnode-1))
    return T.data[n];
}
void PreOrder(Node n,Tree T)
{
    Node i;
    printf("%c ",Label_Node(n,T));
    i=LeftMostChild(n,T);
    while(i!=nil)
    {
        PreOrder(i,T);
        i=RightSibling(i,T);
    }
}
void InOrder(Node n,Tree T)
{
    Node i;
    i=LeftMostChild(n,T);
    if(i!=nil)
        InOrder(i,T);
    printf("%c ",Label_Node(n,T));
    i=RightSibling(i,T);
    while(i!=nil)
    {
       InOrder(i,T);
        i=RightSibling(i,T);
    }
}
void PostOrder(Node n,Tree T)
{
    Node i;
    i= LeftMostChild(n,T);
    while(i!=nil)
    {
        PostOrder(i,T);
        i=RightSibling(i,T);
    }
    printf("%c ",Label_Node(n,T));

}
Node bacnut(Node n, Tree T)
{
    int kq=0;
    Node i;
    i= LeftMostChild(n,T);
    while(i!=nil)
    {
        kq++;
        i=RightSibling(i,T);
    }
    return kq;
}

Node soanhemphai(Node n, Tree T)
{

    int count=0;;
    if(n<0) return nil;
    Node i=n+1;
    while(i<T.maxnode)
    {
        if(T.parent[i]==T.parent[n])
            count++;
        i++;
    }

    return count;
}

main(){
	Tree T;
	Node i,nut;
	int bac,soanhem;
	printf("Nhap du lieu cho cay tong quat\n");
	ReadTree(&T);
	/*T.maxnode=10;
	T.parent[0]=-1; T.data[0]='A';
	T.parent[1]=0; T.data[1]='B';
	T.parent[2]=0; T.data[2]='C';
	T.parent[3]=1; T.data[3]='D';
	T.parent[4]=1; T.data[4]='E';
	T.parent[5]=4; T.data[5]='F';
	T.parent[6]=4; T.data[6]='G';
	T.parent[7]=4; T.data[7]='H';
	T.parent[8]=2; T.data[8]='I';
	T.parent[9]=2; T.data[9]='J';*/
	printf("Danh sach duyet tien tu cua cay vua nhap la\n");
	PreOrder(Root(T),T);
	printf("\nDanh sach duyet trung tu cua cay vua nhap la\n");
	InOrder(Root(T),T);
	printf("\nDanh sach duyet hau tu cua cay vua nhap la\n");
	PostOrder(Root(T),T);
	//bac cua nut goc
	printf("\NNhap nuT can tim bac:");
	scanf("%d",&nut);
	bac=bacnut(nut,T);
	printf("\nBac cua nut goc la: %d",bac);
	//Tim anh em ruot cua nut
	printf("\nNhap vao nut can tim so anh em ruot phai:");
	scanf("%d",&nut);
	soanhem=soanhemphai(nut,T);
	printf("\nSo anh em ruot phai cua nut la: %d",soanhem);

}


