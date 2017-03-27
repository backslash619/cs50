#include<stdio.h>

void swap(int *a,int *b);

int main(void){
    int x=1;
    int y=2;
    printf("x is %i\n",x);
    printf("y is %i\n",y);
    printf("swapping...\n");
    swap(&x,&y);
    printf("%i,%i\n",x,y);
    printf("%p,%p\n",(void*)&x,(void*)&y);
    printf("swapped...\n");
    printf("x is %i\n",x);
    printf("y is %i\n",y);
}

void swap(int *a,int *b){
    printf("%p,%p\n",(void*)a,(void*)b);
    int temp = *a;
    *a=*b;
    *b=temp;
}
