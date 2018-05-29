#include <stdio.h>

struct node {
	node *cld[26];
	int key;
};

int a[100001];
int c[100001];
int m;

int insert(node* ptr, char s[])
{
	int i, k;
	for (i = 0; s[i]; i++) {
		k = s[i] - 'a';
		if (!ptr->cld[k])
			ptr->cld[k] = new node();
		ptr = ptr->cld[k];
	}
	if (!ptr->key)
		ptr->key = ++m;
	return ptr->key;
}

int main(int argc, char *argv[])
{
	int n, i, j = 0;
	char s[21];
	node *root = new node();

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", s);
		a[i] = insert(root, s);
	}

	int cnt = 0;
	int ans = n;
	for (i = 1; i <= n; i++) {
		c[a[i]]++;
		if (c[a[i]] == 1)
			cnt++;
		if (cnt == m) {
			while (cnt == m) {
				c[a[++j]]--;
				if (c[a[j]] == 0)
					cnt--;
			}
			if (i - j + 1 < ans)
				ans = i - j + 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}
