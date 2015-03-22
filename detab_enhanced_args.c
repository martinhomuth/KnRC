/* detab_enhanced_args.c --- 
 * 
 * Filename: detab_enhanced_args.c
 * Description: Extend detab to accept the shorthand "detab -n +m" to mean tab stops
 *              every n columns, starting at column m. Choose convenient (for the user)
 *              default behavior.
 * Author: Martin Homuth
 * Created: Sun Mar 22 15:36:32 2015 (+0100)
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */



#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXARGS 32

#define TABSTOPWIDTH 8
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(int argc, char *argv[])
{
        int i;                       /* counter variable */
        int col_pos_out;             /* position of the output buffer */
        int col_pos_in;              /* position of the input buffer */
	int to_tabstop;              /* the number of blanks until the first tabstop */
        int ch;                      /* store the current character */
        char line[MAXLINE];
	int tabstopwidth;            /* the width of a tabstop */
	int new_tabstopwidth;        /* the received tabstopwidth */
	int starting_column;         /* the column where the tabstop replacement starts */

	tabstopwidth = TABSTOPWIDTH;
	new_tabstopwidth = 0;
	starting_column = 0;

	if(argc < 2)
	{
		printf("Using the default tab stop width of %d\n\n", TABSTOPWIDTH);
	}

	while(--argc > 0)
	{
		ch = (*++argv)[0];
		switch(ch)
		{
		case '-':
		{
			starting_column = atoi(&(*argv)[1]);
			printf("starting column is now %d\n", starting_column);
		} break;
		case '+':
		{
			tabstopwidth = atoi(&(*argv)[1]);
			printf("tabstop width is now %d\n", tabstopwidth);
		} break;
		default:
		{
			printf("unknown parameter %s\n", *argv);
		} break; 
		}
	}
	

        col_pos_out = col_pos_in = i = 0;
        while((ch = getchar()) != EOF)
        {
		col_pos_in++;
		if(ch == '\t')
		{
			if(col_pos_in > starting_column && new_tabstopwidth)
				tabstopwidth = new_tabstopwidth;
			/* get the width of the tabulator */
			to_tabstop = tabstopwidth - (col_pos_in % tabstopwidth);
			col_pos_in += to_tabstop;
			/* fill with blanks */
			for(i = 0; i <= to_tabstop; i++)
			{
				line[col_pos_out++] = ' '; 
			}
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



/* detab_enhanced_args.c ends here */
