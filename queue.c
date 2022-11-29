#include<stdio.h>

struct Q
{
    int arr[20];
    int front;
    int rear;
} queue;

int main(){
  
  printf("A program to implement Queue using Arrays writeen by 210410107063 dated 22/11/2022 13:21 hours.\n");
  while(1){
    int choice;
    printf("-----------------------------------------------------------------");
    printf("Select an option to perform the required operation.\n");
    printf("1)create\n2)display\n3)enqueue\n4)dequeue\n5)for exit\n ");
    scanf("%d",&choice);

    switch(choice){
        case 1: 
            create();
            break;
        case 2:
            display();
            break;
        case 3: 
            enqueue();
            break;
        case 4:
            dequeue();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Sorry, Please choose an appropriate choice!n");     


    }

  }


}

void create(void){
    int size;
    int choice;
    printf("enter the size of the queue\n");
    scanf("%d",&size);
    queue.front = 0;
    //intializing the array using the loop
    for(int i = 0; i<size;i++){
        printf("enter element %d: \n",i);
        scanf("%d",&choice);
        queue.rear++;
        queue.arr[i] = choice;
    }
}


void display(void){
    for(int i=queue.front , j=1 ; i<queue.rear;i++,j++){
        printf("Element %d of queue is %d \n",j,queue.arr[i]);
    }
}

void enqueue(){
    if(queue.rear >= 19){
        printf("Queue Overflow!!!");
    }
    else{
    int choice;
    printf("enter the element: \n");
    scanf("%d",&choice);
    queue.rear++;
    queue.arr[queue.rear] = choice;
    }

}


void dequeue(void){
    if(queue.front == queue.rear){
        printf("Queue Underflow!!!");
    }
    else{
    queue.front++;
    }
}