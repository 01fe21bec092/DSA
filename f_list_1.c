/* Date  : 04/05/2023
   Title : Sorting of elements stored in the file using list
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *fp,*fp1;
int n;

typedef struct array
{
int data;
struct array *next;
}*node;

node getnode()
{
    int x;
    node newnode;
    newnode=(node)malloc(sizeof(struct array));
    if(newnode==NULL)
    {
        printf("error");
        exit(0);
    }
    fscanf(fp,"%d ",&x);

    newnode->data=x;
newnode->next=NULL;
    return newnode;

}


node insert(node head)
{
    node newnode=getnode();
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
node prev,cur;
int temp;
prev=head;
cur=prev->next;
for(int j=0;j<n;j++)
 {
    cur=prev->next;
    for(int i=0;i<=n;i++)
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
    node head=NULL;
    fp=fopen("data.txt","r");
    fp1=fopen("sorted_list.txt","w");
fscanf(fp,"%d",&n);
for(int i=1;i<n;i++)
{
    head=insert(head);

}
head=sort(head,n);
node prev=head;

printf("The sorted list is : ");

for(int i=1;i<n;i++)
{
    printf(" %d ",prev->data);
    fprintf(fp1," %d ",prev->data);
    prev=prev->next;
}


fclose(fp);
fclose(fp1);
  return 0;
}
