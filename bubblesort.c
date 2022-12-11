#include<stdio.h>

void printarray(int* a,int size){
    for(int i =0; i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void bubblesort(int *arr,int size){
    
    int temp; //for swapping values
    int isSorted = 0; //flag for if array is sorted or not
    //intializing the outer loop for passes
    for(int i = 0;i<size-1;i++){
        //inner loop for comparing and swapping 
        isSorted = 1;
        printf("working on pass number : %d \n",i);
        for(int j = 0; j<size-i-1;j++){
            isSorted = 1;
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }

}

int main(void){

    int a[] = {1,525,63,45,26};
    printarray(a,5);
    bubblesort(a,5);
    printarray(a,5);


    return 0;
}