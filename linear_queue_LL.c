#include<stdio.h>
#include<stdlib.h>
#define MAX 20


struct queue
{
    int a[MAX];
    int front;
    int rear;
};
typedef struct queue QUEUE;

int count, c_eq, c_dq;

FILE *fpeq,*fpin,*fpq,*fpdq,*fop;

void enqueue(QUEUE *q,int x)
{
    count++;
    c_eq++;
    int data;
    fscanf(fpin,"%d ",&data);
    if(c_eq>=x+1)
    {
        printf("No elements present at input to add on to the queue\n");
        return;
    }

    if(q->rear==MAX-1)
    {
        printf("overflow\n");
        return;
    }
    else
    {
        if(q->front==-1)
        {
            q->front=0;
        }

        q->rear++;
        q->a[q->rear]=data;
    }
    fprintf(fpq,"%d ",data);
    fprintf(fpeq,"%d ",data);
}
void dequeue(QUEUE *q)
{
    count--;
    c_dq++;
    int x;
    if(q->rear==-1||q->front==-1||q->rear<q->front)
    {
        printf("underflow\n");
        q->rear=-1;
        q->front=-1;
        return;
    }
    else
    {
        x=q->a[q->front];
        q->front++;
        printf("%d dequeued\n",x);
    }
    fprintf(fpdq,"%d ",x);
}

void display(QUEUE *q)
{
    int i;
    if(q->rear==-1||q->front==-1||q->rear < q->front)
    {
        printf("Queue is empty\n");
        //q->rear=-1;
        //q->front=-1;
        return;
    }
    for(i=q->front;i<=q->rear;i++)
    {
        printf("%d\n",q->a[i]);
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

void restore(QUEUE *q)             // To update queue file after dequeue operation
{
    fpq=fopen("queue.txt","w");
   for(int i=q->front;i<q->rear;i++)
    {
      fprintf(fpq,"%d ",q->a[i]);
    }
}

int main()
{
    QUEUE q;
    q.front=-1;
    q.rear=-1;
    int choice,x;
    fpin=fopen("input.txt","r");
    fpeq=fopen("en_q.txt","w");
    fpq=fopen("queue.txt","w");
    fpdq=fopen("de_q.txt","w");
    fop=fopen("op_file.txt","w");


    printf("Enter the number of random numbers to be generated: ");
    scanf("%d",&x);
    random(x);
    for(;;)
    {
        printf(" 1-enqueue\n 2-dequeue\n 3-display\n 4-end\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue(&q,x);
            fprintf(fop,"Enqueue()\n");
            break;
            case 2:dequeue(&q);
            fprintf(fop,"Dequeue()\n");
            fclose(fpq);
            restore(&q);
            break;
            case 3:display(&q);
            break;
            case 4:fclose(fpin);
            fclose(fpeq);
            fclose(fpq);
            fclose(fpdq);
            fprintf(fop,"\nEnqueue() = %d \n",c_eq);
            fprintf(fop,"\nDequeue() = %d \n",c_dq);
            fclose(fop);
            exit(0);
            break;
            default:printf("invalid entry\n");
            break;
        }
        printf("\n");
    }
}
