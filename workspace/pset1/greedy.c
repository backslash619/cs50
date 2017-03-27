#include<stdio.h>
#include<cs50.h>
#include<math.h>

#define QUARTER 25;
#define DIME 10;
#define NICKEL 5;

    int leftover = 0;
    int quarter=0;
    int dime=0;
    int nickel=0;
void coins(float n);
    
int main (void){
    float money;
    do{
        printf("O hey how much change is owed ?\n");
        money = get_float();
        if (money==0)
        {
            printf("No change is required");
            return 0;
        }
    }while(money<0);
    coins(money);
}

void coins(float n){
    int round_value = (int)round(n*100);
    
    quarter = round_value/QUARTER;
    leftover = round_value%QUARTER;
    
    dime = leftover/DIME;
    leftover = leftover%DIME;
    
    nickel = leftover/NICKEL;
    leftover = leftover%NICKEL;
    
    printf("%i\n", leftover+quarter+dime+nickel);
}