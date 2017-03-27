#include<stdio.h>
#include<cs50.h>

int get_negative(void);

int main(void){
    
    int i = get_negative();
    printf("%i\n",i);
    
}

int get_negative(void){
    int i ;
    do{
        i = get_int();
    }while(i>=0);
    return i;
}