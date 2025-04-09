#include <stdio.h>

void Sap_xep_chon( int a[], int n){
    for ( int i=0; i<=n-2; i++){
        //Tim key be nhat trong phan chua duoc sap xep
        int lowkey=i;
        for (int j=i+1; j<=n-1; j++){
            if (a[j] < a[lowkey]){
                lowkey=j;
            }
        }
        //Chuyen key be nhat den vi tri dau tien cua phan chua sap xep
        if (lowkey != i){
            int tempt;
            tempt = a[i];
            a[i] = a[lowkey];
            a[lowkey] = tempt;            
        }
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr);
    // in mang chua duoc sap xep
    printf("Original array: ");
    for (int i=0; i<= n-1; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    Sap_xep_chon (arr,n);
    // in mang da duoc sap xep
    printf("Sorted array: ");
    for (int i=0; i<=n-1; i++){
        printf("%d: ", arr[i]);
    }
    printf("\n");
    return 0;
}

