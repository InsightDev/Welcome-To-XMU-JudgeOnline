#include <cstdio>
using namespace std;

bool b[65536];
int mk[4][4];

void process()
{
	int i, j, k;
	int s, t;
	for (i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
		mk[i][j] = 1 << (i * 4 + j);
	for (s = 0; s < 65536; s++) {
		if (b[s])
			continue;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (s & mk[i][j])
					continue;
				t = s;
				for (k = j; k < 4; k++) {
					if (t & mk[i][k])
						break;
					t |= mk[i][k];
					b[t] = true;
				}
				t = s;
				for (k = i; k < 4; k++) {
					if (t & mk[k][j])
						break;
					t |= mk[k][j];
					b[t] = true;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	char s[4][5];
	int i, j, num = 0;

	for (i = 0; i < 4; i++)
		scanf("%s", s[i]);
	for (i = 3; i >= 0; i--)
	for (j = 3; j >= 0; j--)
		num = num * 2 + (s[i][j] == 'O' ? 1 : 0);
	
	process();
	printf("Player%d Win\n", b[num] ? 1 : 2);

	return 0;
}
