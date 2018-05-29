#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct tm tc;
	char buf[128];
	int t;

	scanf("%d", &t);
	scanf("%d-%d-%d %d:%d:%d",
		&tc.tm_year, &tc.tm_mon, &tc.tm_mday,
		&tc.tm_hour, &tc.tm_min, &tc.tm_sec);
	tc.tm_year -= 1900;
	tc.tm_mon -= 1;
	tc.tm_sec += t;

	time_t tmp = mktime(&tc);
	strftime(buf, 128, "%F %T",
				gmtime(&tmp));
	printf("%s\n", buf);

	return 0;
}
