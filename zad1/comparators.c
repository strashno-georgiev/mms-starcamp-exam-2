#include "comparators.h"
#include <math.h>

int digit_sum(double num) {
	int n = num, sum=0;
	while(n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int doubleEq(double a, double b){
    return fabs(a - b) < 1.0e-10 * fmax(fabs(a), fabs(b));
}

double randreal(int min, int max) {
	return ((double)rand() / (double)RAND_MAX) * (max-min) + min;
} 


int comparator_ascending(const void* el1, const void* el2) {
	double a = *((double*)el1), b = *((double*)el2);
	return doubleEq(a, b) ? 0 : (a - b > 0 ? 1 : -1);
}
int comparator_descending(const void* el1, const void* el2) {
	double a = *((double*)el1), b = *((double*)el2);
	return doubleEq(a, b) ? 0 : (b-a > 0 ? 1 : -1);
}
int comparator_digit_sum(const void* el1, const void* el2) {
	return digit_sum(*(double*)el1) - digit_sum(*(double*)el2);
}

int comparator_absolute_asc(const void* el1, const void* el2) {
	double a = *((double*)el1), b = *((double*)el2);
	return doubleEq(a, b) ? 0 : (fabs(a) - fabs(b) > 0 ? 1 : -1);
}

