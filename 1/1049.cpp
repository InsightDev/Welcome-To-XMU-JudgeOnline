#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define inf 1000000000
using namespace std;

struct node{
	node(int num, int len){
		this->num=num;
		this->len=len;
	}
	int num;
	int len;
};

vector<node> nt[20002];
int d[20002],b[20002];
int a[401][201];
int s[401];
int n,m;

void cgraph(){
	int i,j,k,si,ti,nu;
	char ch;
	m=2*n*n;
	for(i=0; i<=m+1; i++)
		nt[i].clear();
	for(i=1; i<=2*n; i++){
		if(i%2==1)
			a[i][0]=i+1;
		else
			a[i][0]=i/2;
		a[4*n-i][0]=a[i][0];
	}
	for(i=1; i<=4*n-1; i++){
		for(k=1; k<=a[i][0]; k++)
			scanf("%d", &a[i][k]);
		if(i%2==1)
			s[i]=a[i][0]-1;
	}
	nu=0;
	for(i=1; i<=4*n-1; i+=2){
		nt[0].push_back(node(nu+1,a[i][1]));
		nt[nu+1].push_back(node(0,a[i][1]));
		nt[nu+s[i]].push_back(node(m+1,a[i][a[i][0]]));
		nt[m+1].push_back(node(nu+s[i],a[i][a[i][0]]));
		for(j=2; j<=s[i]; j++){
			nt[nu+j-1].push_back(node(nu+j,a[i][j]));
			nt[nu+j].push_back(node(nu+j-1,a[i][j]));
		}
		nu+=s[i];
	}
	nu=0;
	for(i=2; i<=4*n-1; i+=2){
		for(j=1; j<=a[i][0]; j++){
			if(i<2*n){
				si=nu+2*j-1;
				ti=nu+s[i-1]+2*j;
			}else if(i==2*n){
				si=nu+2*j-1;
				ti=nu+s[i-1]+2*j-1;
			}else{
				si=nu+2*j;
				ti=nu+s[i-1]+2*j-1;
			}
			nt[si].push_back(node(ti,a[i][j]));
			nt[ti].push_back(node(si,a[i][j]));
		}
		nu+=s[i-1];
	}
}

int spfa()
{
	int u, i;
	queue<int> que;
	vector<node>::iterator it;

	for (i = 1; i <= m + 1; i++) {
		d[i] = inf;
		b[i] = false;
	}
	d[0] = 0;
	b[0] = true;
	que.push(0);
	while (!que.empty()) {
		u = que.front();
		que.pop();
		b[u] = false;
		for (it = nt[u].begin(); it != nt[u].end(); it++) {
			if (d[it->num] > d[u] + it->len) {
				d[it->num] = d[u] + it->len;
				if (!b[it->num]) {
					b[it->num] = true;
					que.push(it->num);
				}
			}
		}
	}
	return d[m+1];
}

int main(int argc, char* argv[])
{
	int c = 0;

	scanf("%d", &n);
	while (n) {
		cgraph();
		printf("Case %d:\n", ++c);
		printf("%d\n", spfa());
		scanf("%d", &n);
	}

	return 0;
}
