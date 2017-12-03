#include <stdio.h>

/*
 * Verification that "getchar() != EOF" is 0 or 1
 */

int main()
{
	int ch;
	while (1) {
		ch = getchar();
		if ((ch != EOF) == 1)
			putchar(ch);
		else if ((ch != EOF) == 0) {
			printf("exiting as \"ch\" == EOF\n");
			break;
		} else
			printf("\"getchar() != EOF\" is different from 0 and 1\n");
	}
}
