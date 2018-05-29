#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int cas,n;
    
    scanf("%d", &cas);
    while(cas--){
        scanf("%d", &n);
        if(n & (n - 1))
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
