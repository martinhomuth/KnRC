#include <stdio.h>

#define MAXLINE 1000

#define COLNUM 8
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(int argc, char *argv[])
{
        int i;                      /* counter variable */
        int col_pos_out;            /* position of the output buffer */
        int col_pos_in;             /* position of the input buffer */
        int tabs;                   /* number of tabs to be written */
        int blanks;                 /* number of blanks to be written */
	int pos_l;                  /* remember the leftmost position of the blank space */
	int to_tabstop;             /* the number of blanks until the first tabstop */
        int ch;
        char line[MAXLINE];

        col_pos_out = col_pos_in = i = tabs = 0;
        blanks = 0;
        while((ch = getchar()) != EOF)
        {
                col_pos_in++;
                if(ch == ' ')
                {
			/* determine the position left of the blanks */
			if(blanks == 0)
				pos_l = col_pos_in;
                        blanks++;   /* count consecutive blanks */
                }
                else if(blanks > 0)  /* first non-blank character */
                {
			/* blanks until tabstop */
			to_tabstop = COLNUM - (pos_l % COLNUM);
			/* only insert the first tab
			 * if there are enough blanks */
			if(to_tabstop < blanks)
			{
				blanks -= to_tabstop + 1;
				tabs++;
			}
			/* determine the full tabs */
			while(blanks > COLNUM)
			{
				tabs++;
				blanks -= COLNUM;
			}
                        for(i = 0; i < tabs; i++)
                                line[col_pos_out++] = '\t';
                        for(i = 0; i < blanks; i++)
                                line[col_pos_out++] = ' ';
			tabs = 0;
                        blanks = 0;
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
			col_pos_in = 0;
                }
        }
        return 0;
}
