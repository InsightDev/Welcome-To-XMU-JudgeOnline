#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
using namespace std;

struct node{
    unsigned num;
    int len;
}q[50000];

unsigned o[16],z[16],e[4]={0,1,2,3};
set<unsigned> st;
int t[16],f=0,b=0;

unsigned getv(char ch){
    if(ch=='.') return 0;
    else if(ch=='B') return 3;
    else if(ch=='G') return 2;
    else return 1;
}

bool ok(unsigned u, unsigned v){
    if(u==1&&v==3||u==3&&v==1||u==3&&v==3)
        return false;
    return true;
}

bool check(unsigned num, int k){
    int i=k/4;
    int j=k%4;
    unsigned org=(num>>t[k])&e[3];
    if(i>=1&&!ok(org,(num>>t[k-4])&e[3]))
        return false;
    if(j<=2&&!ok(org,(num>>t[k+1])&e[3]))
        return false;
    if(i<=2&&!ok(org,(num>>t[k+4])&e[3]))
        return false;
    if(j>=1&&!ok(org,(num>>t[k-1])&e[3]))
        return false;
    return true;
}

bool procc(unsigned num, int sk, int tk, int len){
    unsigned cur=(num&z[sk])|(((num&o[sk])>>t[sk])<<t[tk]);
    if(!check(cur,tk)||st.find(cur)!=st.end())
        return false;
    if((cur&e[3])==1)
        return true;
    st.insert(cur);
    q[b].num=cur;
    q[b++].len=len+1;
    return false;
}

int search(unsigned num){
    if((num&e[3])==1)
        return 0;
    st.insert(num);
    q[b].num=num;
    q[b++].len=0;
    int i,j,k,len;
    
    while(f!=b){
        num=q[f].num;
        len=q[f++].len;
        for(k=0; k<16; k++){
            if(!(num&o[k]))
                continue;
            i=k/4;
            j=k%4;
            if(i>=2&&(num&o[k-4])&&!(num&o[k-8])&&procc(num,k,k-8,len))
                return len+1;
            if(i>=3&&(num&o[k-4])&&(num&o[k-8])&&!(num&o[k-12])&&procc(num,k,k-12,len))
                return len+1;
            if(j<=1&&(num&o[k+1])&&!(num&o[k+2])&&procc(num,k,k+2,len))
                return len+1;
            if(j<=0&&(num&o[k+1])&&(num&o[k+2])&&!(num&o[k+3])&&procc(num,k,k+3,len))
                return len+1;
            if(i<=1&&(num&o[k+4])&&!(num&o[k+8])&&procc(num,k,k+8,len))
                return len+1;
            if(i<=0&&(num&o[k+4])&&(num&o[k+8])&&!(num&o[k+12])&&procc(num,k,k+12,len))
                return len+1;
            if(j>=2&&(num&o[k-1])&&!(num&o[k-2])&&procc(num,k,k-2,len))
                return len+1;
            if(j>=3&&(num&o[k-1])&&(num&o[k-2])&&!(num&o[k-3])&&procc(num,k,k-3,len))
                return len+1;
        }
    }
}

int main() {
    char ch;
    unsigned num=0;

    for(int i=0; i<16; i++){
        t[i]=i*2;
        o[i]=e[3]<<t[i];
        z[i]=~o[i];
        scanf(" %c", &ch);
        num|=getv(ch)<<t[i];
    }
    printf("%d\n", search(num));

    return 0;
}
