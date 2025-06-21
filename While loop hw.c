/*
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i=1,sum=0,number;
    printf("Enter a number: ");
    scanf("%d",&number);
    while(i<=number)
    {
        sum = sum+i;
        i++;
    }
    printf("The sum is = %d",sum);
}
*/
/*
#include <stdio.h>

int main() {
    int number,i=1;
    float sum=0;
    int sign=1;

    printf("Enter a number: ");
    scanf("%d",&number);

    while(i<=number)
    {
        sum=sum+sign*(float)i/(i+1);
        sign=-sign;
        i++;
    }

    printf("The sum is = %.2f\n",sum);

    return 0;
}
*/
/*
#include <stdio.h>

int main()
{
    int number,i=1;
    float sum=0;

    printf("Enter the value of number: ");
    scanf("%d",&number);

    while (i<=number)
    {
        sum+= (float)i/(i+1);
        i++;
    }

    printf("Sum = %.4f\n",sum);

    return 0;
}
*/
/*
#include <stdio.h>

int main()
 {
    int number,i=1;
    int product=1;


    printf("Enter a number: ");
    scanf("%d",&number);

    while (i<=number)
    {
        product*=i;
        i++;
    }

    printf("%d\n",product);

    return 0;
}
*/
