#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int a[50001];
int n;

int search(int k){
    unsigned num;
    int i,j,z;
    for(i=1; i<=n; i++)
        if(a[i]>k/2.0)
            break;
    z=i-1;
    j=z;
    num=(unsigned)z*(z-1)/2;
    for(i=z+1; i<=n; i++){
       while(j>=1&&a[i]+a[j]>k)
           j--;
       num+=j;
    }
    return (int)num;
}

int main(int argc, char *argv[])
{
    unsigned low,mid,high;
    int m,i,tmp,ans;
    
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    
    low=a[1]+a[2];
    high=a[n-1]+a[n];
    ans=high;
    while(low<=high){
        mid=(low+high)/2;
        tmp=search(mid);
        if(tmp>=m){
            ans=min(ans,(int)mid);
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    printf("%d\n", ans+1);
    
    return EXIT_SUCCESS;
}
