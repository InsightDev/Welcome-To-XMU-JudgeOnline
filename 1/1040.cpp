#include <cmath>
#include <iostream>
using namespace std;

int t[301][301];
int a[301][301];
int b[301][301];
int d[301][301];
int preMac[301][301];
int jobCol[301][301];
int n,m;


int schedule(int job, int mac, int col){
    if(d[mac][col]!=-1)
      return d[mac][col];
    
    int pMac=preMac[job][mac];
    int pCol=jobCol[pMac][job];
    if(pMac==0){
      if(col==1) 
        d[mac][col]=t[job][mac];
      else
        d[mac][col]=schedule(b[mac][col-1],mac,col-1)+t[job][mac];
    }
    else{
      if(col==1)
        d[mac][col]=t[job][mac]+schedule(job,pMac,pCol);
      else
        d[mac][col]=t[job][mac]+max(schedule(job,pMac,pCol),schedule(b[mac][col-1],mac,col-1));
    }
    return d[mac][col];
}

int main()
{
	int i, j, max;

	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 1;i <= n; i++)
		for (j = 1;j <= m; j++)
			scanf("%d", &t[i][j]);

		for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			preMac[i][a[i][j]] = a[i][j-1];
		}

		for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &b[i][j]);
			jobCol[i][b[i][j]] = j;
			d[i][j] = -1;
		}

		max = 0;
		for (i = 1;i <= m; i++) {
			d[i][n]=schedule(b[i][n],i,n);
			if (d[i][n] > max)
				max = d[i][n];
		}
		printf("%d\n", max);
	}
	return 0;
}
