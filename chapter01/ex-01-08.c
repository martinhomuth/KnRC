#include <stdio.h>
#include <stdlib.h>

#include "mh_utils.h"

/*
 * Count blanks, tabs and newlines of given input
 */

int main()
{
	int ch, nn, nt, nb;
	nn = nt = nb = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			nn++;
		if (ch == ' ')
			nb++;
		if (ch == '\t')
			nt++;
	}

	log("\n\nnewlines:\t%d\nblanks:\t\t%d\ntabs:\t\t%d\n\n", nn, nb, nt);
	return EXIT_SUCCESS;
}
