#include " MendleBrotSet2.h"

int main(){

while (true)
{
    /* code */


double realPart;
double imaginary;

while (true)
{
    printf("Enter a real Part:\n");
    int indicator;
    if((indicator = scanf("%lf",&realPart)) == 1){
        break;
    }
    printf("You must enter a valid number\n");
    int ch;
    while (ch = getchar() !='\n' && ch != EOF);

    continue;
}
while (true)
{
    printf("Enter the imaginary part:\n");
    int indicator;
    if((indicator = scanf("%lf",&imaginary)) == 1){
        break;
    }
    printf("You must enter a valid number\n");
    int ch;
    while (ch = getchar() !='\n' && ch != EOF);

    continue;
}

double complex z = realPart + imaginary*I;


if (isInMendleSet(z,LIMIT)){
    printf("The number %.2lf + %.2lfi is in the Mandelbrot Set.\n", realPart, imaginary);
    printf("\n");

}

else{
    printf("The number %.2lf + %.2lfi is NOT in the Mandelbrot Set.\n", realPart, imaginary);
}

printf("\n");


int ch;
while (ch = getchar() !='\n' && ch != EOF);//cleaning input buffer
if (z == (0 + 0*I))
{
    printf("Exiting due to z = 0 + 0*i\n");
    break;
}

}



    return 0;
}
