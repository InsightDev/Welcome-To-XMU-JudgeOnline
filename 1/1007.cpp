#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

string multiply(string a, string b){
    if(a=="0"||b=="0")
        return "0";
    int i,j,k,t;
    int n,m,x,y,r=0;
    string ans="";
    n=a.size();
    m=b.size();
    int* s=new int[n+m-1];
    memset(s,0,sizeof(s));
    t=n+m-2;
    for(j=m-1; j>=0; j--){
        k=t--;
        y=b[j]-'0';
        for(i=n-1; i>=0; i--){
            x=a[i]-'0';
            s[k--]+=x*y;
        }
    }
    k=n+m-2;
    while(k>=0||r!=0){
        x=(k>=0?s[k--]:0);
        ans.insert(ans.begin(), (x+r)%10+'0');
        r=(x+r)/10;
    }
    delete s;
    return ans;
}

int main(int argc, char** argv) {
    char a[1005];
    char b[1005];
    string ans;

    scanf("%s %s", a, b);
    ans = multiply(a, b);
    printf("%s\n", ans.c_str());

    return 0;
}
