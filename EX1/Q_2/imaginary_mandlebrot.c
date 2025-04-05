#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#define LIMIT 10000




double absoluteValue(double complex z){
 
    return sqrt(pow(creal(z),2)+ pow(cimag(z),2));
}

int isInMendleSet(double realPart,double imginary){
  double complex z = 0 + 0*I;
  double complex c = realPart + imginary*I;

  for (size_t i = 0; i < LIMIT; i++)
  {
    z = z*z + c;

    if (absoluteValue(z) > 2)
    {
        return 0;
    }
    
  }

  return 1; 
  
    
}


int main(int argc,char *argv[]){

    if (argc < 3)
    {
     fprintf(stderr,"Error: Not enough arguments provided.\n");  
     fprintf(stderr,"Usage: %s <realPart> <imaginaryPart>\n",argv[0]);
     exit(1); 
    }
    


double realPart = atof(argv[1]);
double imaginary = atof(argv[2]);

if (isInMendleSet(realPart,imaginary)){
    printf("The number %.2lf + %.2lfi is in the Mandelbrot Set.\n", realPart, imaginary);
    printf("\n");

}

else{
    printf("The number %.2lf + %.2lfi is NOT in the Mandelbrot Set.\n", realPart, imaginary);
}

printf("\n");


    return 0;
}
