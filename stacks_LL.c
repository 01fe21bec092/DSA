/* Date: 17/05/2023
   Title : Implement stacks using linked lists and files.
*/

#include <stdio.h>
#include <stdlib.h>

void random(int n);
void restore();
// Structure to create a node with data and the next pointer
typedef struct array
 {
    int data;
    struct array *next;
}*node;

 node top,top1,temp;

int count = 0;
FILE *fpush,*fpin,*fstack,*fpop,*fop;

// Push() operation on a  stack
void push(int x)
 {
     int value;
     fscanf(fpin,"%d",&value);
     fprintf(fpush,"%d ",value);
     fprintf(fstack,"%d ",value);
     if (top == NULL)
    {
        top =(node)malloc(sizeof(struct array));
        top->next = NULL;
        top->data = value;
    }
    else
    {
        if(count==x)
           {
               printf("No elements present at input to push on to the stack\n");
               return;
           }
        temp =(node)malloc(sizeof(struct array));
        temp->next = top;
        temp->data = value;
        top = temp;
    }
    count++;
}

int pop() {
     top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    top1 = top1->next;
    int popped = top->data;
    fprintf(fpop,"%d ",popped);
    free(top);
    top = top1;
    count--;
    return popped;
}

void display() {
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d--->", top1->data);
        top1 = top1->next;
    }
    printf("NULL\n\n");

}

int main()
 {
    fpin=fopen("input.txt","r");
    fpush=fopen("push.txt","w");
    fstack=fopen("stack.txt","w");
    fpop=fopen("pop.txt","w");
    fop=fopen("op_file.txt","w");

    int ch,x;
    printf("Enter the number of random numbers to be generated: ");
    scanf("%d",&x);
    random(x);
    while (1)
        {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:push(x);
               fprintf(fop,"Push()\n");
               break;
        case 2:pop();
               fprintf(fop,"Pop()\n");
                fclose(fstack);
                fclose(fpin);
                restore();
               break;
        case 3:display();
               break;
        case 4:fclose(fpin);
               fclose(fpush);
               fclose(fstack);
               fclose(fpop);
               fclose(fop);
               exit(0);
               break;
        default:
            printf("\nInvalid input\n");
        }
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
{ int z=0;
    fstack=fopen("stack.txt","w");
    fpin=fopen("input.txt","r");
   for(int i=1;i<=count;i++)
    {
      fscanf(fpin,"%d ",&z);
      fprintf(fstack,"%d ",z);
    }
}
