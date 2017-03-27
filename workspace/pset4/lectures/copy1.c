#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(void){
    
    printf("s: ");
    char *s = get_string();
    if(s==NULL){
        
        return 1;  
    }
    
    char *t = malloc((strlen(s)+1) * sizeof(char));
    
    printf("%i\n%i\n",*s,*t);
    printf("%s\n%s\n",s,t);
    
    if(t==NULL){
        return 1;
    }
    for (int i =0 ,n=strlen(s);i<=n;i++){
        t[i]=s[i];
    }
    
    printf("%i\n",*t);
    if(strlen(t)>0){
        t[0]= toupper(t[0]);
    }
    
    printf("s: %s\n",s);
    printf("t: %s\n",t);
    free(t);
    return 0;
}