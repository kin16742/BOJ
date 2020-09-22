#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char c[60];
    cin >> c;
    for(int i=0;i<strlen(c);i++) cout << c[i];
    cout << "??!\n";
}