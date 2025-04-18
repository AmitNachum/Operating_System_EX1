#include <stdio.h>
#define NONZERO 10000

int divisionByZero(){

   return NONZERO / 0;
}

int main(){

    divisionByZero();

    return 0;
}