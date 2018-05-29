#include <stdio.h>
#include <string.h>

char s[729][730];

int main(int argc, char *argv[])
{
	int n, l, i, j, k;

	scanf("%d", &n);
	while (n != -1) {
		l = 1;
		s[0][0] = '7';
		while (n--) {
			for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (i == 0 || j == 2)
					for (k = 0; k < l; k++)
						memcpy(s[i*l+k]+j*l, s[k], l);
				else
					for (k = 0; k < l; k++)
						memset(s[i*l+k]+j*l, ' ', l);
			}
			l *= 3;
		}
		for (i = 0; i < l; i++) {
			s[i][l] = '\0';
			printf("%s\n", s[i]);
		}
		printf("\n");
		scanf("%d", &n);
	}

	return 0;
}
