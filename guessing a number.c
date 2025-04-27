#include <stdio.h>
#include <stdlib.h>


int main()
{

 int secretNumber= 5;
 int guess;
 while(guess!= secretNumber)



{
    printf("Enter a number: ");
    scanf("%d", &guess);

    if (guess!=5)
{
    printf("Wrong number try again\n");

}


 }
    printf("You win!");


    return 0;
}
