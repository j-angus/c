/* char_ops.h 
 * Header file for char operations.
 */

#ifndef _CHAR_OPS_H_
#define _CHAR_OPS_H_ 1

#define MAX_BUF_SIZE (UINT_MAX - 1)

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


/* read_line: 	Read a string of char until:
 * 		We hit \n or EOF.
 * 		The number of char read is equal to num_char.
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
char *read_line(FILE *src, size_t num_char);

#endif /* _CHAR_OPS_H_ */
