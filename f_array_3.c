//Date :13/04/2023
//Sort the number of elements using files and calculate the time for sorting

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int a[],int n);

int main()
{
    FILE *fp;
     //float total;
   time_t x,y,total;
    int n,i,v,e;
    int arr[100000];
     fp=fopen("abc.txt","w");
     if(fp==NULL)
     {
         printf("Error\n");
         exit(0);
     }
     printf("Enter the number of elements to be generated\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         v=rand();
         arr[i]=v;
         fprintf(fp,"%d ",v);
     }
     printf("Enter the number of elements to be sorted\n");
     scanf("%d",&e);
     x=time(NULL);
     sort(arr,e);
    y=time(NULL);

     //printf("Elements generated successfully");
     fclose(fp);

      total=y-x;
printf("\nTime required for sorting is %ld \n",total);


     return 0;
}

void sort(int a[],int n)
{
    FILE *fp;

    fp=fopen("new.txt","w");
     if(fp==NULL)
     {
         printf("Error\n");
         exit(0);
     }
      int i,j,temp;

    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }

        }

    }

    for(i=0;i<n;i++)
    {
        fprintf(fp," %d ",a[i]);
    }
fclose(fp);

}
