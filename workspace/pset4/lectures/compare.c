#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main(void){
    
    printf("s:");
    string s = get_string();
    
    printf("t:");
    string t = get_string();
    
    if(strcmp(s,t)==0){
        printf("same\n");
    }
    else{
        printf("different\n");
    }
    
}