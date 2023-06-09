//Date:13/4/2023
/*Read data from the file, sort and save it in other file*/

#include<stdio.h>
#include<stdlib.h>

 int main()
 {
     FILE *fp;
     int i,x,arr[50];
     fp=fopen("data.txt","r");
     if(fp==NULL)
     {
         printf("Error\n");
         exit(0);
     }
     fscanf(fp,"%d",&x);
     printf("Number of elements to be read is %d\n",x);
     printf("Data fetched is \n");
     for(i=0;i<x;i++)
     {
         fscanf(fp,"%d",&arr[i]);
         printf(" %d ",arr[i]);

     }
     fclose(fp);

     fp=fopen("new.txt","w");
     if(fp==NULL)
     {
         printf("Error\n");
         exit(0);
     }


     int j,temp;

    for(int i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }

        }

    }

    for(i=0;i<x;i++)
     {
         fprintf(fp,"%d  ",arr[i]);
     }



     /*for(;i>0;i--)         //Reversing the elements
     {
         fprintf(fp,"%d\n",arr[i-1]);
     }
     printf("\nElements reversed successfully\n");*/




     fclose(fp);

     return 0;
 }
