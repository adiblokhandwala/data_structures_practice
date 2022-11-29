#include<stdio.h>
int main(void){
    int a,b;
    printf("before swapping\n");
    printf("enter the value of a\n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);
    swap(a,b);
    printf("after swapping\n");
    printf("a = %d, b = %d\n",a,b);
    

}

void swap(int a, int b){
    int temp;
    temp =a;
    a = b;
    b = temp;

}