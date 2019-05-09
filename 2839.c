#include <stdio.h>

int main(void){
    int result=0;
    int a;
    
    scanf("%d",&a);
    
    while(a!=0){
        if(a%5==0){
            result += a/5;
            a=0;
        }
        if(a%5!=0){
            result++;
            a-=3;
        }
        if(a<0){
            result=-1;
            a=0;
        }
    }
    
    printf("%d",result);
    
    return 0;
}