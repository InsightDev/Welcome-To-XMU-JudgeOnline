#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	node(int num) {
		this->num = num;
		this->left = NULL;
		this->right = NULL;
	}
	int num;
	node *left;
	node *right;
};

int a[100000];
int n, z;

void output(struct node *root)
{
	if (root == NULL)
		return;
	output(root->left);
	printf("%d", root->num);
	printf("%c", ++z == n ? '\n' : ' ');
	output(root->right);
}

void insert(struct node *root, int num)
{
	int dir = rand() % 2;
	if (num < root->num)
		dir = 0;
	else if (num > root->num)
		dir = 1;

	if (dir == 0) {
		if (root->left)
			insert(root->left, num);
		else
			root->left = new node(num);
	} else {
		if (root->right)
			insert(root->right, num);
		else
			root->right = new node(num);
	}
}

int main(int argc, char *argv[])
{
	int i, j, k;
	struct node *root;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	k = n >> 1;
	while (k--) {
		i = rand() % n;
		j = rand() % n;
		if (i != j)
			swap(a[i], a[j]);
	}

	root = new node(a[0]);
	for (i = 1; i < n; i++)
		insert(root, a[i]);

	output(root);

	return 0;
}
