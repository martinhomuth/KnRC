/* lines.h --- 
 * 
 * Filename: lines.h
 * Description: Reading and writing lines from stdin/stdout
 * Author: Martin Homuth
 * Created: Thu Apr  9 12:11:23 2015 (+0200)
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

#define MAXLINES 5000        /* maximum number of lines to be sorted */
#define MAXLINE 100

char *lineptr[MAXLINES];     /* pointers to text lines */

int read_lines(char *lineptr[], int nlines);
void write_lines(char *lineptr[], int nlines);


/* lines.h ends here */
