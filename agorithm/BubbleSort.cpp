#include <stdio.h>

typedef struct{
    int key;
    float value;
} recordtype;

void swap(recordtype *x, recordtype *y){
    recordtype tem;
    tem = *x;
    *x= *y;
    *y = tem;
}

// Viet ham Bubblesort
void BubbleSort( recordtype a[], int n){
    int i,j;
    for (i=0 ; i<=n-2 ; i++){
        for (j=n-1 ; j>=i+1 ; j--){
            if (a[j].key<a[j-1].key){
                swap(&a[j],&a[j-1]);
            }
        }
    }
}

void Read_Data(recordtype a[], int *n){
	FILE *f;
	f=fopen("data.txt", "r");
	int i=0;
	if(f!=NULL)
	while (!feof(f)){
		fscanf(f,"%d%f",&a[i].key, &a[i].value);
		i++;
	} else printf("Loi mo file\n");
	fclose(f);
	*n=i;
}
	
void Print_Data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++) 
	printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].value);
}



int main(){
    // mang arr[] luu tru bien recordtype
    recordtype arr[100];
    int n;

    Read_Data(arr,&n);
    printf("Original data:\n");
    Print_Data(arr,n);
    printf("\n");
    BubbleSort(arr,n);
    printf("Sorted data:\n");
    Print_Data(arr,n);
    return 0;
}