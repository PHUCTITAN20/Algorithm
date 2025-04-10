#include <stdio.h>
#include <conio.h>
#include <D:\Teaching Corner\GiangDay\Cau Truc du lieu\CAY_TKNP_Toan\Timkiemnhiphanlib.cpp>

/*=== Xac dinh con trai ===*/
TTree LeftChild(TTree T)
{
 if(T != NULL)
	return T->Left;
 else   return NULL;
}

/*=== Xac dinh con phai ===*/
TTree RightChild(TTree T)
{
 if(T != NULL)
	return T->Right;
 else   return NULL;
}

/*=== Xac dinh nut la ===*/
int isLeaf(TTree T)
{
  if((T != NULL) && (T->Left == NULL) && (T->Right == NULL))
	return 1;
  else  return 0;
}


/*=== Xac dinh so nut cua cay ===*/
int tongsonut(TTree T)
{
 if(EmptyTree(T))
	return 0;
 else   return tongsonut(T->Left)+tongsonut(T->Right)+1;
}


//Them nut co khoa X vao BST
void InsertNode(KeyType X, TTree *T)
{
  if((*T) == NULL)
  {
    (*T)      = (Node*)malloc(sizeof(Node));
    (*T)->Key = X;
    (*T)->Left = NULL;
    (*T)->Right = NULL;
  }
  else
	if((*T)->Key == X)
		printf("Da ton tai khoa X");
	else
		if((*T)->Key > X)
			InsertNode(X,&(*T)->Left);
		else
			InsertNode(X,&(*T)->Right);
}

//Ham tra ve nut co khoa la K, khong thay tra ve NULL
TTree Search(KeyType K, TTree T)
{
    if(T==NULL) return NULL;//Kiem tra cay rong
        else if(K == T->Key) //tim thay khoa
                return T;
            else if(K < T->Key) // Hy vong K nam ben trai
                return Search(K,T->Left);
                else      // Hy vong K nam ben phai
                    return Search(K,T->Right);
}

//Xoa mot nut co khoa nho nhat
KeyType DeleteMin(TTree *T)
{
 KeyType k;
 if((*T)->Left == NULL)
 {
     k = (*T)->Key;
     (*T) = (*T)->Right;
     return k;
 }
 else return DeleteMin(&(*T)->Left);
}

// Xoa 1 nut co khoa X
void DeleteNode(KeyType X, TTree *T)
{
  if((*T)!=NULL) //Kiem tra cay khac rong
	if(X < (*T)->Key) //Hy vong X nam ben trai cua nut
		DeleteNode(X,&(*T)->Left);
	else
	     if(X > (*T)->Key) //Hy vong X nam ben phai cua nut
		DeleteNode(X,&(*T)->Right);
	     else // Tim thay khoa X tren cay
		 if(((*T)->Left==NULL)&&((*T)->Right==NULL))//X la nut la
		     (*T)=NULL; // Xoa nut X
		 else // X co it nhat mot con
		     if((*T)->Left==NULL) //Chac chan co con phai
			(*T) = (*T)->Right;
		     else
			 if((*T)->Right==NULL) //Chac chan co con trai
			    (*T) = (*T)->Left;
			 else  // X co hai con
			    (*T)->Key = DeleteMin(&(*T)->Right);
}

//Duyet tien tu
void NLR(TTree T)
{
  if(!EmptyTree(T))
  {
   printf(" %d",T->Key); //Xu ly nut
   NLR(LeftChild(T)); //Duyet tien tu con trai
   NLR(RightChild(T)); //Duyet tien tu con phai
  }
}

//Duyet trung tu
void LNR(TTree T)
{
 if(!EmptyTree(T))
 {
  LNR(LeftChild(T)); //Duyet trung tu con trai
  printf(" %d",T->Key);//Xu ly nut
  LNR(RightChild(T));//Duyet trung tu con phai
  }
}

//Duyet hau tu
void LRN(TTree T)
{
 if(!EmptyTree(T))
 {
  LRN(LeftChild(T)); //Duyet hau tu con trai
  LRN(RightChild(T));//Duyet hau tu con phai
  printf(" %d",T->Key);//Xu ly nut
  }
}

// To tien
int totien(TTree T,KeyType p, KeyType q)
{
    if((T->Key==p) && ((T->Key <q)||(T->Key >q)))
       return 1;
    else if((T->Key >q && T->Key <p)||(T->Key >p && T->Key <q))
        return 0;
    else if(T->Key<q && T->Key<p) totien(T->Right,p,q);
    else totien(T->Left,p,q);
}

//To tien chung gan nhat
Tdata NearRoot(TTree T,KeyType p, KeyType q)
{
   if((T->Key >=p && T->Key <= q) || (T->Key >=q && T->Key <= p))
      return T->Key;
   else
      if(T->Key < p && T->Key < q)
         return NearRoot(T->Right,p,q);
      else
         return NearRoot(T->Left,p,q);
}

int main()
{
    TTree T,n;
    KeyType X,p,q,a,b,tt;
    MakeNull_Tree(&T);
    //T1=create2('B',create2('D',NULL,NULL),create2('E',create2('H',NULL,NULL),NULL));
    //T2=create2('C',create2('F',NULL,create2('I',NULL,NULL)),create2('G',NULL,NULL));
    //T=create2('A',T1,T2);
    InsertNode(50,&T);
    InsertNode(20,&T);
    InsertNode(30,&T);
    InsertNode(60,&T);
    InsertNode(55,&T);
    InsertNode(16,&T);
    printf("\nDuyet tien tu:\n");
    NLR(T);
    printf("\nDuyet trung tu:\n");
    LNR(T);
    printf("\nDuyet hau tu:\n");
    LRN(T);
    printf("\nNhap vao khoa can xoa:");
    scanf("%d",&X);
    DeleteNode(X,&T);
    printf("\nDuyet trung tu:\n");
    LNR(T);
    printf("\nNhap vao khoa can tim:");
    scanf("%d",&X);
    n=Search(X,T);
    if(n!=NULL)
        printf("\nKhoa can tim ton tai tren cay");
    else
        printf("\nKhoa can tim khong ton tai");
    printf("\nTong so nut tren cay la %d",tongsonut(T));
    printf("\nNhap vao khoa thu nhat can tim to tien chung:");
    scanf("%d",&p);
    printf("\nNhap vao khoa thu hai can tim to tien chung:");
    scanf("%d",&q);
    if(Search(p,T)!=NULL&&Search(q,T)!=NULL)
        printf("\nTo tien chung gan nhat la %d",NearRoot(T,p,q));
    else
        printf("\nKhoa nhap khong co tren cay");

    printf("\nNhap vao to tien de kiem tra:");
    scanf("%d",&a);
    printf("\nNhap vao khoa de kiem tra:");
    scanf("%d",&b);
   if(Search(a,T)!=NULL&&Search(b,T)!=NULL)
   {
        tt = totien(T,a,b);
        if(tt==1)
            printf("\n%d la to tien cua %d",a,b);
        else
            printf("\n%d KHONG la to tien cua %d",a,b);
   }
    else
        printf("\nKhoa nhap khong co tren cay");
//    printf("\nChieu cao cua cay la %d",chieucao(T));
//	printf("\nSo nut la tren cay %d",sonutla(T));*/
}

