#include<stdio.h>
#include<stdlib.h>
#define N 50

int Q[N];
int front = 0, last = 0;

void display();
int enqueue(int);
int dequeue();
void reset();

void main()
{
   enqueue(4);
   enqueue(2);
   enqueue(7);
   enqueue(3);
   display();
   dequeue();
   dequeue();
   display();
   reset();
   display(); 
    
}


void display(){
    int i;
    if(last == 0){
        printf("queue is empty.\n");
        return;
    }
        

    printf("\nFRONT");
    for(i = front; i<last; ++i)
    {
        printf("\t%d",Q[i]);
    }
    printf("\tEND\n");
}

int enqueue(int data){
    if(last >= N){
        printf("queue is full.\n");
        return -1;
    }
    Q[last] = data;
    last++;
    return 0;
}

int dequeue(){
    int item;
    if(last == 0){
        printf("queue is empty.\n");
        return -1;
    }
    item = Q[front];
    for(int i = 1; i < last; i++){
        Q[i-1] = Q[i]; //we shift all items by -1  
    }                  //to save space
    last--;            //we can only use 'last--' operation to remove 
    return item;       //front but we cant use first spaces with this algorithm.
}

void reset(){
    front = last = 0;
}