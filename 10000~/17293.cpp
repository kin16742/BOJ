#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main(void) {
	int v;
	cin >> v;
	int temp = v;
	do {
		if(temp > 2) printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n\n", temp, temp, temp - 1);
		else if(temp == 2) printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottle of beer on the wall.\n\n", temp, temp, temp - 1);
		else if(temp == 1) printf("%d bottle of beer on the wall, %d bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n\n", temp, temp);
		else if(temp == 0 && v == 1) printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottle of beer on the wall.\n\n", v);
		else if(temp == 0 && v != 1) printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottles of beer on the wall.\n\n", v);
	} while (temp--);
}