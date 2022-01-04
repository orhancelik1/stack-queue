#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *front = NULL;
Node *rear = NULL;

///functions
Node *getNewNode(int);
void Enqueue(int);
void Dequeue();
void Print();

////driver main
int main(int argc, char const *argv[])
{
    Enqueue(2); //2
    Enqueue(4); //2 4
    Enqueue(1); //2 4 1
    Enqueue(6); //2 4 1 6
    Dequeue(); //4 1 6
    Print();

    return 0;
}


Node *getNewNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void Enqueue(int data){
    Node* newNode = getNewNode(data);
    
    if(front == NULL && rear == NULL){
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    rear->next = NULL;

}

void Dequeue(){
    Node* temp = front;
    if(front == NULL) return;

    if(front == rear){
        front = rear = NULL;
    }

    front = front->next;
    free(temp);
}

void Print(){
    Node* temp = front;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}