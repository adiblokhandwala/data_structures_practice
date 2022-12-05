#include<stdio.h>
#include<stdlib.h>

/* A program written to implement linked list using structrues and it's different functions written by Adib Lokhandwala
210410107063 dated 27/11/2022 15:30 hours.
NOTE: in this program index of linked list starts with 0 contrary to conventional programming standards.
READ: Program tested and every function works from my side,
contact author if any bug or error found*/


struct node
{
    int data;
    struct node* next;
};

struct node* head  = NULL;

void traversal(){
    //prints every element of linked list sequentially

    if(head == NULL){
        printf("--------------------------------------\n");
        printf("Empty list.....\n");
        printf("--------------------------------------\n");


    }
    else{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
        printf("--------------------------------------\n");

    for(int i = 1;ptr!=NULL;i++){
        printf("element %d of linkedlist = %d\n",i,ptr->data);
        ptr = ptr->next;
    }
        printf("--------------------------------------\n");

    }
}




void insertatbeginning(int value){
    //inserts a node at start
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = value;
    if(head == NULL){
        head = nn;
        head->next = NULL;
    }

    else{
        nn->next = head;
        head = nn;
    }
}


int deletefromfirst(){
    //deletes a node from start
    if(head == NULL){
        printf("empty list!\n");
        return -1;
    }
        struct node* ptr = (struct node*)malloc(sizeof(struct node));

    if(head->next == NULL){
        ptr = head;
        head->next = NULL;
        free(ptr);
    }
    else{
        ptr = head;
        head = head->next;
        free(ptr);

    }
    return 0;
}


void insertatend(int value){
    //inserts a node from end
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    struct node* current = (struct node*)malloc(sizeof(struct node));
    nn->data = value;
    nn->next = NULL;
    current = head;
    if(head == NULL){
        head = nn;
        // return 0;
    }
    else{
        current = head;
        while(current->next != NULL){
            current = current->next;
        }

        current->next = nn;
        // return 0;
    }
    
}


void deletefromend(){
    //deletes a node from end
    if (head == NULL){
        printf("cannot delete from empty list");
    }

    else{
        struct node* previous = (struct node*)malloc(sizeof(struct node));
        struct node* current = (struct node*)malloc(sizeof(struct node));

        current = head;
        previous = NULL;

        while(current->next != NULL){
            previous = current;
            current = current->next;
        }
        if(previous == NULL){
            head = NULL;
            free(current);
        }
        else{
            previous->next = NULL;
            free(current);
        }

    }


}


void searchtheindex(int key){
    //prints whether an element is present in the key and the index if found, also works with multiple instances
    struct node* current= (struct node*)malloc(sizeof(struct node));
    int flag = 0;
    current = head;
    int count = 0;
    for(int i = 1; current!=NULL;i++){
        if(current->data == key){
            printf("found element %d at index %d\n",current->data,i);
            flag = 1;
            count++;
        }
        current = current->next;
    }

    if(flag ==0){
        printf("element not found in the list\n");
    }
}

void insertatindex(int element,int index){
    //inserts an element at specified index
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));

    nn->data = element;
    p = head;
    int i =1;
    while(i!= index - 1){
        p = p->next;
        i++;
    }
    nn->next = p->next;
    p->next = nn;
}

void deletefromindex(int index){
    //deletes an element in linked list of specified index
    struct node* current = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));
    int i = 1;
    current = head;
    p = NULL;

    while(i != index){
        p = current;
        current = current->next;
        i++;
    }
    p->next = current->next;
    free(current);
}


void deletebyvalue(int key,int count_skip){
        //deletes a value  in linked list
    //count_skip specifies the instances you want to skip if multiple instances of value
    //found in the program, for deletion of  first instance, insert the 3rd argument 0
    struct node* current= (struct node*)malloc(sizeof(struct node));
    int flag = 0;
    current = head;
    int index;
    
    for(int i = 1; current!=NULL;i++){
        if(current->data == key){
        if(count_skip>0){
            current = current->next;
            count_skip--;
            continue;

        }
        else{
          index = i;
          flag = 1;
          break;
        }
          
        }
        current = current->next;
    }
    if(flag == 0){
        printf("element not found in the list\n");
    }
    else if(index == 1){
        deletefromfirst();
    }
    else if(current->next == NULL){
        deletefromend();
    }
    else{
        deletefromindex(index);
    }
}

void insertaftervalue(int key,int element,int count_skip){

    //inserts a value after an element(key) in linked list
    //count_skip specifies the instances you want to skip if multiple instances of value
    //found in the program, for insertion after first instance, insert the 3rd argument 0
    struct node* current= (struct node*)malloc(sizeof(struct node));
    int flag = 0;
    current = head;
    int index;
    for(int i = 1; current!=NULL;i++){
        if(current->data == key){
            if(count_skip>0){
            current = current->next;
            count_skip--;
            continue;

        }
        else{
          index = i;
          flag = 1;
          break;
        }
        }
        current = current->next;
    }
    if(flag == 0){
        printf("element not found in the list\n");
    }
    else if(index == 1){
        insertatindex(element,2);
    }
    else if(current->next == NULL){
        insertatend(element);
    }
    else{
        insertatindex(element,index+1);
    }

}

int main(void){

while(1){

 int choice;
 printf("Please select your choice: \n");
 printf("---------------------------------------------------------\n");
 printf("select 0)To traverse the linked list\n");
 printf("select 1)To insert at the beginning of the linked list\n");
 printf("select 2)To delete at the beginning of the linked list\n");
 printf("select 3)To insert at the end of the linked list\n");
 printf("select 4)To delete from the end of the linked list\n");
 printf("select 5)To insert at an index of the linked list\n");
 printf("select 6)To delete at an index of the linked list\n");
 printf("select 7)To insert after a value of the linked list\n");
 printf("select 8)To delete an element by it's value in the linked list\n");
 printf("select 9)To search an element and print it's index\n");
 printf("select 10)To exit the program\n");


 scanf("%d",&choice);
        int value;
        int val;
        int index;
        int element;
        int ind;
        int key;
        int num;
        int skip;
        int k,ski;
        int ele;


 switch(choice){
    case 0:
        traversal();
        break;
    case 1:
        printf("enter the value: \n");
        scanf("%d",&value);
        insertatbeginning(value);
        break;
    case 2:
        deletefromend();
        break;
    case 3:
        printf("enter the value: \n");
        scanf("%d",&val);
        insertatend(val);
        break;
    case 4:
        deletefromend();
        break;
    case 5:
        
        printf("enter the value: \n");
        scanf("%d",&element);
        printf("enter the index: \n");
        scanf("%d",&index);
        insertatindex(element,index);
        break;
    case 6:
        printf("enter the index: \n");
        scanf("%d",&ind);
        deletefromindex(ind);
        break;
    case 7: 
       
        printf("enter the value: \n");
        scanf("%d",&key);
        printf("enter the value you want to insert after: \n");
        scanf("%d",&num);
        printf("enter the no of elements you want to skip if multiple instances found: \n");
        scanf("%d",&skip);
        insertaftervalue(key,value,skip);
        break;
    case 8: 
        printf("enter the value: \n");
        scanf("%d",&k);
        printf("enter the no of elements you want to skip if multiple instances found: \n");
        scanf("%d",&ski);
        deletebyvalue(k,ski);
        break;
    case 9:
        printf("enter the element: \n");
        scanf("%d",&ele);
        searchtheindex(ele);             
        break;
    case 10:
        exit(0);
        break;    
    default:
        printf("invalid choice!!!!!\n");
 }

}
 






    return 0;

}