#include <stdio.h>
#include <stdlib.h>

double cube(double num)
{
return num*num*num;;
}


int main()
{
    double number;
    printf("Enter your number: ");
    scanf("%lf", &number);
    printf("Answer: %f",cube(number));

    return 0;
}

