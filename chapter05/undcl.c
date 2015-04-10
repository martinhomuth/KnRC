/* undcl.c --- 
 * 
 * Filename: undcl.c
 * Description: Create declaration from description
 * Author: Martin Homuth
 * Created: Fri Apr 10 19:33:02 2015 (+0200)
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
#include "dcl.h"

int main(void)
{
	int type;
	char temp[MAXTOKEN];

	while(gettoken() != EOF)
	{
		strcpy(out, token);
		while((type = gettoken()) != '\n')
		{
			if(type == PARENS || type == BRACKETS)
			{
				strcat(out, token);
			}
			else if(type == '*')
			{
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			}
			else if(type == NAME)
			{
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}
			else
				printf("invalid input at %s\n", token);
		}
		printf("%s\n", out);
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

/* undcl.c ends here */
