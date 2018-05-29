#include <stdio.h>
#include <string.h>

int q[100000];

int main(int argc, char* argv[])
{
	int n;
	char s[4];
	int head = 0;
	int tail = 0;

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if (!strcmp(s, "PUT")) {
			scanf("%d", &q[tail++]);
		} else {
			if (head == tail)
				printf("EMPTY\n");
			else
				printf("%d\n", q[head++]);
		}
	}

	return 0;
}
