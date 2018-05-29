#include <cstdio>
#include <algorithm>
using namespace std;

struct point {
	int x;
	int y;
} p[1000000];
int n;

struct node {
	void set(int i, int j, node* l, node* r) {
		x = i;
		y = j;
		lc = l;
		rc = r;
	}
	int x, y;
	node* lc;
	node* rc;
} q[1000000];
int idx = 0;

/*
8
5 8
1 4
7 3
10 6
2 7
6 2
3 9
6 5
2
2 6
4 4
*/

double s[8][2] = {
	{5, 8}, {1, 4}, {7, 3}, {10, 6}, {2, 7}, {6, 2}, {3, 9}, {6, 5}
};

double t[8][2];


int partition(int l, int r, int z)
{
	int i, j = l - 1;
	int k = l + rand() % (r - l + 1);

	swap(s[k][0], s[r][0]);
	swap(s[k][1], s[r][1]);	
	for (i = l; i < r; i++) {
		if (s[i][z] < s[r][z]) {
			j++;
			swap(s[j][0], s[i][0]);
			swap(s[j][1], s[i][1]);
		}
	}
	j++;
	swap(s[j][0], s[r][0]);
	swap(s[j][1], s[r][1]);
	return (r + l) / 2 + 1;
	return j;
}

struct node* slice(int l, int r, int z)
{
	if (l < r) {
		int k = partition(l, r, z);
		q[idx].set(s[k][0], s[k][1], slice(l, k - 1, z ^ 1), slice(k + 1, r, z ^ 1));
		return &q[idx++];
	} else if (l == r) {
		q[idx].set(s[r][0], s[r][1], NULL, NULL);
		return &q[idx++];
	}
	return NULL;
}

void print(struct node* root)
{
	if (root == NULL)
		return;
	printf("- %d %d\n", root->x, root->y);
	print(root->lc);
	print(root->rc);
}


double cal(int x, int y)
{
	return 1;
}

int main(int argc, char* argv[])
{
	int m, i, j;
	struct node* root;
	/*
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &i, &j);
		printf("%.1f\n", cal(i, j));
	}
	*/
	n = 8;
	root = slice(0, n - 1, 0);
	print(root);

	return 0;
}
