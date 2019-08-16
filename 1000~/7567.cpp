#include <iostream>
#include <string.h>
using namespace std;
char c[60];
int result = 10;
int main() {
    cin >> c;
    for(int i=1;i<strlen(c);i++){
        if(c[i] == c[i-1]) result+=5;
        else result+=10;
    }
    cout << result << endl;
}