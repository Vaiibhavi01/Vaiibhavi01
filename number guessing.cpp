#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int random,guess; int numberofguess=0;
	srand(time(NULL));
	printf("welcome to the world of guessing numbers\n");
	random=rand()%100+1;
	do
	{
		printf("\n please enter number between 0 to 100:");
		scanf("%d",&guess);
		numberofguess++;
		if(random>guess)
		{
			printf("guess larger number\n");
			
		}
		else if(random<guess)
		{
			printf("guess smaller number\n");
		}
		else
		{
			printf("Congratulations !!! you have successfully guessed the number in %d attempts",numberofguess);
		}
	}
	while(guess!=random);
	
	printf("bye bye. Thanks for playing");
	printf("game by: Vaibhavi ");
	return 0;
}
