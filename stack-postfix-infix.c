#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 50

int A[N];
int top = 0;

void push(int item){
    if(top >= N){
        printf("stack overflow.\n");
        return;
    }
    A[top] = item;
    top++;
}

int pop(){
    if(top <= 0){
        printf("no element in the stack.\n");
        return -1;
    }
        
    top--;
    return A[top];
}

void reset(){
    top = -1;
}

int size(){
    return top;
}

int isEmpty(){
    if(top == -1)
        return 0;
    else
        return 1;
    
}


void main()
{
    char c;
    int right, left;
    while (1)
    {
        c = getchar();
        if(isdigit(c))
        {
            push((int)c - 48); // make all character digit (0123456789)
        }//if
        else
        {
            if(c == '\n'){ //program stops after pressing Enter
                printf("\n%d",pop());
                return;
            }

            right = pop();
            left = pop();
            switch (c)
            {
            case '+':
                push(left + right);
                break;
            case '-':
                push(left - right);
                break;
            case '/':
                push(left / right);
                break;                                
            case '*':
                push(left * right);
                break;            
            default:
                break;
            }

        }//else
    
    }//while
    
}
