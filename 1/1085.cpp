#include <iostream>
using namespace std;

int a[1001][1001];

void inserty(int x, int y, int z)
{
    int l=1,r=1000,m;
    while(l<=r)
    {
       m=(l+r)/2;
       if(y<=m)
          if(a[x][m]>=z)
            a[x][m]=z;
       
       if(y==m)
          break;
       if(y<m)
          r=m-1;
       else
          l=m+1;
    }
}


void insertx(int x, int y, int z)
{
    int l=1,r=1000,m;
    while(l<=r)
    {
      m=(l+r)/2;
      if(x<=m)
        inserty(m,y,z);
      if(x==m)
        break;
      if(x<m)
        r=m-1;
      else
        l=m+1;
    }
}

int queryy(int x, int y)
{
    int l=1,r=1000,m,ans=10000;
    while(l<=r)
    {
       m=(l+r)/2;
       if(y>=m)
       {
          if(a[x][m]<ans)
             ans=a[x][m];
       }
       if(y<=m)
          r=m-1;
       else
          l=m+1;
    }
    return ans;
}

int queryx(int x, int y)
{
    int l=1,r=1000,m,ans=10000,tmp;
    while(l<=r)
    {
       m=(l+r)/2;
       if(x>=m)
       {
         tmp=queryy(m,y);
         if(tmp<=ans)
           ans=tmp;
       }
       
       if(x<=m)
         r=m-1;
       else
         l=m+1;
    }
    return ans;
}


int main()
{
    int n,x,y,z,op;
    int i,j;
    
    for(i=1;i<=1000;i++)
    for(j=1;j<=1000;j++)
      a[i][j]=10000;
    
    scanf("%d", &n);
    while(n--)
    {
      scanf("%d%d%d%d", &op, &x, &y, &z);
      if(op==0)
        insertx(x,y,z);
      else if(queryx(x,y)<=z)
        printf("yes\n");
      else
        printf("no\n");
    }
    
    return 0;
}
