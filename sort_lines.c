/* sort_lines.c --- 
 * 
 * Filename: sort_lines.c
 * Description: Sort the lines received by stdin lexicographically using strcmp
 * Author: Martin Homuth
 * Created: Wed Mar 25 20:53:38 2015 (+0100)
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

#define MAXLINES 5000        /* maximum number of lines to be sorted */
char *lineptr[MAXLINES];     /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
int writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,void qsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *));
	   int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort the input lines */
int main()
{
	int nlines;               /* number of input lines read */
	int numeric = 0;          /* 1 if numeric sort */

	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort((void **) lineptr, 0, nlines-1,
		      (int (*)(void*, void*)) (numeric ? numcmp : strcmp ));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
	
}

void qsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int readlines(char *lineptr[], int nlines)
{
	
}
/* sort_lines.c ends here */
