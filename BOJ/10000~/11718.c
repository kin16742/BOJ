#include <stdio.h>

int main(void) {
	char a;
	a = getchar();

	while (a != -1) {
		putchar(a);
		a = getchar();
	}

	return 0;
}