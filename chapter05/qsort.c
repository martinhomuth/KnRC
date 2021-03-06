/* qsort.c --- 
 * 
 * Filename: qsort.c
 * Description: Implementation of the quicksort algorithm. 
 * Author: Martin Homuth
 * Created: Thu Apr  9 12:15:00 2015 (+0200)
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
#include <ctype.h>
#include "qsort.h"

#define MAXLINE 100

void q_sort(void *v[], int left, int right,
	    int (*comp)(void *, void *),
	    int order, int fold, int dict)
{
	int i, last;
	unsigned int j;
	char l[MAXLINE], r[MAXLINE];
	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
	{
		if(dict)
		{
			an_strcpy(l, v[i]);
			an_strcpy(r, v[left]);
		}
		else
		{
			strcpy(l,v[i]);
			strcpy(r,v[left]);
		}
		if(fold)
		{
			for(j = 0; j < strlen(l); j++)
			{
				l[j] = tolower(l[j]);
			}
			for(j = 0; j < strlen(r); j++)
			{
				r[j] = tolower(r[j]);
			}
		}
		if(!order && (*comp)(l, r) < 0)
			swap(v, ++last, i);
		if(order && (*comp)(l, r) >= 0)
			swap(v, ++last, i);
	}
	
	swap(v, left, last);
	q_sort(v, left, last-1, comp, order, fold, dict);
	q_sort(v, last+1, right, comp, order, fold, dict);
}

void swap(void *v[], int i, int j)
{
	void *tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void an_strcpy(char *s1, char *s2)
{
	while(*s2 != '\0')
	{
		if(isalnum(*s2) || isspace(*s2))
			*s1++ = *s2++;
		else
		{
			s2++;
		}
	}
	*s1 = '\0';
}


/* qsort.c ends here */
