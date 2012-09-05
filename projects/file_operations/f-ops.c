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


/* get_input: read data from a stream, stops reading on EOF
 * src: source of data, stdin or file...
 * Returns a pointer to the characters read or NULL
 */
char *get_input(FILE *src)
{
	int bufsz = 2; /* The size of our char storing buffer */
	int num_ch = 0; /* Keep a count of the number of chracters read */
	char *buf = NULL; /* the buffer for storing character input */
	printf("&buf: %p\n", buf);

	if ((buf = malloc(bufsz)) == NULL) {
		printf("ERROR: %s(), malloc() fail\n", __func__);
	} 
	else {
		while ((buf[num_ch] = getc(src))!=EOF) {
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
				printf("&buf: %p\n", buf);
			}
		}
		buf[num_ch] = '\0'; /* Terminate the string */
	}
	return buf;
}

/* print_str: prints characters in str and their ascii codes. */
void print_str(char *str)
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
			printf("'%3s': %#04x\n", ascii_ctrl[str[i]], str[i]);
		}
	}
	return;
}


int main(int argc, char **argv)
{
	/* char my_str[MAX_CHAR]; */
	char *my_str = NULL;
	FILE *data_src = stdin;
	printf("This is f-ops.\n");

	/* Check for filename on command line */
	if (argc > 1) {
		data_src = fopen(argv[1], "r")
		if (!data_src) {
			printf("ERROR: Can't open '%s'\n", argv[1]);
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


	printf("&my_str: %p\n", my_str);
	/*
	printf("Please enter some text, (# to finish): ");
	my_str = get_input(stdin);
	*/
	printf("&my_str: %p\n", my_str);

	printf("strlen(my_str): %d\n", strlen(my_str));
	printf("You entered: %s\n", my_str);
	print_str(my_str);

	free(my_str);
	printf("After free(my_str), ");
	printf("&my_str: %p\n", my_str);
	my_str = NULL;
	printf("After 'my_str = NULL' assignment, ");
	printf("&my_str: %p\n", my_str);

	return(0);
}

