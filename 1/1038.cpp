#include <iostream>
#include <cstdlib>
#include <cstdio>
#define inf 1000000000
using namespace std;

int a[21][2001];
int b[2001];
int n,m,des;
int ans,diff;

void search(){
    int i=1,j=1,sum=0;
    while(i<=m){
        sum+=b[i];
        if(sum<des){
            if(des-sum<=diff){
                diff=des-sum;
                ans=sum;
            }
        }else{
            while(j<=i&&sum>=des){
                if(sum-des<diff){
                    diff=sum-des;
                    ans=sum;
                }
                sum-=b[j++];
            }
            if(j<=i&&des-sum<=diff){
                diff=des-sum;
                ans=sum;
            }
        }
        i++;
    }
}

void vmaxsum(){
    int i,j,k;
    diff=inf;
    for(i=1; i<=n; i++){
        for(k=1; k<=m; k++)
            b[k]=0;
        for(j=i; j<=n; j++){
            for(k=1; k<=m; k++)
                b[k]+=a[j][k];
            search();
        }
    }
}

int main(int argc, char** argv) {
    int i,j,cas=1;

    while(scanf("%d%d%d",&n,&m,&des)!=EOF){
        if(n==0&&m==0)
            break;
        for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            scanf("%d", &a[i][j]);
        vmaxsum();
        printf("Case %d:\n", cas++);
        printf("%d\n", ans);
    }
    
    return 0;
}
