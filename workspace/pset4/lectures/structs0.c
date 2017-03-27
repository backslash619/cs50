#include<stdioh>

#include "structs.h"

#define STUDENTS 3

int main(void){
    
    student arr[STUDENTS];
    
    for (int i =0;i<STUDENTS;i++){
        
        printf("name:");
        arr[i].name=get_string();
        
        printf("room:");
        arr[i].room=get_string();
        
    }
    
    
    for (int i =0; i<STUDENTS;i++){
        
        
    }
    
}