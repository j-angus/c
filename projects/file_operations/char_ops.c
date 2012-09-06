/* char_ops.c
 * char type function definitions
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "char_ops.h"



/* read_line: 	Read a string of char until:
 * 		We hit \n or EOF
 * 		The number of char read is equal to num_char or 
 *		The number of char read is equal to MAX size_t type - 1.
 * 		\n is not kept.
 * Parameters
 * ----------
 * src:		The input stream to read from
 * num_char:	Max number of char to read at any one time
 *
 * Returns
 * -------
 * A pointer to the string read, NULL on error or no data.
 */
char *read_line(FILE *src, size_t max_char)
{
	printf("%s\n", __func__);
	char *buf = NULL;
	size_t bufsz = 2;
	size_t num_char = 0;

	if ((buf = malloc(bufsz)) == NULL) {
		printf("ERROR in %s(): malloc failed to allocate memory.\n",
				__func__);
	}
	else {
		while (*buf = getchar(src)) {
			if (*buf++ == '\n') {
				break;
			}
			++num_char;
			if (num_char > (bufsz - 2)) {

	return buf;
}
