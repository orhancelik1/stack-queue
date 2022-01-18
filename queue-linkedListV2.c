#include<stdio.h>
#include<stdlib.h>

typedef struct q{
    int data;
    struct q *next;
}QUEUE;

QUEUE *front = NULL, *last = NULL;

int enqueue(int);
int dequeue();
void Display();
void Reset();

void main()
{
    enqueue(5);
    enqueue(7);
    enqueue(2);
    enqueue(9);
    enqueue(1);
    Display();
    dequeue();
    dequeue();
    Display();
    Reset();
    Display();
    
}

int enqueue(int data){
    QUEUE *temp = (QUEUE*)malloc(sizeof(QUEUE));
    temp->data = data;
    temp->next = NULL;
    if(front == NULL)
    {
        front = last = temp;
        return 0;
    }
    last->next = temp;
    last = temp;
    last->next = NULL;
    return 0;
    
}
int dequeue(){
    QUEUE *temp = front;
    if(front == NULL){ //if queue is empty
        printf("Queue is empty.\n");
        return 0;
    }
    if(front == last){ //if we have only one element
        front = last = NULL;
        return 0;
    }
        
    front = front->next;
    free(temp);
    return 0;
}

void Reset(){
    QUEUE *temp;
    while(front){
        temp = front;
        front = front->next;
        free(temp);
        

    }
}

void Display(){
    QUEUE *temp = front;
    if(front == NULL){
        printf("list is empty");
        return;
    }
        
    printf("\nFRONT");
    while(temp)
    {
        printf("\t%d",temp->data);
        temp = temp->next;
    }
    printf("\tEND\n");
    
}
