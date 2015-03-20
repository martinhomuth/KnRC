#include <stdio.h>

#define MAXLINE 1000

#define COLNUM 8
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(int argc, char *argv[])
{
        int i;
        int col_pos_out;            /* position of the output buffer */
        int col_pos_in;             /* position of the input buffer */
        int blanks_in;              /* number of consecutive blanks */
        int tabs;                   /* number of tabs to be written */
        int blanks_out;             /* number of blanks to be written */
        int ch;
        char line[MAXLINE];

        col_pos_out = col_pos_in = i = blanks_out = tabs = 0;
        blanks_in = 0;
        while((ch = getchar()) != EOF)
        {
                col_pos_in++;
                if(ch == ' ')
                {
                        blanks_in++;   /* count consecutive blanks */
                }
                else if(blanks_in > 0)  /* first non-blank character */
                {
                        /* determine the number of blanks after the last tab stop */
                        blanks_out = MIN(blanks_in, (col_pos_in % COLNUM));
			/* remove the blanks that will still be blanks from
			 * the total amount of blanks received */
                        blanks_in -= blanks_out;
                        /* determine the number of tabs until the tab stop above */
                        if(blanks_in > 0)
			{
				/* TODO: this determines the first tab
				 * need to determine all remaining tabs
				 * maybe using a while loop for all the remaining
				 * blanks according to COLNUM */
                                tabs = (col_pos_in % COLNUM);
			}
#if 0			
			printf("inserting %d tabs, %d blanks and the character %c\n",
			       tabs, blanks_out, ch);
#endif			
                        for(i = 0; i < tabs; i++)
                                line[col_pos_out++] = '\t';
                        for(i = 0; i < blanks_out; i++)
                                line[col_pos_out++] = ' ';
                        blanks_in = 0;
                        line[col_pos_out++] = ch;
                }
                else
                {
                        line[col_pos_out++] = ch;
                }

		/* print the current line */
                if(line[col_pos_out-1] == '\n') 
                {
                        line[col_pos_out] = '\0';
                        printf("%s",line);
                        col_pos_out = 0;
                }
        }
        return 0;
}
