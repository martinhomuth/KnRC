#include <stdio.h>

/*
 * print Celsius-Fahrenheit table
 * for values between 0 and 300 degrees Celsius
 *  floating point version
 */

int main()
{
	int lower = -100;
	int upper = 100;
	int step = 5;

	float celsius = lower;
	printf("\nCelsius-Fahrenheit table\n\n");
	printf("-------------------------------\n");
	printf("  Celsius |   Fahrenheit\n");
	printf("-------------------------------\n");
	while (celsius < upper) {
		float fahr = (celsius * 1.8) + 32.0;
		printf("%12.0f | %8.1f\n", celsius, fahr);
		celsius += step;
	}
}
