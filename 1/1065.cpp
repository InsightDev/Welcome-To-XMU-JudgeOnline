#include <stdio.h>

struct node {
	node *next[26];
	bool exist;
};

bool insert(node *ptr, char *s)
{
	int i, k;
	for (i = 0; s[i]; i++) {
		k = s[i] - 'a';
		if (!ptr->next[k])
			ptr->next[k] = new node();
		ptr = ptr->next[k];
	}
	if (ptr->exist)
		return false;
	ptr->exist = true;
	return true;
}

int main(int argc, char *argv[])
{
	char s[11];
	int n, cnt = 0;
	node* root = new node();

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if (insert(root, s))
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
