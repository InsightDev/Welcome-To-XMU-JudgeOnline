#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

char s[1000][100][200];
char t[1000][200];
int cc[1000];
int dd[1000];

int main(int argc, char** argv) {
    map<string,int> off;
    map<string,int> cnt;
    map<string,int> adv;
    set<string> ans;
    int a,n,m,q,k,i,j;
    char ur[201];

    scanf("%d", &a);

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", ur);
        off[ur]=0;
    }

    scanf("%d", &k);
    for(i=0; i<k; i++){
        scanf("%d", &m);
        j=0;
        while(m--){
            scanf("%s", s[i][j]);
            if(off.find(s[i][j])!=off.end()){
                if(j<a)
                    cnt[s[i][j]]++;
                j++;
            }
        }
        cc[i]=j;
    }

    scanf("%d", &q);
    while(q--){
        scanf("%s %d", ur, &i);
        if(off.find(ur)!=off.end()&&cnt[ur]>=2)
            adv[ur]=i;
    }


    for(i=0; i<k; i++){
        for(j=0; j<cc[i]&&j<a; j++){
            if(ans.find(s[i][j])!=ans.end())
                continue;
            if(adv.find(s[i][j])==adv.end()||adv[s[i][j]]==i){
                ans.insert(s[i][j]);
                dd[i]++;
            }
        }
    }
    for(i=0; i<k; i++){
        j=a;
        while(dd[i]<a&&j<cc[i]){
            if(ans.find(s[i][j])==ans.end()){
                ans.insert(s[i][j]);
                dd[i]++;
            }
            j++;
        }
    }

    for(set<string>::iterator it=ans.begin(); it!=ans.end(); it++)
        printf("%s\n", (*it).c_str());

    return 0;
}
