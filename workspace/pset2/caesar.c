#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

void cipher(int key);

int main(int argc,string argv[]){

    int key;
    
    if(argc > 2 || argc==1){
        
        printf("Usage: ./caesar k\n");
        return 1;
    }
    
    key=atoi(argv[1]);
    cipher(key);
}

void cipher(int key){
    string plain_text="";
    printf("Plain Text :");
 
    plain_text = get_string();
    
    printf("Cipher Text:");
        
    for(int i =0,n=strlen(plain_text);i<n;i++){
        
        if(isalpha(plain_text[i])){
            
            if(islower(plain_text[i])){
                printf("%c",(((plain_text[i]-97)+key)%26)+97);
            }
            else {
                printf("%c",(((plain_text[i]-65)+key)%26)+65);
            }
        }
        else{
            printf("%c",plain_text[i]);
        } 
    }
    printf("\n");
}