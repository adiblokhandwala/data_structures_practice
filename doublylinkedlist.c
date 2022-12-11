#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* previous;
    struct node* next;

};

int size = 0;
struct node* first = NULL;
struct node* last = NULL;


void traverse(){
    struct node* ptr = first;
    while(ptr!= NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("------------------------------\n");
}


void reverse_traverse(){
    struct node* ptr = last;
    while(ptr!= NULL){
        printf("%d->",ptr->data);
        ptr = ptr->previous;
    }
    printf("------------------------------\n");
}


void insertatbeginning(int value){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = value;
    if(first ==NULL){
        nn->previous = NULL;
        nn->next = NULL;
        first = nn;
        last = nn;
        size++;
    }
    else{
        nn->next = first;
        nn->previous = NULL;
        first->previous = nn;
        first = nn;
        size++;

    }
}

void removefrombeginning(void){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(first == NULL){
        printf("emtpy list\n");
    }
    if(first->next == NULL){
        temp = first;
        first->previous = NULL;
        first->next = NULL;
        free(temp);
        size--;

    }
    else{
        temp = first;
        first->next->previous = NULL;
        first = first->next;
        free(temp);
        size--;
    }


}

void insertatend(int value){
     struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = value;
    if(first ==NULL){
        nn->previous = NULL;
        nn->next = NULL;
        first = nn;
        last = nn;
        size++;

    }
    else{

          struct node* ptr = first;
         while(ptr->next!= NULL){
        ptr = ptr->next;
    }

    ptr->next = nn;
    nn->previous = ptr;
    nn->next = NULL;
    last = nn;
    size++;
        

    }

}

void removefromend(){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    

    if(first == NULL){
        printf("emtpy list\n");
    }
    else{

        ptr = last;
        ptr->previous->next = NULL;
        last = ptr->previous;
        free(ptr);
        size--;

    }
}



void removefromindex(int position){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(position > size){
        printf("error: postion value is greater than the size of linked list\n");
        return;
    }
     if(position ==1){
         removefrombeginning();

     }else
     if(position == size){
        removefromend();
     }
     else{

        if(position <= size/2){
            int index=1;
            ptr = first;
            while(index!=position){
                
                ptr = ptr->next;
                index++;
            }
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
            free(ptr);
            size--;
        }
        else{
                int index = size;
                ptr = last;
            while(index!=position){
                
                ptr = ptr->previous;
                index--;
            }
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
            free(ptr);
            size--;

        }
                
                

        }
     }



void insertatindex(int value,int position){

    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = value;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(position == 1){
        insertatbeginning(value);
    }
    else if(position == size){
        insertatend(value);
    }
    else{

        if(position <= size/2){
            int index=1;
            ptr = first;
            while(index!=position-1){
                
                ptr = ptr->next;
                index++;
            }
            
             
             nn->previous = ptr;
             nn->next = ptr->next;
             ptr->next->previous = nn;
             ptr->next = nn;
             size++;

        }
        else{
                int index = size;
                ptr = last;
            while(index!=position-1){
                
                ptr = ptr->previous;
                index--;
            }

            nn->previous = ptr;
             nn->next = ptr->next;
             ptr->next->previous = nn;
             ptr->next = nn;
             size++;
            

        }

    }

}

void reverse_the_list(){
    first = last;
}


int main(){
    insertatbeginning(7);
    insertatbeginning(9);
    insertatbeginning(3);
    insertatbeginning(1);
    insertatbeginning(8);
    insertatend(6);
    traverse();
    printf("size : %d \n",size);



    //  removefrombeginning();
    //  removefrombeginning();
    //  removefrombeginning();
    //  removefrombeginning();
    // removefromend();
    traverse();

    removefromindex(4);
    traverse();
    insertatindex(5,3);
    printf("before reversal\n");
    traverse();
    reverse_the_list();
    printf("after reversal\n");
    traverse();

    // reverse_traverse();


}