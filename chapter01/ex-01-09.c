#include <stdio.h>
#include <stdlib.h>

#include "mh_utils.h"

/*
 * Copy input to output and squash multiple blanks to one
 */

int main()
{
	int ch, blanks = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ')
			blanks++;
		else if (blanks) {
			putchar(' ');
			blanks = 0;
			putchar(ch);
		} else
			putchar(ch);
	}

	return EXIT_SUCCESS;
}
