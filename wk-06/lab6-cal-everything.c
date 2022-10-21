/* 
 * Author: Niall Ryan
 * Description: Accepts two non-zero doubleeger numbers
 * 		a & b, the program then returns the
 * 		result of sum, difference, product,
 * 		devision, power and natural log.
 *
 * Input: Two non-zero doubleeger numbers
 * Output: All calculations acted upon inputted numbers
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
double power(double a, double b);
double dev(double a, double b);
double prod(double a, double b);
double diff(double a, double b);
double sum(double a, double b);
double n_log(double a, double b);

// Main Function
int main(int argc, char **argv)
{
	// Initialize input data
	double a = atof(argv[1]);
	double b = atof(argv[2]);

	// Initialize function array pointer
	double (*cal_array[])(double, double) = {sum, diff, prod,
					       	 dev, power, n_log};

	// Iterate over function array pointer
	for (int i = 0; i <= 5; ++i)
	{
		printf("%.2f\n", (*cal_array[i])(a, b));
	}
	
	// Return 0 for succesful execution
	return 0;
}

// Sum function returns a + b
double sum(double a, double b)
{
	return a + b;
}

// Diff function return a - b
double diff(double a, double b)
{
	return a - b;
}

// Prod function return a * b
double prod(double a, double b)
{
	return a * b;
}

// Dev function returns a / b
double dev(double a, double b)
{
	return a / b;
}

// Power function returns a ^ b
double power(double a, double b)
{
	return pow(a, b);
}

// N_log function returns log(a) + log(b)
double n_log(double a, double b)
{
	return log(a) + log(b);	
}
