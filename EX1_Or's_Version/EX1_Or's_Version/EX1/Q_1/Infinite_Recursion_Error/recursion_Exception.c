#include <stdio.h>

void overflow();



void overflow(){
    printf("Infinite recursion\n");
    overflow(); //infinte recursion.
}
int main(){


overflow();



    return 0;

}