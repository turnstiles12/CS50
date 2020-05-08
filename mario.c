#include <stdio.h>
#include <cs50.h>

int main(void){
    int n = 1;
    int x, t;
    do
    {
        x = get_int("Height: ");//input the height
        
    }
    while(x<1 || x>8);
    for(int i=0; i<x; i++){
        for( t=x-n; t>0; t--){// format the bricks centered, printed x-1 times
            printf(" ");
        }
        for(int j=0; j<n; j++){ //Left side
            printf("#");
        }  
        printf("  "); //Space in between
        for(int y=0; y<n; y++){//Right side
            printf("#");
        }
        printf("\n"); //next line
        n++;
    
    }
}