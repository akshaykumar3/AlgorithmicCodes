/* https://www.hackerrank.com/contests/stryker-codesprint/challenges/minimum-index-difference/submissions/code/7036856 */
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
    int n,i,a[2000],b[2000],j, m = 2001, value = 10001,diff;
    scanf("%d", &n);
    for(i = 0; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n ; i++) {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < n ; i++) {
        for(j = 0 ; j < n; j++) {
            if(a[i] == b[j]) {
                diff = max(i-j, j-i);
                if(diff < m) {
                    m = diff;
                    value = a[i];
                } else if (diff == m) {
                    value = min(a[i], value);
                }
                break;
            }
        }
    }
    printf("%d", value);
    return 0;
}
