/* lines.c --- 
 * 
 * Filename: lines.c
 * Description: Reading and writing lines from stdin/stdout.
 * Author: Martin Homuth
 * Created: Thu Apr  9 12:12:38 2015 (+0200)
 */

/* Change Log:
 * 
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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lines.h"
#include "alloc.h"

int get_line(char *line, int len)
{
	int ch;
	int i = 0;

	while(--len > 0 && (ch = getchar()) != EOF && ch != '\n')
		line[i++] = ch;
	if(ch == '\n')
		line[i++] = ch;
	line[i] = '\0';
	return i;
}

void write_lines(char *lineptr[], int nlines)
{
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}

int read_lines(char *lineptr[], int maxlines)
{
	int nlines, len;
	char *p, line[MAXLINE];

	nlines = 0;
	while((len = get_line(line, maxlines)) > 0)
	{
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* lines.c ends here */
