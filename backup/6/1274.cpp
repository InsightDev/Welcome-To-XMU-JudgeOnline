#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int v[21];
int d[3000001];
queue<int> que;
int va, vb, vc;

int val(int a, int b, int c)
{
	return a * 10000 + b * 100 + c;
}

void process(int x, int y, int z)
{
	int num = val(x, y, z);
	if (!d[num]) {
		d[num] = 1;
		que.push(num);
	}
}

void search(int num)
{
	que.push(num);
	d[num] = 1;
	
	int a, b, c;
	int r, i;

	while (!que.empty()) {
		num = que.front();
		que.pop();
		
		a = num / 10000;
		b = num % 10000 / 100;
		c = num % 100;
		if (a == 0)
			v[c] = 1;
		
		if (a != 0) {
			r = min(a, vb - b);
			process(a - r, b + r, c);
			r = min(a, vc - c);
			process(a - r, b, c + r);
		}
		if (b != 0) {
			r = min(va - a, b);
			process(a + r, b - r, c);
			r = min(b, vc - c);
			process(a, b - r, c + r);
		}
		if (c != 0) {
			r = min(va - a, c);
			process(a + r, b, c - r);
			r = min(vb - b, c);
			process(a, b + r, c - r);
		}
	}
	for (i = 0; i <= vc; i++)
		if (v[i])
			printf("%d ", i);
	printf("\n");
}

int main(int argc, char *argv[])
{
	scanf("%d %d %d", &va, &vb, &vc);
	search(vc);

	return 0;
}
