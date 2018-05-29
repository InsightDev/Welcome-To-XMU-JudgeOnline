#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define inf 1000000000
using namespace std;

int c[201][201];
int f[201][201];
int w[201];
int p[201];
int n, s, t;

bool bfs() {
    queue<int> que;
    int u, v, i;
    for (i = 1; i <= n; i++) {
        p[i] = -1;
        w[i] = inf;
    }
    p[s] = -2;
    que.push(s);
    while (!que.empty()) {
        u = que.front();
        que.pop();
        for (v = 1; v <= n; v++) {
            if (p[v] == -1 && c[u][v] > f[u][v]) {
                p[v] = u;
                w[v] = min(w[u], c[u][v] - f[u][v]);
                if (v == t)
                    return true;
                que.push(v);
            }
        }
    }
    return false;
}

int edmonds_karp() {
    int u, v, flow = 0;
    s = 1;
    t = n;
    while (bfs()) {
        for (v = t; v != s; v = u) {
            u = p[v];
            f[u][v] += w[t];
            f[v][u] -= w[t];
        }
        flow += w[t];
    }
    return flow;
}

int main(int argc, char** argv) {
    int m, u, v, cap;
    int i, j;

    while(cin>>m>>n){
        for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            c[i][j] = f[i][j] = 0;
        while(m--){
            scanf("%d %d %d", &u, &v, &cap);
            c[u][v] += cap;
        }
        printf("%d\n", edmonds_karp());
    }

    return 0;
}
