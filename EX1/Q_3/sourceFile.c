#include " MendleBrotSet2.h"

double absoluteValue(double complex z){
    return sqrt(pow(creal(z),2)+ pow(cimag(z),2));
}

bool isInMendleSet(double complex input,int N){

  double complex z = 0 + 0*I;

  for (size_t i = 0; i < N; i++)
  {
    z = z*z + input;

    if (absoluteValue(z) > 2)
    {
        return false;
    }
    
  }

  return true; 
  
    
}