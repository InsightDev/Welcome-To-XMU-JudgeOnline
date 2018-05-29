#include <stdio.h>

int main(int argc, char *argv[])
{
	int x0, y0, w0, h0;
	int x1, y1, w1, h1;

	scanf("%d %d %d %d", &x0, &y0, &w0, &h0);
	scanf("%d %d %d %d", &x1, &y1, &w1, &h1);
	if (x0 + w0 <= x1 || x1 + w1 <= x0 ||
			y0 + h0 <= y1 || y1 + h1 <= y0)
		printf("No\n");
	else
		printf("Yes\n");
	
	return 0;
}
