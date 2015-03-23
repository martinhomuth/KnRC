/* tail.c --- 
 * 
 * Filename: tail.c
 * Description: Write the program tail, which prints the last n lines of its
 *              input. By default, n is 10, let us say, but it can be changed
 *              by an optional argument, so that "tail -n" prints out the last
 *              n lines. The program should behave rationally no matyter how
 *              unreasonable the input or the value of n. Write the program so
 *              it makes the best use of available storage; lines should be stored
 *              as in the sorting program of section 5.6, not in a two-dimensional
 *              array of fixed size.
 * Author: Martin Homuth
 * Created: Sun Mar 22 15:49:00 2015 (+0100)
 */

/* Commentary: 
 * Section 5.6 sorting program:
 * readlines(char *lineptr[], int maxlines)
 * {
 *   char *p, line[MAXLINE];
 *   nlines = 0;
 *
 *   while((len = getline(line, MAXLEN)) > 0)
 *   {
 *     if(nlines >= maxlines || (p = alloc(len)) == NULL)
 *     {
 *       return -1;
 *     }
 *     else
 *     {
 *       line[len-1] = '\0';
 *       strcpy(p, line);
 *       lineptr[nlines++] = p;
 *     }
 *   }
 *   return nlines;
 * }
 * 
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
#include <string.h>

#define MAXLINE 100
#define DEFAULT 10

int main(int argc, char **argv)
{
	int ch;                   /* holds the characters obtained from the input */
	int n;                    /* the number of lines displayed from the input */

	n = DEFAULT;
	while(--argc > 0 && (*++argv)[0] == '-')
	{
		--argc;
		if(argc)
		{
			ch = (*(argv))[1];
			switch(ch)
			{
			case 'n':
			{
				n = atoi(*(argv+1));
			} break;
			default:
			{
				printf("unknown parameter -%c\n", ch);
			} break;
			}
		}
		else
		{
			printf("Usage: ./tail [-n NUM_LINES]\n");
			return(EXIT_FAILURE);
		}
	}
	printf("will show the last %d lines\n", n);

	while(getlines() != 0)
	{


	}
}

/* tail.c ends here */
