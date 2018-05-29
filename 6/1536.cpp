#include <stdio.h>

struct list_head {
	list_head *prev;
	list_head *next;
} node[1000001];

inline void __list_add(list_head *curr, list_head *prev, list_head *next)
{
	next->prev = curr;
	curr->next = next;
	curr->prev = prev;
	prev->next = curr;
}

inline void __list_del(list_head * prev, list_head * next)
{
	next->prev = prev;
	prev->next = next;
}

inline void list_add(list_head *curr, list_head *head)
{
	__list_add(curr, head->prev, head);
}

inline void list_del(list_head *curr)
{
	__list_del(curr->prev, curr->next);
	curr->next = NULL;
	curr->prev = NULL;
}

int main(int argc, char* argv[])
{
	int m, n, w, i;
	int ans = 0;
	int cnt = 0;
	list_head head = { &head, &head };

	scanf("%d %d %d", &m, &n, &w);
	while (w--) {
		scanf("%d", &i);
		if (node[i].next) {
			list_del(&node[i]);
			list_add(&node[i], &head);
		} else {
			list_add(&node[i], &head);
			if (++cnt > m) {
				list_del(head.next);
				cnt--;
			}
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
