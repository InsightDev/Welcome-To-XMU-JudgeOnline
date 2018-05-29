#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point{
    int x;
    int y;
}p[100];

bool comp(Point p0, Point p1){
    return p0.x<p1.x;
}

int main(int argc, char** argv) {
    int n,m,length,width;
    int i,j,k,s,cas,ans;
    int y[100];

    scanf("%d", &cas);
    while(cas--){
        scanf("%d %d %d", &n, &length, &width);
        for(i=0; i<n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        sort(p,p+n,comp);
        ans=0;
        for(i=0; i<n; i++){
            for(j=i; j<n; j++){
                if(p[j].x-p[i].x>length)
                    break;
                m=j-i+1;
                for(k=0; k<m; k++)
                    y[k]=p[i+k].y;
                sort(y,y+m);
                for(s=0; s<m; s++){
                    for(k=s; k<m; k++)
                        if(y[k]-y[s]>width)
                            break;
                    ans=max(ans,k-s);
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
