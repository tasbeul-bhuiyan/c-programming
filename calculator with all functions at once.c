#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b;
    printf("\"The Calculator\"\n\n");

    printf("Enter a value of a: ");
    scanf("%lf",&a);
    printf("Enter a value of b: ");
    scanf("%lf",&b);
    printf("Addition = %f\n",a+b);
    printf("Substraction = %f\n",a-b);
    printf("Multiplication = %f\n",a*b);
    printf("Division = %f\n",a/b);
    printf("Remaindar = %d\n",(int)a%(int)b);

    return 0;
}
