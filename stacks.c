/* Date : 13/05/23
 Title : Generate random numbers in a file. Take users input for the operations push and pop.
         Store the pushed and poped values in separate file. ALso store the operated functions in op file.
Name of files : 1-input
                2-stack
                3-push
                4-pop
                5-op file*/

#include<stdio.h>
#include<stdlib.h>

int stack[10000];
int top=-1;
int count=0;
FILE *fpush,*fpin,*fstack,*fpop,*fop;

void push(int);
void pop();
void random(int);
void restore();
int main()
{

    fpin=fopen("input.txt","r");
    fpush=fopen("push.txt","w");
    fstack=fopen("stack.txt","w+");
    fpop=fopen("pop.txt","w");
    fop=fopen("op_file.txt","w");

    int ch,x;
    printf("Enter the number of random numbers to be generated: ");
    scanf("%d",&x);
    random(x);
    for(; ;)
    {
    printf("\n 1-Push\n 2-Pop\n 3-exit\n");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(x);
                   fprintf(fop,"Push()\n");
                   break;
            case 2:pop();
                   fprintf(fop,"Pop()\n");
                   fclose(fstack);
                   restore();
                   break;
            case 3:fclose(fpin);
                   fclose(fpush);
                   fclose(fstack);
                   fclose(fpop);
                   fclose(fop);
                   exit(0);
                   break;
            default :printf("Invalid condition\n");
        }
  }

    return 0;
}

void push(int x)
{
    int item;
    count++;
    if(top==10000)
        printf("Stack overflow\n");
    else
        {
           if(top==(x-1))
           {
               printf("No elements present at input to push on to the stack\n");
               return;
           }
         top++;
         fscanf(fpin,"%d",&item);
         stack[top]=item;
         fprintf(fpush,"%d ",item);
         fprintf(fstack,"%d ",item);
        }
}

void pop()
{
    int temp;
    count--;
    if(top==-1)
        printf("Stack underflow\n");
    else
    {
    int temp;
    temp=stack[top];
    top--;

    fprintf(fpop,"%d ",temp);

    }
}

void random(int n)
{  int v;
    FILE *fp;
fp=fopen("input.txt","w");
for(int i=0;i<n;i++)
{
    v=rand()%(100-0);
    fprintf(fp,"%d ",v);
}
fclose(fp);
}

void restore()
{
    fstack=fopen("stack.txt","w+");
   for(int i=0;i<=top;i++)
    {
      fprintf(fstack,"%d ",stack[i]);
    }
}
