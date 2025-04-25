#include <stdio.h>
#include <stdlib.h>

int main()
{
   char grade;
   printf("Enter your grade: ");
   scanf(" %c",&grade);
   switch(grade){
    case 'A':
    case 'a':
        printf("You did great!\n ");
        break;
    case 'B':
    case 'b':
        printf("You did alright!\n ");
        break;
    case 'C':
    case 'c':
        printf("You did poorly!\n ");
        break;
    case 'D':
    case 'd':
        printf("You did very bad!\n ");
        break;
    case 'F':
    case 'f':
        printf("You failed\n");
        break;
    default :
        printf("Invalid grade\n");
        break;

}



    return 0;
}
