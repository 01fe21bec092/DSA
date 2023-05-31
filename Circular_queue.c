/* Date : 30/05/2023
  Title: Implementation of circular queues using arrays in C */

#include <stdio.h>
#include <stdlib.h>
# define max 5

int queue[max];
int front=-1;
int rear=-1;
int count,c_eq, c_dq;

FILE *fpeq,*fpin,*fpq,*fpdq,*fop;


// function to insert an element in a circular queue
void enqueue(int x)
{
    count++;
    c_eq++;
    int data;
    fscanf(fpin,"%d",&data);

    if(count>=x+1)
    {
        printf("No elements present at input to add on to the queue\n");
        return;
    }

    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=data;
    }
    else if((rear+1)%max==front)           // (front==rear+1) || (front==0 && rear==MAX-1)
    {
        printf("Queue overflow..\n");
        return;
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=data;
    }
    fprintf(fpq,"%d ",data);
    fprintf(fpeq,"%d ",data);
}

// function to delete the element from the queue
int dequeue()
{
    int temp=queue[front];
    c_dq++;
    count--;
    if((front==-1) && (rear==-1))
    {
        printf("\nQueue underflow..\n");
        return;
    }
 else if(front==rear)
{
    printf("\nThe dequeued element is %d \n", queue[front]);
   front=-1;
   rear=-1;
}
else
{
    printf("\nThe dequeued element is %d \n", queue[front]);
   front=(front+1)%max;
}
 fprintf(fpdq,"%d ",temp);
}

// function to display the elements of a queue
void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty..\n");
    }
    else
    {

        printf("\nElements in a Queue are : ");
        while(i!=rear)
        {
            printf("%d  ", queue[i]);
            i=(i+1)%max;
        }
        printf("%d  ", queue[rear]);
    }
    printf("\n");
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
    fpq=fopen("queue.txt","w");
   for(int i=front;i!=rear;i=(i+1)%max)
    {
      fprintf(fpq,"%d ",queue[i]);
    }
    fprintf(fpq,"%d ",queue[rear]);
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
        case 2:dequeue(x);
              fprintf(fop,"Dequeue()\n");
              fclose(fpq);
              restore();
              break;
        case 3:display();
               break;
        case 4 : fclose(fpin);
            fclose(fpeq);
            fclose(fpq);
            fclose(fpdq);
            fprintf(fop,"\nEnqueue() = %d \n",c_eq);
            fprintf(fop,"\nDequeue() = %d \n",c_dq);
            fclose(fop);
                exit(0);
        default : printf("Invalid choice\n");

    }}
    return 0;
}
