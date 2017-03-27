#include<stdio.h>
#include<cs50.h>
int no_of_bottles(int n);

int main (void){
    printf("Minutes :");
    int i = get_int();
    printf("Bottles :%i\n",no_of_bottles(i));
}

int no_of_bottles(int n){
    int x ;
    x = n  * 192;
    return x/16;
}