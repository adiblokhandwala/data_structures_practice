#include<stdio.h>
#include<stdlib.h>

int main(void){
    int size;
    int i;
    int sum = 0;
    printf("enter the number of elements you want to enter\n");
    scanf("%d",&size);
    int* ptr = (int*)calloc(size,sizeof(int));
    if(ptr == NULL){
        printf("sorry memory not allocated\n");
    }
    for(int i=0;i<size;i++){
        scanf("%d",ptr+i);
        sum += *(ptr+i);
    }

    printf("The sum of elements of array are: %d\n",sum);
    free(ptr);
    printf("freeing memory.........\n");
    printf("done\n");

}