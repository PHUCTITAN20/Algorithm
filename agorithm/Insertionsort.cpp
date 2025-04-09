#include <stdio.h>

//Define data structure
typedef struct{
    int key;
    float value;
} recordtype;

void swap (recordtype *x, recordtype *y){
    recordtype temp=*x;
    *x=*y;
    *y=temp;
}

// Viet ham Insertionsort
void Insertionsort (recordtype a[], int n){
    int i, j;
    for (i=0; i<=n-1; i++){
        j=i;
        while (j>0 && a[j].key<a[j-1].key){
            swap(&a[j],&a[j-1]);
            j--;
        }
    }
}

int main(){
    // mang arr[] luu tru bien recordtype
    recordtype arr[] = { {64, 1.1}, {25, 2.5}, {12, 3.6}, {22, 4.4}, {11, 5.2} };
    // Mot trick hay de tim kich thuoc cua mang
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i=0; i<=n-1; i++){
        printf("{%d %.2f} ",arr[i].key, arr[i].value);
    }
    printf("\n");

    Insertionsort(arr,n);

    printf("Sorted array: ");
    for (int i=0; i<=n-1; i++){
        printf("{%d %.2f} ",arr[i].key, arr[i].value);
    }
    printf("\n");
    return 0;
}