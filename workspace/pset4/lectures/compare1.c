#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void){
    
    printf("s:");
    char *s = get_string();
    
    printf("t:");
    char  *t = get_string();
    
    printf("%i\n%i \n",*s,*t);
    printf("%s \n %s\n" ,s,t);
    if(s!= NULL && t!=NULL){
        
        if(strcmp(s,t)==0){
        printf("same\n");
        }
        else{
        printf("different\n");
        }
        
    }
    
}