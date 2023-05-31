#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;
int count, c_eq, c_dq;

FILE *fpeq,*fpin,*fpq,*fpdq,*fop;

void enqueue(int x)        // Enqueue operation to add elements to the queue
{
    count++;
    c_eq++;
    int data;
    fscanf(fpin,"%d ",&data);
    if(front==-1)
    {
        front=0;
    }
    if(rear==MAX-1)
    {
        printf("Queue overflow\n");
        return;
    }

    if(count>=x+1)
    {
        printf("No elements present at input to add on to the queue\n");
        return;
    }
    else
    {
      rear++;
    queue[rear]=data;
    fprintf(fpq,"%d ",data);
    fprintf(fpeq,"%d ",data);
    }

}


void dequeue()         // Dequeue operation to remove elements from the queue
{
    count--;
    c_dq++;
    int x;
    if(front==-1||front>rear)
    {
        printf("Queue underflow\n");
        front=-1;
        rear=-1;
        return;
    }
    else
    {
      x=queue[front];
    front++;
     printf("Deleted %d\n",x);
     fprintf(fpdq,"%d ",x);
    }

}
void display()
{
    if(front==-1||front>rear)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Queue: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void random(int n)            // to generate random numbers
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

void restore()             // To update queue file after dequeue operation
{
    fpq=fopen("queue.txt","w+");
   for(int i=0;i<=rear;i++)
    {
      fprintf(fpq,"%d ",queue[i]);
    }
}


int main()
{
    int choice,x;
    fpin=fopen("input.txt","r");
    fpeq=fopen("en_q.txt","w");
    fpq=fopen("queue.txt","w+");
    fpdq=fopen("de_q.txt","w");
    fop=fopen("op_file.txt","w");


    printf("Enter the number of random numbers to be generated: ");
    scanf("%d",&x);
    random(x);
    while(1)
    {
        printf("1 to enqueue\n2 to dequeue\n3 to display\n4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:enqueue(x);
               fprintf(fop,"Enqueue()\n");
                break;
        case 2:dequeue();
              fprintf(fop,"Dequeue()\n");
              fclose(fpq);
              restore();
              break;
        case 3:display();break;
        case 4:
            fclose(fpin);
            fclose(fpeq);
            fclose(fpq);
            fclose(fpdq);
            fprintf(fop,"\nEnqueue() = %d \n",c_eq);
            fprintf(fop,"\nDequeue() = %d \n",c_dq);
            fclose(fop);
            exit(0);
        default: printf("Invalid choice\n");
        }
    }

  return 0;
}
