/* Date : 30/05/2023
  Title: Implementation of double ended queues using arrays with file operations in C language */

#include <stdio.h>
#include <stdlib.h>
#define size 10
int deque[size];
int f = -1, r = -1;
int count,c_eq, c_dq;

FILE *fpeq,*fpin,*fpq,*fpdq,*fop;



//  insert_front function will insert the value from the front
void insert_front(int x)
{
    count++;
    c_eq++;
    int data;
    fscanf(fpin,"%d",&data);

    if(c_eq>=x+1)
    {
        printf("No elements present at input to add on to the queue\n");
        return;
    }


    if((f==0 && r==size-1) || (f==r+1))
    {
        printf("Overflow\n");
        return;
    }
    else if((f==-1) && (r==-1))
    {
        f=r=0;
        deque[f]=data;
    }
    else if(f==0)
    {
        f=size-1;
        deque[f]=data;
    }
    else
    {
        f=f-1;
        deque[f]=data;
    }
    fprintf(fpeq,"%d ",data);
}

// insert_rear function will insert the value from the rear
void insert_rear(int x)
{
    count++;
    c_eq++;
    int data;
    fscanf(fpin,"%d",&data);

    if(c_eq>=x+1)
    {
        printf("No elements present at input to add on to the queue\n");
        return;
    }

    if((f==0 && r==size-1) || (f==r+1))
    {
        printf("Overflow\n");
        return;
    }
    else if((f==-1) && (r==-1))
        {
        r=0;
        deque[r]=data;
    }
    else if(r==size-1)
    {
        r=0;
        deque[r]=data;
    }
    else
    {
        r++;
        deque[r]=data;
    }
   fprintf(fpeq,"%d ",data);
}

    // display function prints all the value of deque.
void display()
{
    int i=f;
    printf("\nElements in a deque are: ");

    while(i!=r)
    {
        printf("%d ",deque[i]);
        i=(i+1)%size;
    }
     printf("%d\n",deque[r]);
}


// delete_front() function deletes the element from the front
void delete_front()
{
    count--;
    c_dq++;
    int temp=deque[f];
    if((f==-1) && (r==-1))
    {
        printf("Deque is empty\n");
        return;
    }
    else if(f==r)
    {
        printf("\nThe deleted element is %d\n", deque[f]);
        f=-1;
        r=-1;

    }
     else if(f==(size-1))
     {
         printf("\nThe deleted element is %d\n", deque[f]);
         f=0;
     }
     else
     {
          printf("\nThe deleted element is %d\n", deque[f]);
          f=f+1;
     }
     fprintf(fpdq,"%d ",temp);
}

// delete_rear() function deletes the element from the rear
void delete_rear()
{
    count--;
    c_dq++;
    int copi;
    copi=deque[r];
    if((f==-1) && (r==-1))
    {
        printf("Deque is empty\n");
        return;
    }
    else if(f==r)
    {
        printf("\nThe deleted element is %d\n", deque[r]);
        f=-1;
        r=-1;

    }
     else if(r==0)
     {
         printf("\nThe deleted element is %d\n", deque[r]);
         r=size-1;
     }
     else
     {
          printf("\nThe deleted element is %d\n", deque[r]);
          r=r-1;
     }
     fprintf(fpdq,"%d ",copi);
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
    int i;
    fpq=fopen("queue.txt","w");
   for(i=f;i<r;i++)
    {
      fprintf(fpq,"%d ",deque[i]);
    }
    fprintf(fpq,"%d ",deque[i]);
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
    printf("\n1 to insert front\n2 to insert rear \n3 to delete front\n4 to delete rear\n5 to display\n6 to exit\n");
    scanf("%d",&choice);

     switch(choice)
    {

        case 1:insert_front(x);
               fprintf(fop,"insert_front()\n");
               fclose(fpq);
               restore();
               break;
        case 2:insert_rear(x);
              fprintf(fop,"insert_rear()\n");
              fclose(fpq);
              restore();
              break;
        case 3 : delete_front();
                 fprintf(fop,"delete_front()\n");
                 fclose(fpq);
                 restore();
                 break;
        case 4 : delete_rear();
                 fprintf(fop,"delete_rear()\n");
                 fclose(fpq);
                 restore();
                 break;
        case 5:display();
               break;
        case 6 : fclose(fpin);
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

