/* Date  : 04/05/2023
   Title : Generate random numbers and store in a file. Sort the generated random numbers and
   calculate the time required for sorting and store in other file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

FILE *fp,*fp1;
int n;
void random(int n)
{int v;
    FILE *fp;
fp=fopen("data.txt","w");
for(int i=0;i<n;i++)
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

node sort(node head,int n)
{
node cur,p;
int temp;
cur=head;
p=cur->next;
for(int j=0;j<=n;j++)
{
    p=cur->next;
    for(int i=0;i<=n;i++)
{
    if(cur->data>p->data)
    {
    temp=cur->data;
        cur->data=p->data;
        p->data=temp;

        p=p->next;
    }
    else
    {
   p=p->next;
    }

}
cur=cur->next;
}
return head;
}


int main()
{
int n;
time_t total,x,y;

printf("enter the number of numbers to be sorted: ");
scanf("%d",&n);
random(n);
    node head=NULL;
    fp=fopen("data.txt","r");
    fp1=fopen("xyz.txt","w");
for(int i=0;i<n;i++)
{
    head=insert(head);

}
x=time(NULL);

head=sort(head,n);
y=time(NULL);
total=y-x;

node cur=head;

for(int i=0;i<n;i++)
{
    printf(" %d",cur->data);
    fprintf(fp1," %d",cur->data);
    cur=cur->next;
}

fprintf(fp1,"\nEXECUTION TIME:\n%ld",total);
printf("\nEXECUTION TIME:\n%ld\n",total);
fclose(fp);
fclose(fp1);
return 0;
}

