#include <stdio.h>

/* print input one word per line */

int main()
{
	int c, blanks = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t' || c == ' ') {
			blanks++;
		} else if (blanks) {
			putchar('\n');
			putchar(c);
			blanks = 0;
		} else {
			putchar(c);
		}
	}
}
