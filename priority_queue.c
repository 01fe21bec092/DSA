/* Date : 30/05/2023
  Title: Implementation of priority queues using arrays with file operations in C language.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void enqueue(int);
void dequeue();
void check_priority(int);
void display_priorityqueue();

int pqueue[MAX];
int front=-1, rear=-1;
int count,c_eq, c_dq;

FILE *fpeq,*fpin,*fpq,*fpdq,*fop;

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


void main()
{
    int choice,x;
    fpin=fopen("input.txt","r");
    fpeq=fopen("en_q.txt","w");
    fpdq=fopen("de_q.txt","w");
    fop=fopen("op_file.txt","w");


    printf("Enter the number of random numbers to be generated: ");
    scanf("%d",&x);
    random(x);

    while (1)
        {
        printf("\n 1 enqueue by priority ");
        printf("\n 2 dequeue by priority ");
        printf("\n 3 display priority queue ");
        printf("\n 4 exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1 :enqueue(x);
                fprintf(fop,"Enqueue()\n");
                break;
        case 2: dequeue();
                fprintf(fop,"Dequeue()\n");
                break;
        case 3: display_priorityqueue();
                break;
        case 4:fclose(fpin);
            fclose(fpeq);
            fclose(fpdq);
            fprintf(fop,"\nEnqueue() = %d \n",c_eq);
            fprintf(fop,"\nDequeue() = %d \n",c_dq);
            fclose(fop);
            exit(0);
        default: printf("\n Please enter valid choice");
        }
    }
}

// function to insert an element in a circular queue
void enqueue(int x)
{
    count++;
    c_eq++;
    int data;
    fscanf(fpin,"%d",&data);
    fprintf(fpeq,"%d ",data);
    if(count>=x+1)
    {
        printf("No elements present at input to add on to the queue\n");
        return;
    }

    if (rear >= MAX - 1)
    {
        printf("\nQUEUE OVERFLOW");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pqueue[rear] = data;
        return;
    }
    else
        check_priority(data);
    rear++;
}

// Check and arrange queue according to descending priority.
void check_priority(int data)
{
    int i,j;
    for (i = 0; i <= rear; i++)
    {
        if (data >= pqueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pqueue[j] = pqueue[j - 1];
            }
            pqueue[i] = data;
            return;
        }
    }
    pqueue[i] = data;

}

// function to delete the element from the queue
void dequeue()
{
    count--;
    c_dq++;
    int i;
    if ((front==-1) && (rear==-1))
    {
        printf("\nEmpty Queue");
        return;
    }
    fprintf(fpdq,"%d ",pqueue[front]);
    front++;

}

// function to display the elements of a queue
void display_priorityqueue()
{
    fpq=fopen("queue.txt","w+");
    if ((front == -1) && (rear == -1))
    {
        printf("\nEmpty Queue ");
        return;
    }
    for (; front <= rear; front++)
    {
        printf(" %d ", pqueue[front]);
        fprintf(fpq,"%d ", pqueue[front]);
    }
     front = 0;

     fclose(fpq);
}
