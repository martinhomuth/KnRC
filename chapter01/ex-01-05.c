#include <stdio.h>

/*
 * print Celsius-Fahrenheit table
 * for values between 0 and 300 degrees Celsius
 *  floating point version
 */

int main()
{
	float celsius;
	printf("\nCelsius-Fahrenheit table\n\n");
	printf("-------------------------------\n");
	printf("  Celsius |   Fahrenheit\n");
	printf("-------------------------------\n");
	for (celsius = 100; celsius > -100; celsius -= 10) {
		float fahr = (celsius * 1.8) + 32.0;
		printf("%12.0f | %8.1f\n", celsius, fahr);
	}
}
