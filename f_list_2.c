/* Date  : 04/05/2023
   Title :Generate random numbers and store in a file. Sort the generated random numbers and store in other file using list.
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

FILE *fp,*fp1;
int n;
void random(int x)
{
    int v;
    FILE *fp;
fp=fopen("abc.txt","w");
for(int i=0;i<x;i++)
{
   v=rand()%(100-0);

    fprintf(fp,"%d ",v);
}
fclose(fp);
}

typedef struct array
{
int data;
struct array *next;
}*node;

node getnode()
{int a;
    node newnode;
    newnode=(node)malloc(sizeof(struct array));
    if(newnode==NULL)
    {
        printf("error");
        exit(0);
    }
    fscanf(fp,"%d",&a);
    newnode->data=a;

    newnode->next=NULL;
    return newnode;

}
node insert(node head)
{node newnode=getnode();
    if(head==NULL)
    {
        head=newnode;

    }

    newnode->next=head;
    head=newnode;
    return head;
}
node sort(node head,int x)
{
node prev,cur;
int temp;
prev=head;
cur=prev->next;
for(int j=0;j<=x;j++)
{
    cur=prev->next;
    for(int i=0;i<=x;i++)
{
    if(prev->data>cur->data)
    {
    temp=prev->data;
        prev->data=cur->data;
        cur->data=temp;

        cur=cur->next;
    }
    else
    {
   cur=cur->next;
    }

}
prev=prev->next;
}
return head;
}


int main()
{
    int x;
    printf("Enter the number of elements to be sorted : ");
    scanf("%d",&x);
    random(x);
    node head=NULL;
    fp=fopen("abc.txt","r");
    fp1=fopen("sorted_list.txt","w");

for(int i=0;i<x;i++)
{
    head=insert(head);
}

head=sort(head,x);

node prev=head;

printf("\nSorted list is : ");

for(int i=0;i<x;i++)
{
    printf(" %d",prev->data);
    fprintf(fp1," %d",prev->data);
    prev=prev->next;
}


fclose(fp);
fclose(fp1);
return 0;
}
