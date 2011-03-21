/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch06exXX.c
 * loops. 
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Exercises \n\n");
	
	int i, j;

	i = 9384;
	do {
		printf("i == %d\n", i);
		i /= 10;
	} while (i > 0);

	/* Ex3 */
	for (i = 5, j = i -1; i > 0, j > 0; --i, j = i - 1)
		printf("i == %d\n", i);

	/* Ex4 */
	printf("for (i = 0; i < 10; i++)\n");
	for (i = 0; i < 10; i++)
		printf("i == %d\n", i);

	printf("for (i = 0; i++ < 10;)\n");
	for (i = 0; i++ < 10;)
		printf("i == %d\n", i);

	printf("for (i = 0; i < 10; ++i)\n");
	for (i = 0; i < 10; ++i)
		printf("i == %d\n", i);

	/* Ex8 */
	/* infinite loop
	for (i = 10; i >= 1; i /= 2)
		printf("i == %d\n", i++);
	*/

	/* Ex9 */
	/* still an infinite loop
	i = 10;
	while (i >= 1) {
		printf("i == %d\n", i++);
		i /= 2;	
	}
	*/

	/* Ex10 */
	int sum = 0;
	for (i = 0; i < 10; ++i) {
		printf("%d %% 2: %d\n", i, i % 2);
		if (i % 2)			
			continue;
		sum += i;
		printf("sum == %d\n", sum);
	}
	printf("sum == %d\n", sum);

	/* Ex12 */
	/* test for a prime number */
	int n = 13; /* number to test for being prime */
	int d; /* for looping through factors of n */
	for (d = 2; (d * d) != n; ++d)
		if (n % d == 0)
			break;
	if (d < n)
		printf("%d is divisable by %d\n", n, d);
	else
		printf("%d is prime.\n", n);
	
	return 0;
}
