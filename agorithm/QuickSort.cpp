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

// The function FindPivot receive 3 inputs that is recordtype, i, j. Return -1 if it doesn't find out pivot and reversrly return 1
int FindPivot(recordtype a[], int i, int j){
    int firstkey;
    int k;
    k=i+1;
    firstkey = a[i].key;
    while(k<=j && a[k].key==firstkey) k++;
    if(k>j) return -1; // Probed all array
    if (a[k].key > firstkey) return k;
    return i;
}

// The partition function receive 4 paramaters that are recordtype, i, j, pivot having keytype for partition the array based on pivot
// and return L as the fist index of the right array.

int Partition( recordtype a[], int i, int j, int pivot){
    int L, R;
    L = i;
    R = j;
    while (L<=R){
        //Moving L to the left if its key is smaller than pivot
        while (a[L].key < pivot) L++;
        //Moving R to the right if its key is larger than pivot
        while (a[R].key >= pivot) R--;
        if (L<R) swap(&a[L], &a[R]);
    }
    return L; //partition point
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

}
