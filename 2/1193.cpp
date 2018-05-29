#include <math.h>
#include <stdio.h>

int x[1000001] = {1};

int sls(int i)
{
	if (x[i] == 0)
	{
		double si = sin(i);
		int v0 = sls(i - sqrt(i));
		int v1 = sls(log(i));
		int v2 = sls(i * si * si);
		x[i] = (v0 + v1 + v2) % 1000000;
	}
	return x[i];
}

int main(int argc, char* argv[])
{
	int i;

	scanf("%d", &i);
	while (i != -1)
	{
		printf("%d\n", sls(i));
		scanf("%d", &i);
	}

	return 0;
}
