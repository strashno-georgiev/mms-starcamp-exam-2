#if defined MIN && defined MAX && defined COUNT

#include <stdio.h>
#include "comparators.h"

void print_array(const double* arr, size_t n) {
	printf("{");
	if(n > 0) {
		printf("%lf", arr[0]);
	}
	for(int i=1; i < n; i++) {
		printf(", %lf", arr[i]);
	}
	printf("}\n");	
}

int main() {
	double arr[COUNT];
	int (*comparators[4])(const void*, const void*) = {comparator_ascending, comparator_descending, comparator_digit_sum, comparator_absolute_asc};
	int op;
	srand((unsigned)time(NULL));
	for(int i=0 ; i < COUNT; i++) {
		arr[i] = randreal(MIN, MAX);		
	}
	print_array(arr, COUNT);

	while(1) {
		printf("Enter operation(1-4):");
		scanf("%d", &op);
		getchar();
		while(op < 1 || op > 4) {
			fprintf(stderr, "Invalid operation\n");
			printf("Enter operation(1-4):");
			scanf("%d", &op);
			getchar();
		}
		
		qsort(arr, COUNT, sizeof(double), comparators[op-1]);
		print_array(arr, COUNT);
	}
	return 0;
}

#endif

