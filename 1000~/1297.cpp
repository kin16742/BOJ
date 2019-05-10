#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    double cross, h, w, temp;
    cin >> cross >> h >> w;
    temp = cross / sqrt(h * h + w * w);
    cout << (int)(h*temp) << ' ' << (int)(w*temp) << endl; 
    return 0;
}