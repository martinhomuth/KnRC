/* detab.c --- 
 * 
 * Filename: detab.c
 * Description: Replaces all tabulators ('\t') with blanks
 * Author: Martin Homuth
 * Created: Sat Mar 21 10:26:59 2015 (+0100)
 * Version: 0.1
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

#define MAXLINE 1000

#define COLNUM 8
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(int argc, char *argv[])
{
        int i;                      /* counter variable */
        int col_pos_out;            /* position of the output buffer */
        int col_pos_in;             /* position of the input buffer */
	int to_tabstop;             /* the number of blanks until the first tabstop */
        int ch;                     /* store the current character */
        char line[MAXLINE];

        col_pos_out = col_pos_in = i = 0;
        while((ch = getchar()) != EOF)
        {
		col_pos_in++;
		if(ch == '\t')
		{
			/* get the width of the tabulator */
			to_tabstop = COLNUM - (col_pos_in % COLNUM);
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


/* detab.c ends here */
