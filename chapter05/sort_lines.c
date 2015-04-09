/* main.c --- 
 * 
 * Filename: main.c
 * Description: 
 * Author: Martin Homuth
 * Maintainer: 
 * Created: Thu Apr  9 12:17:01 2015 (+0200)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
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
#include <stdio.h>
#include <string.h>
#include "lines.h"
#include "qsort.h"
#include "numcmp.h"

/* sort the input lines */
int main(int argc, char *argv[])
{
	int nlines;               /* number of input lines read */
	int numeric = 0;          /* 1 if numeric sort */

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if((nlines = read_lines(lineptr, MAXLINES)) >= 0)
	{
		q_sort((void **) lineptr, 0, nlines-1,
		       (int (*)(void*,void*))(numeric ? numcmp : strcmp));

		write_lines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
	
}


/* main.c ends here */
