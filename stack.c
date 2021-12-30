#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3

int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE-1){
        printf("stack overflow");
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        printf("No element to top.");
        return;
    }
    top--;
}

void Peek(){

    if(top == -1){
        printf("there is no element in stack.\n");
        return;
    }
    printf("last element is: %d\n",A[top]);
}

void Print(){
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    Peek();
    Push(5);Print();
    Push(7);Print();
    Push(3);Print();
    Pop();Print();
    Push(9);Print();
    Peek();
    
    
    
    


return 0;
}
