#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a,b,c,d;//a is total. b marks obtained. c is total classes, is attendance of student.
    printf("\"Grade And Attendance Analysis\"\n\n");
    printf("Enter the total obtainable marks: ");
    scanf("%d",&a);
    printf("Enter the marks obtained by the student: ");
    scanf("%d",&b);
    printf("Enter the total number of class taken: ");
    scanf("%d",&c);
    printf("Enter the number of classes attended by the student: ");
    scanf("%d",&d);

    if(a<0||b<0||c<0||d<0||b>a||d>c)
    {
        printf("Invalid grade or attendance.");
    }


    else if(b>=0.9*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Excellent and regular student.");
    }

    else if(b>=0.9*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Excellent student but irregular.");
    }

    else if(b>=0.9*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Excellent student but bad attendance.");
    }


    else if(b>=0.8*a&&b<0.9*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Very good and regular student.");
    }

    else if(b>=0.8*a&&b<0.9*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Very good student but irregular.");
    }

    else if(b>=0.8*a&&b<0.9*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Very good student but bad attendance.");
    }



    else if(b>=0.7*a&&b<0.8*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Good and regular student.");
    }

    else if(b>=0.7*a&&b<0.8*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Good student but irregular.");
    }

    else if(b>=0.7*a&&b<0.8*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Good student but bad attendance.");
    }



    else if(b>=0.6*a&&b<0.7*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Above average and regular student.");
    }

    else if(b>=0.6*a&&b<0.7*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Above average student but irregular.");
    }

    else if(b>=0.6*a&&b<0.7*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Above average student but bad attendance.");
    }


    else if(b>=0.5*a&&b<0.6*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Average and regular student.");
    }

    else if(b>=0.5*a&&b<0.6*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Average student but irregular.");
    }

    else if(b>=0.5*a&&b<0.6*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Average student but bad attendance.");
    }



    else if(b>=0.4*a&&b<0.5*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Below average but regular student.");
    }

    else if(b>=0.4*a&&b<0.5*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Below average student and irregular.");
    }

    else if(b>=0.4*a&&b<0.5*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Below average student and bad attendance.");
    }



    else if(b>=0.3*a&&b<0.4*a&&d>=0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Weak but regular student.");
    }

    else if(b>=0.3*a&&b<0.4*a&&d>=0.5*c&&d<0.8*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Weak student and irregular.");
    }

    else if(b>=0.3*a&&b<0.4*a&&d<0.5*c&&!(b>a)&&!(d>c)&&!(d<0.2*c))
    {
        printf("Weak student and bad attendance.");
    }

    else if(b<0.3*a||d<0.2*c)
    {
        printf("Failed student.");
    }



    return 0;
}
