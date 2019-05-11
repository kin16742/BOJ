#include <iostream>
#include <string.h>
using namespace std;
char c[101];
int a[26];
int main(){
    cin >> c;
    for(int i=0;i<strlen(c);i++){
        a[c[i] - 'a']++;
    }
    for(int i=0;i<26;i++){
        cout << a[i] << ' ';
    }
    return 0;
}