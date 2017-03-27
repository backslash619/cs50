#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int count=0;
void cipher(string keyword);
char token(int count,string key_text);
    
int main(int argc,string argv[]){
     
     
    if(argc>2){
        printf("argc is >2");
        return 1;
    }
    
    for(int i=0 , n=strlen(argv[1]); i<n;i++){
        
        if(!isalpha(argv[1][i])){
            printf("not contain aplhabetic content ");
            break;
        }    
        else{
            cipher(argv[1]);        
        }
    }
}

void cipher(string key_text){
    
    int key;
    
    string plain_text="";
    printf("Plain Text :");
 
    plain_text = get_string();
    printf("Cipher Text:");
        
    for(int i =0,n=strlen(plain_text);i<n;i++){
        
        if(isalpha(plain_text[i])){
            
            if(islower(plain_text[i])){
                
                key =(int)token(count,key_text);
                count++;
                
                printf("%c",(((plain_text[i]-97)+key)%26)+97);
            }
            else {
                
                key = (int)token(count,key_text);
                count++;
                
                printf("%c",(((plain_text[i]-65)+key)%26)+65);
            }
        }
        else{
            printf("%c",plain_text[i]);
        } 
    }
    printf("\n");
    exit(0);
    
}

char token(int count1,string key_text){
    
    int text_len = strlen(key_text);
    int index = count1%text_len;
    if(islower(key_text[index])){
        
        return key_text[index]-97; 
    }
    else{
        return key_text[index]-65;
    }
}