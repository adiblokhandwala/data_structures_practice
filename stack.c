#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int top;
    int size;
    int *arr;
}stack;

//function to initialize stack
void create_stack(int size){

    stack.arr = (int*)malloc(size*sizeof(int));
    stack.top = -1;
    stack.size = size;
}

void push(int element){
    if(isFull()){
        printf("StackOverflow\n");
    }
    else{
    stack.top++;
    stack.arr[stack.top] = element;
    }
}

void pop(void){
    if(isEmpty()){
        printf("StackUnderflow\n");
    }
    else{
    stack.arr[stack.top];
    stack.top--;
    }
}

void peep(int key){
    int index;
    for(int i = 0;i<index;i++){
        if(stack.arr[i] == key){
            printf("elment %d is stored at %d index\n",key,index);
            break;
        }
    }
}

void display(void){
    for(int i = 0;i<stack.size;i++){
        printf("element %d : %d\n",i,stack.arr[i]);
    }
}

int isFull(){
    if(stack.top >= stack.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(stack.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
  
  printf("A program to implement Queue using Arrays writeen by 210410107063 dated 22/11/2022 13:21 hours.\n");
  while(1){
    int choice;
    printf("-----------------------------------------------------------------");
    printf("Select an option to perform the required operation.\n");
    printf("1)create\n2)display\n3)push\n4)pop\n5)for exit\n ");
    scanf("%d",&choice);
    int element;
    int size;



    switch(choice){
        case 1: 
            printf("enter the size of stack: \n");
            scanf("%d",&size);
            create_stack(size);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("enter the element: \n");
            scanf("%d",&element);
            push(element);
            break;
        case 4:
            pop();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Sorry, Please choose an appropriate choice!n");     


    }

  }


}
