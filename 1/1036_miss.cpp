#include <stdio.h>

#define C 26

int main(int argc, char* argv[])
{
	int a, b, c, d, e, f, g;
	int h, i, j, k, l, m, n;
	int o, p, q, r, s, t;
	int u, v, w, x, y, z;
	int cn, cm, sa = 0;

	scanf("%d", &cn);
	cn = cn * 2;
	cn = cn - 1;
	cm = cn / C;
	cn = cn % C;
	while (cn--) {
		scanf("%d", &a);
		sa ^= a;
	}
	while (cm--) {
		scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
			&a, &b, &c, &d, &e, &f, &g,
			&h, &i, &j, &k, &l, &m, &n,
			&o, &p, &q, &r, &s, &t,
			&u, &v, &w, &x, &y, &z);
		sa = sa ^ a ^ b ^ c ^ d ^ e ^ f ^ g
				^ h ^ i ^ j ^ k ^ l ^ m ^ n
				^ o ^ p ^ q ^ r ^ s ^ t
				^ u ^ v ^ w ^ x ^ y ^ z;
	}
	printf("%d\n", sa);

	return 0;
}
