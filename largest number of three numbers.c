#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3){
    int result;
    if(num1>=num2 && num1>=num3){
        result=num1;
    }
    else if (num2>=num1 && num2>num3){
        result=num2;
    }
    else {
        result=num3;
    }
    return result;
}

int main()
{
    int n1;
    printf("Enter first number: ");
    scanf("%d", &n1);
    int n2;
    printf("Enter second number: ");
    scanf("%d", &n2);
    int n3;
    printf("Enter third number: ");
    scanf("%d", &n3);
    printf("The largest number of the three numbers is %d", max(n1,n2,n3));



    return 0;
}
