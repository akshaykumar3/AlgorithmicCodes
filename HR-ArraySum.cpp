using namespace std;
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<ios>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define pa pair<int,int>
#define in 2147483647
int main(){
    int n,i,s=0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &i);
        s+=i;
    }
    printf("%d",s);
    return 0;
}
