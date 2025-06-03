#include <stdio.h>

int main() {

    char a;
    printf("Choose an operator ['+','-','*','/']: ");
    scanf("%c",&a);

    double b,c,r;
    printf("Enter first number: ");
    scanf("%lf",&b);
    printf("Enter second number: ");
    scanf("%lf",&c);

    switch(a){
    case '+':
    r = b+c;
    break;

    case '-':
    r = b-c;
    break;

    case '*':
    r = b*c;
    break;

    case '/':
    r = b/c;
    break;

    default:
    printf("Invalid operator");

    }
printf("Result = %f",r);

    return 0;
}
