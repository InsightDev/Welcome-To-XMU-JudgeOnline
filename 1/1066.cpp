#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int F,A,V,H;
int a,b,c;
int ans=15;

void search(int L, int C, int sa, int sb, int k){
    if(k==15||k>=ans||(15-k)*(H-F/2)<L&&(15-k)*(2*A-F/2)<L)
        return;
    
    int AA=A;
    int FF=F;
    if(sa-->0) FF/=2;
    if(sb-->0) AA*=2;
    C+=V;

    if(AA>FF){
        if(AA-FF>=L){
            ans=k;
            return;
        }
        search(L-(AA-FF),C,sa,sb,k+1);
    }else{
        search(L,C,sa,sb,k+1);
    }

    if(H>FF&&C>=c){
        if(H-FF>=L){
            ans=k;
            return;
        }
        search(L-(H-FF),C-c,sa,sb,k+1);
    }

    if(sa<=0&&C>=a) search(L,C-a,3,sb,k+1);
    if(sb<=0&&C>=b) search(L,C-b,sa,3,k+1);
}

int main(int argc, char** argv) {
    int L,C;

    scanf("%d %d %d %d %d", &L, &F, &A, &C, &V);
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &H);

    search(L,C,0,0,1);
    printf("%d\n", ans==15?-1:ans);

    return 0;
}
