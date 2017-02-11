using namespace std;
#include<iostream>
#include<stdio.h>
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b
int main()
{
    int n,i,a=0;
    scanf("%d",&n);
    while(n--){
       scanf("%d",&i); 
       a=a^i;
    }
    printf("%d\n", a);
    return 0;
}
 