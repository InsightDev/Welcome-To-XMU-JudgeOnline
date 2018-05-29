#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

string s[1001];
char c[2569];
int a[2568];

string add(string a, string b){
    int i=a.size()-1;
    int j=b.size()-1;
    int k=max(i,j);
    int x,y,r=0;
    c[k+1]='\0';
    while(i>=0||j>=0){
        x=(i>=0?a[i--]-'0':0);
        y=(j>=0?b[j--]-'0':0);
        c[k--]=(x+y+r)%10+'0';
        r=(x+y+r)/10;
    }
    string st(c);
    if(r!=0)
        st.insert(st.begin(), r+'0');
    return st;
}

string multiply(string st, int num){
    int i,r=0;
    for(i=0; i<st.size(); i++)
        a[i]=(st[i]-'0')*num;
    for(i=st.size()-1; i>=0; i--){
        st[i]=(a[i]+r)%10+'0';
        r=(a[i]+r)/10;
    }
    while(r!=0){
        st.insert(st.begin(), r%10+'0');
        r/=10;
    }
    return st;
}

int main(int argc, char** argv) {
    int i,cas=1;

    s[1]="0";
    s[2]="1";
    for(i=3; i<=1000; i++)
        s[i]=multiply(add(s[i-1],s[i-2]),i-1);

    scanf("%d", &i);
    while(i){
        printf("Case %d:\n", cas++);
        printf("%s\n", s[i].c_str());
        scanf("%d", &i);
    }

    return 0;
}
