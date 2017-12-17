#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mh_utils.h"

#define HEIGHT 30
#define WIDTH 80
#define UPPER_LENGTH_BOUND 255
#define BITS_PER_WORD 8

enum alignment { HORIZONTAL, VERTICAL };

/*
 * display a histogram of word lengths
 *
 * by default this uses horizontal bars, this can be switched to
 * vertical bars using an command line argument
 */

void print_horizontal(void *bitarray)
{
}

int bitarray_get_max_length(void *bitarray)
{
	int max = 0;
	for (int i = 0; i < UPPER_LENGTH_BOUND; i++)
		if (((int *)bitarray)[i])
			max = i;
	return max;
}

int bitarray_get_max_height(void *bitarray)
{
	int max = 0;
	for (int i = 0; i < UPPER_LENGTH_BOUND; i++)
		if (((int *)bitarray)[i] > max)
			max = ((int *)bitarray)[i];
	return max;
}


#define COORD_OFFSET 3
void print_vertical(void *bitarray)
{
	int width = bitarray_get_max_length(bitarray);
	int height = bitarray_get_max_height(bitarray);
	int bar_width = WIDTH / width - 1;
	int bar_unit = HEIGHT / height - 1;

	printf("width: %d\nheight: %d\nbar_width: %d\nbar_unit: %d\n",
	       width, height, bar_width, bar_unit);
	printf("\nvertical:\n\n");

	for (int y = HEIGHT; y >= -COORD_OFFSET + 1; y--) {
		for (int x = -COORD_OFFSET; x < WIDTH; x++) {

			if (y >= 0 && x >= 0) {
				(((int *)bitarray)[x / bar_width]) > (y / bar_unit) ?
					printf("x") :
					printf(" ");
			} else if (x == -1)
				printf("|");
			else if (x == -2) {
				if (y % bar_unit == 0 && y > 0)
					printf("%2d", y / bar_unit);
				else
					printf("  ");
			} else if (x >= 0) {
				/* TODO: improve to only print one
				   column number per bar */
				int bar_offset = bar_width / 2 + 1;
				if (y == -1)
					printf("-");
				else if (y == -2 && (x + bar_offset) % bar_offset == 0)
					printf("%d", x / bar_width);
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}

void bitarray_increase(void *bitarray, int num)
{
	((int *)bitarray)[num]++;
}

/*
 * Masks the appropriate entry, shifts it to 0 and prints its value
 *
 * bits = (2 ^ 5) - 1
 */
void bitarray_print(void *bitarray)
{
	int val;
	for (int i = 0; i < UPPER_LENGTH_BOUND; i++) {
		val = ((int *)bitarray)[i];
		printf("%d ", val);
	}
	printf("\n");
}

void get_word_lengths(void *bitarray)
{
	int c, current_length = 0, blanks = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			bitarray_increase(bitarray, current_length);
			current_length = 0;
		} else if (c == '\t' || c == ' ' || c == '\b') {
			if (!blanks)
				bitarray_increase(bitarray, current_length);
			else
				blanks++;
			current_length = 0;
		} else {
			if (blanks)
				blanks = 0;
			current_length++;
		}
	}
}

int main(int argc, char *argv[])
{
	int direction;
	if (argc > 1)
		direction = HORIZONTAL;

	/*
	 * use a bit array with at least 4 bits per word length
	 *
	 * the number of bits per length is adjustable
	 */
	log_debug("Allocating %lu byte\n", UPPER_LENGTH_BOUND * BITS_PER_WORD / sizeof(char) + 1);
	int byte_to_allocate = UPPER_LENGTH_BOUND * BITS_PER_WORD / sizeof(char) + 1;
	void *bitarray = malloc(byte_to_allocate);
	memset(bitarray, 0, byte_to_allocate);

	//bitarray_increase(bitarray, 12);
	//bitarray_print(bitarray);

	//printf("max: %d\n", bitarray_get_max(bitarray));

	get_word_lengths(bitarray);

	//bitarray_print(bitarray);

	print_vertical(bitarray);

	free(bitarray);
	return 0;
}
