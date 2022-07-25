#pragma once
#include <stdlib.h>
#include <time.h>
double randreal(int min, int max);
int comparator_ascending(const void* el1, const void* el2);
int comparator_descending(const void* el1, const void* el2);
int comparator_digit_sum(const void* el1, const void* el2);
int comparator_absolute_asc(const void* el1, const void* el2);
int doubleEq(double a, double b);
