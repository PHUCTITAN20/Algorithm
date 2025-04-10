#include <stdio.h>
#include <string.h>
int main(void){
    
    printf("Nhap chuoi co ky tu trang: ");
    char str[10];
    printf("hello");
    fgets(str, sizeof(str)+1, stdin);    
    printf("Chuoi vua nhap: ");
    puts(str); 
    return 0;
}
