#include <stdio.h>

/*
 * print Fahrenheit-Celsius table
 * for values between 0 and 300 degrees Fahrenheit
 *  floating point version
 */

int main()
{
	int lower = 0;
	int upper = 300;
	int step = 20;

	float fahr = lower;
	printf("\nFahrenheit-Celsius table\n\n");
	printf("-------------------------------\n");
	printf("  Fahrenheit |   Celsius\n");
	printf("-------------------------------\n");
	while (fahr < upper) {
		float celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%12.0f | %8.1f\n", fahr, celsius);
		fahr += step;
	}
}
