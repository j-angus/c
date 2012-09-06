/* co_tst_drv.c
 * test function defined in char_ops.c
 */

#include "char_ops.h"

int main(int argc, char *argv[])
{
	printf("co_tst_drv\n");
	char *line_buf = NULL;
	FILE *data_src = stdin;                                                    
	size_t max_line_length = UINT_MAX - 1;

        /* Check for command line parameters */                                    
        if (argc > 1) {                                                            
                data_src = fopen(argv[1], "r");                                    
                if (data_src == NULL) {                                            
                        printf("ERROR: Unable to open file '%s'\n", argv[1]);   
                        exit(1);                                                   
                }                                                                  
	}                                                                          

	while ((line_buf = read_line(data_src, max_line_length))) {
		printf("%s(), line_buf: %s\n", __func__, line_buf);
		printf("%s(), strlen(line_buf): %u\n", __func__, strlen(line_buf));
	}

	if ((data_src != NULL) && (data_src != stdin)) {
		fclose(data_src);
	}
	return 0;
}
