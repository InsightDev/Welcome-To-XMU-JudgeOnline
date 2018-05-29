#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	char cmd[7];
	int n, i;
	char c;
	string st;

	cin >> st;
	scanf("%d", &n);
	while (n--) {
		scanf("%s %d", cmd, &i);
		if (!strcmp(cmd, "add")) {
			scanf(" %c", &c);
			st.insert(st.begin() + (i - 1), c);
		} else {
			st.erase(st.begin() + (i - 1));
		}
	}
	cout << st << endl;

	return 0;
}
