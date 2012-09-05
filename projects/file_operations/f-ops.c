/* f-ops.c
 * 2012-08-31
 * Try using c file operations
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 128 /* Max number of char to store in string buffers */


/* get_input: Read data from a stream, stops reading on EOF
 * src: source of data, stdin or file...
 * Returns a pointer to the characters read or NULL
 */
char *get_input(FILE *src)
{
	int bufsz = 2; /* The size of our char storing buffer */
	int num_ch = 0; /* Keep a count of the number of chracters read */
	char *buf = NULL; /* the buffer for storing character input */
	printf("buf: %p\n", buf);

	if ((buf = malloc(bufsz)) == NULL) {
		printf("ERROR: %s(), malloc() fail\n", __func__);
	} 
	else {
		while ((buf[num_ch] = getc(src)) != EOF) {
			++num_ch;
			if (num_ch == bufsz - 1) {
				printf("%s(), strlen(buf): %d\n", 
						__func__, strlen(buf));
				bufsz += bufsz;
				printf("%s(), bufsz: %d\n", __func__, bufsz);
				if ((buf = realloc(buf, bufsz)) == NULL) {
					printf("ERROR: %s(), realloc() fail\n",
						       	__func__);
					break;
				} 
				printf("buf: %p\n", buf);
			}
		}
		buf[num_ch] = '\0'; /* Terminate the string */
	}
	return buf;
}

/* print_ascii_code: displays the ascii codes of chars in a string */
void print_ascii_code(char *str)
{
	/* Codes for non-printable ascii control characters */
	const char *ascii_ctrl[] = {
		"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
		"BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI",
		"DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
		"CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"", "", "", "", "", "", "", "",
		"" ,"" ,"" ,"" ,"" ,"" ,"" ,"DEL"};
	
	for (int i=0; i < strlen(str); i++) {
		if (isprint(str[i])) {
			printf("'%3c':'%#04x'\n", str[i], str[i]);
		} 
		else {
			printf("'%3s': %#04x\n", 
					ascii_ctrl[(int)str[i]], str[i]);
		}
	}
	return;
}

/* allocate memory for a string buffer */
char *str_alloc(size_t bufsz)
{
	char *buf = NULL;
	
	if ((buf = malloc(bufsz)) == NULL) {
		printf("ERROR: in function %s(), malloc(%u) fail\n", 
				__func__, bufsz);
	}
	return buf;
}

int main(int argc, char **argv)
{
	char *my_str = NULL;
	FILE *data_src = stdin;
	printf("This is f-ops.\n");

	/* Check for command line parameters */
	if (argc > 1) {
		data_src = fopen(argv[1], "r");
		if (data_src == NULL) {
			printf("ERROR: Unable to open file '%s'\n", argv[1]);
			exit(1);
		}
		else {
			my_str = get_input(data_src);
			fclose(data_src);
		}
	}
	else {
		printf("Please enter some text, (EOF to finish): ");
		my_str = get_input(data_src);
	}


	printf("my_str: %p\n", my_str);
	printf("strlen(my_str): %d\n", strlen(my_str));
	printf("You entered: %s\n", my_str);
	print_ascii_code(my_str);

	free(my_str);
	printf("After free(my_str), ");
	printf("my_str: %p\n", my_str);
	my_str = NULL;
	printf("After 'my_str = NULL' assignment, ");
	printf("my_str: %p\n", my_str);

	size_t bufsz = UINT_MAX;
	while ((my_str = str_alloc(bufsz)) == NULL) {
		bufsz -= (UINT_MAX / 1000);
	} 
	printf("bufsz: %u\n", bufsz);
	printf("bufsz(kB): %u\n", bufsz/1000);
	printf("my_str: %p\n", my_str);
	printf("strlen(my_str): %d\n", strlen(my_str));
	/*
	for (size_t  i = 0; i < bufsz; ++i) {
		my_str[i] = 'x';
	}
	*/
	for (int i=0; i<100; i++) {
		printf("'%d' ", my_str[i]);
	}
	printf("\n");
	free(my_str);
	my_str = NULL;

	return(0);
}

