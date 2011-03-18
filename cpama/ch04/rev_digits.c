/**
 * file: rev_digits.c
 * gcc -Wall -o rev_digits rev_digits.c
 * 
 * Displays reversed digits entered by the user.
 *  
 */


#include <stdio.h>

/**
 * Reverses a two digit integer. 
 */
int rev_int(int num)
{
	return (num % 10) * 10 + (num / 10);
}

int main (int argc, char **argv)
{
	int num; /* the number entered by the user */
	
	printf("Please enter a positive two digit number: ");
	scanf("%d", &num);
	printf("You entered: %d\n", num);
	
	if (num < 10) {
		printf("That was a crap number!\n");
		printf("You're supposed to enter a positive two digit "
			"number dude.\n");
	}
	else
		printf("Digits reversed: %d", rev_int(num));
	
	
	return 0;
}

