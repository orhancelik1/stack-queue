#include<stdlib.h>
#include<stdio.h>

typedef struct STACK{
    int data;
    struct STACK* next;
}STACK;

STACK* top = NULL;

STACK* getNewSTACK(int);
void Push(int);
void Pop();
void Print();
void Front();
void Reset();
int Size();

int main(int argc, char const *argv[])
{
    
    Push(2);Print(); //2
    Push(4);Print(); //4 2
    Push(1);Print(); //1 4 2 
    Push(0);Print(); //0 1 4 2
    Pop();Print();   //1 4 2
    Pop();Print();   //4 2
    Push(7);Print(); //7 4 2
    printf("size of stack: %d\n",Size()); //3
    Front(); //7
    Reset();Print();
    
    return 0;
}
//getting new STACK
STACK* getNewSTACK(int data){
    STACK* newSTACK = (STACK*)malloc(sizeof(STACK));
    newSTACK->data = data;
    newSTACK->next = NULL;

    return newSTACK;
}

//inserting head (top)
void Push(int data){
    STACK* temp = getNewSTACK(data);
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
    STACK* temp = top;
    top = temp->next;
    free(temp);

}

void Print(){
    STACK* temp = top;
    if(top == NULL){
        printf("there is no element in the stack.\n");
        return;
    }
    
    while(temp!= NULL){
        printf("\n| %d |",temp->data);
        temp = temp->next;
    }
    printf("\n------\n");
}

void Front(){
    if(top == NULL){
        printf("there is no element.\n");
        return;
    }
    printf("top element is: %d\n",top->data);
}

void Reset(){
    STACK *temp;
    while(top){
        temp = top;
        top = top->next;
        free(temp);
    }
}

int Size(){
    int size = 0;
    STACK *temp = top;
    while(temp){
        temp = temp->next;
        size++;
    }
    return size;
}