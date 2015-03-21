/* entab_enhanced.c --- 
 * 
 * Filename: entab_enhanced.c
 * Description: Modify the program entab to accept a list of tab stops as arguments.
 *              Use the default tab settings if there are no arguments.
 * Author: Martin Homuth
 * Created: Sat Mar 21 10:26:51 2015 (+0100)
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
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXARGS 32

#define TABSTOPWIDTH 8
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(int argc, char *argv[])
{
        int i;                        /* counter variable */
        int col_pos_out;              /* position of the output buffer */
        int col_pos_in;               /* position of the input buffer */
        int tabs;                     /* number of tabs to be written */
        int blanks;                   /* number of blanks to be written */
	int pos_l;                    /* remember the leftmost position of the blank space */
	int to_tabstop;               /* the number of blanks until the first tabstop */
        int ch;
        char line[MAXLINE];
	int tabstopwidth;             /* the width of a tabstop */
	int tabstops[MAXARGS] = {0};  /* hold the arguments from the command line */
	int current_tabstop;          /* iterator for the tabstops */

        col_pos_out = col_pos_in = i = tabs = 0;
        blanks = 0;
	current_tabstop = 0;
	if(argc < 2)
	{
		printf("Using default tabstop length of %d\n\n", TABSTOPWIDTH);
	}
	while(--argc > 0)
	{
		tabstops[argc] = atoi((*++argv));
	}
	
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
			if(tabstops[current_tabstop] > 0)
			{
				tabstopwidth = tabstops[current_tabstop++];
			}
			else
			{
				tabstopwidth = TABSTOPWIDTH;
			}
			/* blanks until tabstop */
			to_tabstop = tabstopwidth - (pos_l % tabstopwidth);
			/* only insert the first tab
			 * if there are enough blanks */
			if(to_tabstop < blanks)
			{
				blanks -= to_tabstop + 1;
				tabs++;
			}
			/* determine the full tabs */
			while(blanks > tabstopwidth)
			{
				tabs++;
				blanks -= tabstopwidth;
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


/* entab_enhanced.c ends here */
