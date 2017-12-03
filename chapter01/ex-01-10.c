#include <stdio.h>
#include <stdlib.h>

#include "mh_utils.h"

/*
 * Copy input to output and replace tabs, blanks and newlines with
 * their control visible ansi sequences
 */

int main()
{
	int ch;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			putchar('\\');
			putchar('b');
		} else if (ch == '\t') {
			putchar('\\');
			putchar('t');
		} else if (ch == '\n') {
			putchar('\\');
			putchar('n');
		} else
			putchar(ch);
	}

	return EXIT_SUCCESS;
}
