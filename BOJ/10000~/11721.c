#include <stdio.h>
#include <string.h>
int main(void) {
	char arr[100];
    int a;
	scanf("%s",arr);
    a=strlen(arr);
	for (int i = 0; i < a; i++) {
		printf("%c", arr[i]);
		if ((i+1) % 10 == 0)
			printf("\n");
	}
    return 0;
}