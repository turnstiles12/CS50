#include <stdio.h>
#include <cs50.h>

int main(void){
    
    int n = 1;
    int x;
    do
    {
        x = get_int("Height: ");
        
    }
    while(x<1 || x>8);
    for(int i=0; i<x; i++){
        for(int j=0; j<n; j++){
            printf("#");
        }   
        printf("  #\n");
        n++;
    }
}