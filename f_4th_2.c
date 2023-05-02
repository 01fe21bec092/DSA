//Date: 13/04/2023
//generate random numbers and store in a file
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int n,i,v;
     fp=fopen("abc.txt","w");
     if(fp==NULL)
     {
         printf("Error\n");
         exit(0);
     }
     printf("Enter the number of elements to be generated within 100\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         v=rand()%(100-0);
         fprintf(fp,"%d ",v);
     }
     printf("Elements generated successfully");
     fclose(fp);

     return 0;
}
