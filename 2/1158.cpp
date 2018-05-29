#include <stdio.h>

struct node {
	node *c[26];
	node *root;
};

void insert(node *root, char *t)
{
	node *ptr = root;
	for (int i = 0; t[i]; i++) {
		int k = t[i] - 'a';
		if (!ptr->c[k])
			ptr->c[k] = new node();
		ptr = ptr->c[k];
	}
	ptr->root = root;
}

int query(node *ptr, char *s, int i)
{
	if (!s[i])
		return ptr->root != NULL;
	int k = s[i] - 'a';
	return (ptr->c[k] && query(ptr->c[k], s, i + 1))
			|| (ptr->root && query(ptr->root, s, i));
}

int main(int argc, char *argv[])
{
	node *root = new node();
	char s[10001], t[101];
	int n;

	scanf("%s", s);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", t);
		insert(root, t);
	}
	if (query(root, s, 0))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
