#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int random,guess;
    int num_of_guess = 0;
    srand(time(NULL));
    printf("welcome to the world of guessing numbers");
    random = rand() % 100 +1; //generating between 0 to 100
    do
    {
    printf("\nplease enter your guess between(1 to 100):");
    scanf("%d", &guess);
    num_of_guess++;
    if(guess < random)
    {
      printf("guess a larger number. \n");
    }
    else if(guess > random)
    {
      printf("guess a smaller number. \n");
    }
    else
    {
        printf("congratulations !!!you have successfully guessed the number in %d attempts", num_of_guess);
    }
    }while(guess != random);
        printf("\nbye bye, thank you for playing.");
        printf("\n developed by:Rachitha.k");
}