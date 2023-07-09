#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    //Generating a random number 2 digit number
    srand(time(0));
    int num, count=1, input;
    num = rand() % 100;
    do
    {
        printf("Enter the number between 1 to 100\n");
        scanf("%d", &input);
        if(input>num)
        printf("Lower number please\n");
        else if(input<num)
        printf("Upper number please\n");
        else
        printf("You guessed it right in %d attempts\n", count);
        count++;
    }while(input!=num);
    printf("Yes the number is %d\n", num);
    return 0;
}