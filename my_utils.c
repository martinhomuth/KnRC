#include "my_utils.h"

void swap(char *p1, char *p2)
{
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void reverse(char *ptr)
{
	int numel = 0;
	char *tmp = ptr;
	while(*(tmp)++ != '\0')
		numel++;
	tmp = ptr+numel-1;
	while(tmp > ptr)
		swap(tmp--, ptr++);
}
