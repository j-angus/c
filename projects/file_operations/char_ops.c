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
	int ch;
	size_t num_ch = 0;

	if ((buf = malloc(bufsz)) == NULL) {
		printf("ERROR in %s(): malloc failed to allocate memory.\n",
				__func__);
		return NULL;
	}
	
	while ((ch = getc(src)) != EOF) {
		printf("\nch == [%c]:[%d]\n", ch, ch);		
		if (ch == '\n') {
			break;
		}
		buf[num_ch] = ch;
		++num_ch;
		if (num_ch == max_char)
			break;
		if (num_ch == (bufsz - 1)) {
			printf("num_ch: %u, \
				bufsz: %u, buf: %p\n",
				num_ch, bufsz, buf);

			bufsz += bufsz;
			if ((buf = realloc(buf, bufsz)) == NULL) {
				printf("ERROR in %s(): \
					malloc failed to allocate memory.\n",
					__func__);
				break;
			}
		}
	}
	/* NULL terminate string */
	if ((num_ch == 0) && (ch == EOF)) {
		free(buf);	
		buf = NULL;
	}
	else {
		buf[num_ch] = '\0';
	}
	if (buf) {
		printf("%s(), buf[0], [%c]:[%d]\n", __func__, buf[0], buf[0]);	
	}
	return buf;
}
