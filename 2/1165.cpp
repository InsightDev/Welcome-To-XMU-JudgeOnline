#include <cstdlib>
#include <iostream>
using namespace std;

int a[100001];
int c[100001];
int all=0;

int lowbit(int t){
    return t&(t^(t-1));
}

int sum(int end){
    int ans=0;
    while(end>0){
        ans += c[end];
        end -= lowbit(end);
    }
    return ans;
}

void add(int pos, int num){
    while(pos<=100000){
        c[pos] += num;
        pos += lowbit(pos);
    }
}

int search(int k){
    int l=1;
    int r=100000;
    int ans;
    while(l<=r){
        int m=(l+r)/2;
        int s=sum(m);
        if(s>k){
            r=m-1;
        }else if(s==k){
            ans=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int n, i, o;
    
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &o, &i);
        if(o==1){
            if(a[i]==0){
               all++;
               add(i,1);
               a[i]=1;
            }
        }else if(o==2){
            if(a[i]==1){
               all--;
               add(i,-1);
               a[i]=0;
            }
        }else{
            if(i>=1&&i<=all)
                printf("%d\n", search(i));
            else
                printf("-1\n");
        }
    }
    
    return EXIT_SUCCESS;
}
