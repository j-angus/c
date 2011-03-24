/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch08pp14.c
 * Write a program that reverses the words in a sentence.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 128

int main(void)
{
	int ch; /* user input */
	char sentence[MAX_LEN]; /* array to store user entered sentence */
	char terminator = '\0'; /* holds end of sentence terminator */
	int i = 0; /* array index */

	for (; i < MAX_LEN; ++i)
		sentence[i] = '\0';

	printf("Enter a sentence (max %d char long): ", MAX_LEN);
	for (i = 0; i < MAX_LEN; ++i) {
		ch = getchar();
		if (ch != '.' && ch != '!' && ch != '?') {
			sentence[i] = ch;
		}
		else {
			terminator = ch;
			break;
		}
	}

	printf("Reversal of sentence: ");
	for (i = 0; i < MAX_LEN; ++i) {
		if (sentence[i] != '\0')
			printf("%c", sentence[i]);
		else {
			printf("%c\n", terminator);
			break;
		}
	}
	return 0;
}
