#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

void Push(int);
void Pop();
void Print();

int main(int argc, char const *argv[])
{
    Push(2);Print(); //2
    Push(4);Print(); //4 2
    Push(1);Print(); //1 4 2
    Push(0);Print(); //0 1 4 2
    Pop();Print();   //1 4 2
    Pop();Print();   //4 2
    Push(7);Print(); //7 4 2
    
    return 0;
}

//inserting head (top)
void Push(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

void Pop(){

    Node* temp = top;
    top = temp->next;
    free(temp);

}

void Print(){
    Node* temp = top;
    printf("Stack is: ");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}