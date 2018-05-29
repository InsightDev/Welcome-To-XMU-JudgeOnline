#include <iostream>
using namespace std;

char s[502][502];
char t[502][502];
int p[502][502];
int b[502];
int n,m,r,c;

void next(){
    int i,j,k;
    for(k=1;k<=r;k++){
      p[k][1]=0;
      j=0;
      for(i=2;i<=c;i++){
        while(j>0&&t[k][j+1]!=t[k][i])
          j=p[k][j];
        if(t[k][j+1]==t[k][i])
          j++;
        p[k][i]=j;
      }
    }
}

void kmp(int beg){
   int i,j,k,cur=1;
   for(k=beg;k<beg+r;k++){
     j=0;
     for(i=1;i<=m;i++){
       while(j>0&&t[cur][j+1]!=s[k][i])
         j=p[cur][j];
       if(t[cur][j+1]==s[k][i])
         j++;
       if(j==c)
         b[i-r+1]++;
     }
     cur++;
   }
}

void match(){
    int i,k,cot=0,sx,sy;
    
    next();
    for(i=1;i<=n-r+1;i++){
      for(k=1;k<=m-c+1;k++)
        b[k]=0;
      kmp(i);
      for(k=1;k<=m-c+1;k++){
        if(b[k]==r){
          cot++;
          if(cot>1){
            printf("ambiguous\n");
            return;
          }
          sx=i;
          sy=k;
        }
      }
    }
    if(cot==0)
      printf("no\n");
    else
      printf("%d %d\n", sx-1, sy-1);
}

int main()
{
    int i;
    
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++)
      scanf("%s", &s[i][1]);
    scanf("%d %d", &r, &c);
    for(i=1;i<=r;i++)
      scanf("%s", &t[i][1]);
    match();
    
    return 0;
}