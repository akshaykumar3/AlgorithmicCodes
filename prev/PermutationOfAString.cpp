using namespace std;
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ios>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define pa pair<long long,long long>
#define in 2000000000
#define pb(a) push_back(a)
#define ln 9000000000000000000
/*int gcd(int i,int j)
{
	return (j==0?i:gcd(j,i%j));
}*/
int a[5];
void print() {
    int i;
    for(i=0;i<5;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int i,int j) {
    int t = a[i];
    a[i]=a[j];
    a[j]=t;
}
void fn(int l,int h) {
    if(l==h) print();
    else {
        int i;
        for(i=l;i<=h;i++) {
            swap(l,i);
            fn(l+1,h);
            swap(l,i);
        }
    }
}
int main()
{
    a[0]=1,a[1]=2,a[2]=3,a[3]=4,a[4]=5;
    fn(0,4);
	return 0;
}
