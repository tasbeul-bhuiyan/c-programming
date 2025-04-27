#include <stdio.h>
#include <stdlib.h>


int main()
{
    int nums[3][2] = {
        {1,2},
        {3,4},
        {5,6},
        };

        int i,j;
        printf ("i= ");
        scanf("%d",&i);
        printf("j= ");
        scanf("%d",&j);
        printf("%d",nums[i] [j]);
    return 0;
}
