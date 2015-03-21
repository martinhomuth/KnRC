/* detab_enhanced.c --- 
 * 
 * Filename: detab_enhanced.c
 * Description: Modify the program detab to accept a list of tab stops
 *              as arguments. Use the default tab setting if there are
 *              no arguments
 * Author: Martin Homuth
 * Created: Sat Mar 21 10:27:08 2015 (+0100)
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
	int current_tabstop;         /* the current tabstop (duh) */
	int tabstops[MAXARGS] = {0}; /* storage of the arguments */
	int tabstopwidth;

	if(argc < 2)
	{
		printf("Using the default tab stop width of %d\n\n", TABSTOPWIDTH);
	}

	current_tabstop = 0;
	while(--argc > 0)
	{
		tabstops[current_tabstop++] = atoi(*++argv);
	}
	current_tabstop = 0;
        col_pos_out = col_pos_in = i = 0;
        while((ch = getchar()) != EOF)
        {
		col_pos_in++;
		if(ch == '\t')
		{
			/* get the width of the tabulator */
			/* WARNING: This does not work as the terminal has tab stops
			 *          in it and I really don't understand what the
			 *          "list of tab stops" really should be... */
			if(tabstops[current_tabstop] > 0)
				tabstopwidth = tabstops[current_tabstop++];
			else
				tabstopwidth = TABSTOPWIDTH;
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


/* detab_enhanced.c ends here */
