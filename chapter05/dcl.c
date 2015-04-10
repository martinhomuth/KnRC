/* dcl.c --- 
 * 
 * Filename: dcl.c
 * Description: Parses a declarator
 * Author: Martin Homuth
 * Created: Fri Apr 10 19:06:44 2015 (+0200)
 */

/* Change Log:
 *
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
#include "dcl.h"



void dcl(void)
{
	int ns;

	for(ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out, " pointer to");
}

void dirdcl(void)
{
	int type;

	if(tokentype == '(')   /* ( dcl ) */
	{
		dcl();
		if(tokentype != ')')
		{
			printf("error: missing )\n");
		}
	}
	else if(tokentype == NAME)    /* variable name */
	{
		strcpy(name, token);
	}
	else
		printf("error: expected name or (dcl)\n");
	while((type = gettoken()) == PARENS || type == BRACKETS)
	{
		if(type == PARENS)
		{
			strcat(out, " function returning");
		}
		else
		{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}

int main(void)
{
	while(gettoken() != EOF)                   /* first token on line */
	{
		strcpy(datatype, token);           /* is the datatype */
		out[0] = '\0';
		dcl();                             /* parse rest of the line */
		if(tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);

	char *p = token;

	while((c = getch()) == ' ' || c == '\t')
		;
	if(c == '(')
	{
		if((c = getch()) == ')')
		{
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else
		{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if(c == '[')
	{
		for(*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if(isalpha(c))
	{
		for(*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
/* dcl.c ends here */
