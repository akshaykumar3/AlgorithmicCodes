using namespace std;
#include<iostream>
#include<stdio.h>
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b
int main()
{
    int m,n,i,j,a=0,v;
    scanf("%d%d",&n,&m);
    for(i=n;i<=m;i++){
    	for(j=i+1;j<=m;j++){
    		v = i^j;
    		a = max(a, v);
    		//cout<<v<<endl;
    	}
    }
    printf("%d\n", a);
    return 0;
}
 