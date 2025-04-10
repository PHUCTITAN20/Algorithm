#include <stdio.h>

int main()
{
   FILE *fp;
   char str[60];

   /* mo file de doc */
   fp = fopen("baitapc.txt" , "r");
   if(fp == NULL) 
   {
      perror("Xay ra loi trong khi doc file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) 
   {
      /* Ghi noi dung len stdout */
      puts(str);
   }
   fclose(fp);
   
   return(0);
}
