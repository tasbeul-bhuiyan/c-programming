#include <stdio.h>
#include <stdlib.h>


int main()
{

 int secretNumber= 5;
 int guess;
 int guessCount = 0;
 int guessLimit= 3;
 int outOfGuesses = 0;

 while(guess!= secretNumber && outOfGuesses==0){
 if(guessCount<guessLimit)
    {


    printf("Enter a number: ");
    scanf("%d", &guess);
    guessCount++;

    if (guess!=secretNumber && guessCount<guessLimit)
{
    printf("Wrong number try again\n");

}
    }else
{
    outOfGuesses =1;

}


 }
 if(outOfGuesses==1){
    printf("Out of guesses,you lose!\n");
 }
 else{
    printf("You win!\n");}


    return 0;
}
