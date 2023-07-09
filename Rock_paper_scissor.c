#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//comparing user input with computer generated input and returning 1 if user wins and -1 if computer wins
int output(char comp,char user)
{
    if(comp==user)
    return 0;
    else if(user=='r'&&comp=='p')
    return -1;
    else if(user=='r'&&comp=='s')
    return 1;
    else if(user=='p'&&comp=='r')
    return 1;
    else if(user=='p'&&comp=='s')
    return -1;
    else if(user=='s'&&comp=='r')
    return -1;
    else 
    return 1;
}
int main()
{
    char comp, user;
    srand(time(0));
    int n;
    n = rand() % 100;

    if(n<33)
    comp='r';
    else if(n>=33 && n<=66)
    comp='p';
    else
    comp='s';

    printf("Enter r for 'rock'\n      p for 'paper'\n      s for 'scissor'\n ");
    scanf("%c", &user);
    int result=output(comp,user);
    if(result==1)
    printf("You won! You chose %c and computer chose %c\n", user, comp);
    else if(result==-1)
    printf("You lost! You chose %c and computer chose %c\n", user, comp);
    else
    printf("Match tied! You chose %c and computer chose %c\n", user, comp);
     printf("r stands for 'rock'\np stands for 'paper'\ns stands for 'scissor'\n ");
    return 0;
}