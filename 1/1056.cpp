#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

double d[46][1141][46];
int v[46];

double search(int i, int m, int k){
    if(i==45){
        if(m>=3) return v[45];
        if(m>=1) return v[45]/2.0;
        return 0;
    }
    if(d[i][m][k]!=-1)
        return d[i][m][k];

    double ans=0;
    ans=max(ans,search(i+1,m,0));
    if(m>=3) ans=max(ans,search(i+1,m-3,0)+v[i]);
    if(m>=1) ans=max(ans,search(i+1,m-1,0)+v[i]/2.0);
    if(k!=0)
        ans=max(ans,search(i+1,m+k,k+1));
    else if(i+3<=45)
        ans=max(ans,search(i+3,m+3,3));

    d[i][m][k]=ans;
    return ans;
}

int main(int argc, char** argv) {
    int m,i,j,k;
    double ans;

    scanf("%d", &m);
    for(i=1; i<=45; i++)
        scanf("%d", &v[i]);
    
    for(i=0; i<=45; i++)
    for(j=0; j<=m+990; j++)
    for(k=0; k<=45; k++)
        d[i][j][k]=-1;
    
    ans=search(1,m,0);
    printf("%d\n", (int)(ans+0.5));

    return 0;
}
