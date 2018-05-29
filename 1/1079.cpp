#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(int argc, char** argv) {
    int n,i;
    double ans=0;

    scanf("%d", &n);
    for(i=1; i<=n; i++)
        ans+=(double)n/i;
    printf("%f\n", ans);

    return 0;
}
