#include<stdio.h>
#include<cs50.h>

int count = 0;
int sum_first=0;
int sum_second=0;

int main (void){
    long long credit_no;

    do{
        printf("Number:");
        credit_no = get_long_long();
    }while(credit_no <= 0 );
    
    while(credit_no>0){
        if (count%2==0){
            
            sum_first=sum_first+credit_no%10;
            credit_no = credit_no/10;  
            //printf("%lld\n  %i",credit_no,sum_first);
            count++;
        }
        else{
            //sum_second=sum_second+credit_no%10*2;
            credit_no = credit_no/10;  
            count++;
            //printf("%lld\n %i",credit_no,sum_second);
            
        }
    }
    printf("%i",sum_first);

}