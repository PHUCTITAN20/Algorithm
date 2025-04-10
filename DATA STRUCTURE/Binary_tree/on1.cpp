#include <stdio.h>
#include <malloc.h>

#define NULL 0LL

typedef int tdata;
typedef struct TNode{
    tdata data;
    struct TNode *left;
    struct TNode *right;
} TNode;

typedef struct TNode *TTree;
//End for initializing a tree

//makenulltree

void makenull_tree(TTree *T){
    (*T)=NULL;
}

//Check NULL tree
int emptyTree(TTree T){
    return (T==NULL);
}

//Viet ham deletemin
int DeleteMin (TTree *Root){
    tdata k;
    if ((*Root)->left==NULL){
        k=(*Root)->data;
        (*Root)=(*Root)->right;
        return k;
    }
    else DeleteMin(&(*Root)->left);
}

//con trái
TTree leftchild(TTree n){
    if (n!=NULL)
        return n->left;
    else
        return NULL;
}

//Con phải
TTree rightchild(TTree n){
    if (n!=NULL)
        return n->right;
    else
        return NULL;
}

//check leaf node
int is_leaf(TTree n){
    return ((n->left==NULL)&&(n->right==NULL));
}

//Tạo cây từ hai cây con
TTree create2(tdata v,TTree left,TTree right){
    TTree N;//N kiểu TTree thì N đã là một con trỏ
    N=(TNode*)malloc(sizeof(TNode));
    N->data=v;
    N->left=left;
    N->right=right;
    return N;
}

//hàm duyệt tiền tự 
void tientu(TTree T){
    if (!emptyTree(T)){
        printf("%d ",T->data);
        tientu(leftchild(T));
        tientu(rightchild(T));
    }
}

//Hàm duyệt trung tự
void trungtu(TTree T){
    if (!emptyTree(T)){
        trungtu(leftchild(T));
        printf("%d ",T->data);
        trungtu(rightchild(T));
    }
}

//Hàm duyệt hậu tự
void hautu(TTree T){
    if (!emptyTree(T)){
        hautu(leftchild(T));
        hautu(rightchild(T));
        printf("%d ",T->data);
    }
}


void DeleteNode (tdata x, TTree *Root){
    if ((*Root)!=NULL){
        if ( x < (*Root)->data)
            DeleteNode(x,&(*Root)->left);
        if ( x > (*Root)->data)
            DeleteNode(x,&(*Root)->right);
        
        //Nếu đến được đây thì đã *Root đang là x chuẩn bị xóa

        if (((*Root)->left==NULL)&&((*Root)->right==NULL))
            (*Root)=NULL;
        else {
                //Nếu chỉ có một con thì lôi thằng đó lên thay
                if((*Root)->left==NULL)
                    (*Root)=(*Root)->right;
                else if((*Root)->right==NULL)
                        (*Root)=(*Root)->left;
                    //Nếu có hai con thì thay bằng con cực trái của cây phải    
                    else 
                        (*Root)->data=DeleteMin(&(*Root)->right);
        }
    }     
}

//Hàm đếm nút lá
int countLeafNode(TTree T){
    if (T==NULL) return 0;
    if (is_leaf(T)) return 1;
    return  (countLeafNode(T->left) + countLeafNode(T->right));
}

//Hàm đếm tổng số nút
int countNode(TTree T){
    if (T==NULL) return 0;
    if (is_leaf(T)) return 1;
    return (1 + countNode(T->left) + countNode(T->right));
}

int sumNode(TTree T){
    if (T!=NULL){
        return (T->data + sumNode(T->left) + sumNode(T->right));
    }
}

//Ham tim kiem nut co nhan k
TTree search(tdata k, TTree T){
    if (T==NULL)
        return NULL;
    if (T->data==k)
        return T;
    else 
        if (T->data>k)
            return search(k,T->right);
        else
            return search(k,T->left);        
}

//Tim to tien chung gan nhat cua hai nut co nhan p va q
tdata NearRoot(TTree T, tdata p, tdata q){
    //Neu T->data bi kep giu p va q thi no la to tien
    //Neu khong goi de quy trai va phai
    if ((T->data >= p && T->data <=q) || (T->data >=q && T->data <=p))
        return T->data;
    else 
        if ( T->data<p && T->data<q )
            return NearRoot(T->left,p,q);
        else 
            return NearRoot(T->right,p,q);
}


//check to tien
int totien(TTree T, tdata p, tdata q){
    if ((T->data==p) && ((T->data<q)||(T->data>q)))
        return 1;
    else
        if ((T->data < q && T->data > p) || (T->data < p && T->data > q))
            return 1;
        else
            if (T->data <q && T->data <p)
                return totien(T->right,p,q);
            else
                return totien(T->left,p,q);
}

//them mot node co nhan k vao BST
//Can phai kiem tra da co node chua va dat no dung vi tri

void insertnode(tdata k, TTree *T){
    if ((*T)==NULL){
        (*T)=(TNode*)malloc(sizeof(TNode));
        (*T)->data=k;
        (*T)->left=NULL;
        (*T)->right=NULL;
    }
    else{
        if ((*T)->data ==k)
            printf("Da ton tai khoa: %d",k);
        else if ((*T)->data > k)
                insertnode(k,&(*T)->left);
            else
                insertnode(k,&(*T)->right);
    }
}


int kiemtra_snt(int n){
    if (n<2) return 0;
    for (int i=2;i<n;i++){
        if (!n%i==0) return 0;
    }
    return 1;
}

//xoa nut so nguyen to
void deleteSNT(TTree *T){
    if ((*T)!=NULL){
        while((kiemtra_snt((*T)->data)))
            DeleteNode((*T)->data,T);
        if ((*T)->left!=NULL)
            deleteSNT(&(*T)->left);
        if ((*T)->right!=NULL)
            deleteSNT(&(*T)->right);
        }
}

//Viet ham xoa cac nut la so chan
int kiemtra_chan(int n){
    if (n%2==0) return 1;
    else 
        return 0;
}

void delete_even_number(TTree *T){
    if ((*T)!=NULL){
        while ((kiemtra_chan((*T)->data))==1)
            DeleteNode((*T)->data,T);
        if ((*T)->left!=NULL)
            delete_even_number(&(*T)->left);
        if ((*T)->right!=NULL)
            delete_even_number(&(*T)->right);
    }
}



int main(){
    TTree T;
    makenull_tree(&T);

    
    insertnode(10,&T);
    insertnode(6,&T);
    insertnode(15,&T);
    insertnode(2,&T);
    insertnode(5,&T);
    insertnode(9,&T);
    insertnode(3,&T);
    insertnode(12,&T);
    insertnode(26,&T);
    insertnode(14,&T);
   

    printf("\nDuyet trung tu\n");
    trungtu(T);
    delete_even_number(&T);
    printf("\nDuyet trung tu\n");
    trungtu(T);

    return 0;
}
