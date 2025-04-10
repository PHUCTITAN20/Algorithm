#include <stdio.h>
#include <string.h>
int main(){
    char my_name[] = "Le Tran Dat";
    char *p_name = my_name;

    p_name[1] = 'E';
    printf("%s",my_name);
    return 0;
}
