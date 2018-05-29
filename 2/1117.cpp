#include <stdio.h>
#include <limits.h>

const char* s[30];
int a[30][30];

int get_index(char ch)
{
	switch (ch) {
		case '[': return 26;
		case ';': return 27;
		case ',': return 28;
		case '.': return 29;
		default: return ch - 'A';
	}
}

int main(int argc, char *argv[])
{
	int i, j, k, d;
	double sum = 0;
	char t[9];

	// ABCDEFG
	s[0] = "QWSZ";
	s[1] = "VGHN";
	s[2] = "XDFV";
	s[3] = "SERFCX";
	s[4] = "WSDR";
	s[5] = "DRTGVC";
	s[6] = "FTYHBV";
	// HIJKLMN
	s[7] = "GYUJNB";
	s[8] = "UJKO";
	s[9] = "HUIKMN";
	s[10] = "JIOL,M";
	s[11] = "KOP;.,";
	s[12] = "NJK,";
	s[13] = "BHJM";
	// OPQRST
	s[14] = "IKLP";
	s[15] = "OL;[";
	s[16] = "AW";
	s[17] = "EDFT";
	s[18] = "AWEDXZ";
	s[19] = "RFGY";
	// UVWXYZ
	s[20] = "YHJI";
	s[21] = "CFGB";
	s[22] = "QASE";
	s[23] = "ZSDC";
	s[24] = "TGHU";
	s[25] = "ASX";
	// [;,.
	s[26] = "P;";
	s[27] = "LP[.";
	s[28] = "MKL.";
	s[29] = "L;,";

	for (i = 0; i < 30; i++)
	for (j = 0; j < 30; j++)
		if (i != j)
			a[i][j] = INT_MAX;

	for (i = 0; i < 30; i++) {
		for (k = 0; s[i][k]; k++) {
			j = get_index(s[i][k]);
			a[i][j] = 1;
		}
	}

	for (k = 0; k < 30; k++) {
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 30; j++) {
				if (a[i][k] != INT_MAX &&
					a[k][j] != INT_MAX &&
					a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}

	scanf("%s", t);
	for (i = 0; i < 30; i++) {
		d = INT_MAX;
		for (k = 0; k < 8; k++) {
			j = get_index(t[k]);
			if (a[i][j] < d)
				d = a[i][j];
		}
		sum += d;
	}
	printf("%.3f\n", 1 + sum / 30);

	return 0;
}
