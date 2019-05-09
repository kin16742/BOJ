#include <stdio.h>

int main(void){
    int a;
    int result=0;
    scanf("%d",&a);
    for(a;a>0;a--){
        result += a;
    }
    printf("%d",result);
    return 0;
}