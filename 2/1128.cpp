#include <queue>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define inf 1000000000
using namespace std;

int x[]={-1,0,1,0};
int y[]={0,1,0,-1};
char s[200][201];
double d[200][200];
double dws=inf;
int m,n,owns;
int ex,ey;

bool bound(int u, int v){
	return u>=0&&u<m&&v>=0&&v<n;
}

double fire(int sx, int sy){
	if(sx!=ex&&sy!=ey)
		return inf;
	int nx,ny,i;
	double cost;
	for(i=0; i<4; i++){
		nx=sx+x[i];
		ny=sy+y[i];
		cost=0;
		while(bound(nx,ny)){
			cost+=0.2;
			if(s[nx][ny]=='E')
				return cost;
			if(s[nx][ny]=='O')
				break;
			nx+=x[i];
			ny+=y[i];
		}
	}
	return inf;
}

double bfs(int sx, int sy){
	queue<int> xx;
	queue<int> yy;
	int i,j,nx,ny;
	double fd;
	for(i=0; i<m; i++)
	for(j=0; j<n; j++)
		d[i][j]=inf;
	d[sx][sy]=0;
	xx.push(sx);
	yy.push(sy);
	while(!xx.empty()){
		sx=xx.front(); xx.pop();
		sy=yy.front(); yy.pop();
		fd=fire(sx,sy);
		if(fd!=inf)
			return d[sx][sy]+fd;
		for(i=0; i<4; i++){
			nx=sx+x[i];
			ny=sy+y[i];
			if(!bound(nx,ny)||d[nx][ny]!=inf||s[nx][ny]=='O'||s[nx][ny]=='R'&&owns==0)
				continue;
			d[nx][ny]=d[sx][sy]+1;
			if(s[nx][ny]=='B')
				return d[nx][ny];
			if(s[nx][ny]=='S')
				dws=d[nx][ny];
			xx.push(nx);
			yy.push(ny);
		}
	}
	return inf;
}

int main(int argc, char** argv) {
	int i,j,wx,wy,sx,sy;
	double ans,tmp;
	bool eship=false;

	scanf("%d %d %d", &m, &n, &owns);
	for(i=0; i<m; i++){
		scanf("%s", s[i]);
		for(j=0; j<n; j++){
			if(s[i][j]=='W'){
				wx=i; wy=j;
			}else if(s[i][j]=='E'){
				ex=i; ey=j;
			}else if(s[i][j]=='S'){
				sx=i; sy=j; eship=true;
			}
		}
	}

	ans=bfs(wx,wy);
	if(eship&&dws!=inf){
		owns=1;
		tmp=bfs(sx,sy);
		if(tmp!=inf)
			ans=min(ans,tmp+dws);
	}
	if(ans==inf)
		printf("-1\n");
	else
		printf("%.1f\n", ans);

	return 0;
}
