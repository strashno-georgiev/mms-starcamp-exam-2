#include <string.h>
#include <stdio.h>
int main(int argc, char* argv[]) {

	unsigned char num[501];
	unsigned char symtable[10] = {'!', '#', '/', '~', '=', '\'', '\\', '>', '.', ','};
	if(argc > 1) {
		strncpy(num, argv[1], 500);
	}
	for(int i=0; i < 500; i++ ) {
		if(i % 2 == 0) {
			num[i] = 'A' + num[i] - '0';
		}
		else {
			num[i] = symtable[num[i] - '0'];
		}
	}
	printf("%s\n", num);
}
