#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(void){
    
    printf("s: ");
    string s = get_string();
    if(s==NULL){
        
        return 1;  
    }
        
    //printf("%i\n%i\n",*s,*t);
    //printf("%s\n%s\n",s,t);
    
    string t = s;
    //printf("%i\n",*t);
    if(strlen(t)>0){
        t[0]= toupper(t[0]);
    }
    
    printf("s: %s\n",s);
    printf("t: %s\n",t);
    
}