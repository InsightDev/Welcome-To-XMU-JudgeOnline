#include <stdio.h>
#include <string.h>

#define S 10

struct AVInteger {
	unsigned short v[S];
};

const unsigned char log2_tab[256] = {
	0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
	4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

char* str_num_dub(char* s)
{
	int l = strlen(s);
	int t, r = 0;

	for (register int i = l - 1; i >= 0; i--)
	{
		t = ((s[i] - '0') << 1) + r;
		r = t / 10;
		s[i] = t % 10 + '0';
	}
	if (r)
		*(--s) = r + '0';

	return s;
}

char* str_num_inc(char* s)
{
	int l = strlen(s);
	int t, r = 1;

	for (register int i = l - 1; i >= 0; i--)
	{
		t = (s[i] - '0') + r;
		r = t / 10;
		s[i] = t % 10 + '0';
	}
	if (r)
		*(--s) = r + '0';

	return s;
}

char* avi_to_str(AVInteger a)
{
	static char s[50];
	char* ps = NULL;
	int neg = a.v[S-1] & (1 << 15);
	int i, j, k, v;

	if (neg)
	{
		for (i = 0; i < S; i++)
			a.v[i] = ~a.v[i];
	}

	memset(s, 0, sizeof(s));
	s[49] = '0';
	ps = s + 49;

	for (k = S - 1; k >= 0; k--)
	{
		v = a.v[k];
		for (j = 15; j >= 0; j--)
		{
			ps = str_num_dub(ps);
			if (a.v[k] & (1 << j))
				ps = str_num_inc(ps);
		}
	}

	if (neg)
	{
		ps = str_num_inc(ps);
		*(--ps) = '-';
	}

	return ps;
}

inline int avi_log2(AVInteger a)
{
	for (register int i = S - 1; i >= 0; i--)
		if (a.v[i])
			return log2_tab[a.v[i]] + 16 * i;

	return -1;
}

inline AVInteger avi_add(const AVInteger& a, const AVInteger& b)
{
	AVInteger out;
	int c = 0;

	for (register int i = 0; i < S; i++)
		out.v[i] = c = (c >> 16) + a.v[i] + b.v[i];

	return out;
}

inline AVInteger avi_sub(const AVInteger& a, const AVInteger& b)
{
	AVInteger out;
	int c = 0;

	for (register int i = 0; i < S; i++)
		out.v[i] = c = (c >> 16) + a.v[i] - b.v[i];

	return out;
}

inline AVInteger avi_mul(const AVInteger& a, const AVInteger& b)
{
	AVInteger out;
	int na = (avi_log2(a) + 16) >> 4;
	int nb = (avi_log2(b) + 16) >> 4;

	memset(&out, 0, sizeof(out));
	for (register int i = 0; i < na; i++)
	{
		unsigned int c = 0;
		if (!a.v[i])
			continue;
		for (register int j = i; j < S && j - i <= nb; j++)
			out.v[j] = c = (c >> 16) + out.v[j] + a.v[i] * b.v[j-i];
	}

	return out;
}

inline int avi_cmp(const AVInteger& a, const AVInteger& b)
{
	int v = (short)a.v[S-1] - (short)b.v[S-1];
	if (v) return (v >> 16) | 1;

	for (register int i = S - 2; i >= 0; i--)
	{
		v = a.v[i] - b.v[i];
		if (v) return (v >> 16) | 1;
	}

	return 0;
}

inline AVInteger avi_max(const AVInteger& a, const AVInteger& b)
{
	return avi_cmp(a, b) > 0 ? a : b;
}

inline AVInteger avi_min(const AVInteger& a, const AVInteger& b)
{
	return avi_cmp(a, b) < 0 ? a : b;
}

inline AVInteger get_max_avi()
{
	AVInteger out;

	memset(&out, 0xff, sizeof(out));
	out.v[S-1] &= 0x7fff;

	return out;
}

inline AVInteger get_min_avi()
{
	AVInteger out;

	memset(&out, 0, sizeof(out));
	out.v[S-1] |= 0x8000;

	return out;
}

inline AVInteger int_to_avi(long long a)
{
	AVInteger out;

	for (int i = 0; i < S; i++)
	{
		out.v[i] = a;
		a >>= 16;
	}

	return out;
}

char* dyna(int* a, char* o, int n)
{
	AVInteger mav[51][51];
	AVInteger miv[51][51];
	AVInteger max_avi = get_max_avi();
	AVInteger min_avi = get_min_avi();
	AVInteger e[4];
	int i, j, k, l;

	for (i = 1; i <= n; i++)
		mav[i][i] = miv[i][i] = int_to_avi(a[i]);

	for (l = 2; l <= n; l++)
	{
		for (i = 1; i <= n - l + 1; i++)
		{
			j = i + l - 1;
			miv[i][j] = max_avi;
			mav[i][j] = min_avi;
			for (k = i; k < j; k++)
			{
				switch (o[k])
				{
					case '+':
					{
						mav[i][j] = avi_max(mav[i][j], avi_add(mav[i][k], mav[k+1][j]));
						miv[i][j] = avi_min(miv[i][j], avi_add(miv[i][k], miv[k+1][j]));
						break;
					}
					case '-':
					{
						mav[i][j] = avi_max(mav[i][j], avi_sub(mav[i][k], miv[k+1][j]));
						miv[i][j] = avi_min(miv[i][j], avi_sub(miv[i][k], mav[k+1][j]));
						break;
					}
					case '*':
					{
						e[0] = avi_mul(mav[i][k], mav[k+1][j]);
						e[1] = avi_mul(mav[i][k], miv[k+1][j]);
						e[2] = avi_mul(miv[i][k], mav[k+1][j]);
						e[3] = avi_mul(miv[i][k], miv[k+1][j]);
						for (int z = 0; z < 4; z++)
						{
							mav[i][j] = avi_max(mav[i][j], e[z]);
							miv[i][j] = avi_min(miv[i][j], e[z]);
						}
						break;
					}
				}
			}
		}
	}

	return avi_to_str(mav[1][n]);
}

int main(int argc, char* argv[])
{
	char s[105], o[51];
	int a[51];
	int k, n;

	while (scanf("%s", s) != EOF) {
		for (n = 0, k = 0; s[k]; k++) {
			if (k & 1)
				o[n] = s[k];
			else
				a[++n] = s[k] - '0';
		}
		printf("%s\n", dyna(a, o, n));
	}

	return 0;
}
