#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

Node* getNewNode(int);
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
//getting new node
Node* getNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//inserting head (top)
void Push(int data){
    Node* temp = getNewNode(data);
    if(top == NULL){
        top = temp;
        return;
    }
    
    temp->next = top;
    top = temp;
}

void Pop(){

    if(top == NULL){
        printf("there is no element in the stack.\n");
        return;
    }
    Node* temp = top;
    top = temp->next;
    free(temp);

}

void Print(){
    Node* temp = top;
    if(top == NULL){
        printf("there is no element in the stack.\n");
        return;
    }
    printf("Stack is: ");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}