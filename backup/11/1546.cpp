#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

typedef enum {slpa, srpa, sadd, ssub, smul, sdiv, ssen} symbol;

int ocp[] = {20, 0, 5, 5, 10, 10, 0};
int otp[] = {0, 20, 6, 6, 11, 11, 0};

symbol get_symbol(char ch)
{
	switch (ch) {
		case '(': return slpa;
		case ')': return srpa;
		case '+': return sadd;
		case '-': return ssub;
		case '*': return smul;
		case '/': return sdiv;
		default: return ssen;
	}
}

int cal(int a, int b, char op)
{
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		default: return a / b;
	}
}

int main(int argc, char *argv[])
{
	int val, n1, n2;
	char ch, cp;
	symbol top;
	symbol com;

	stack<int> num;
	stack<char> op;
	op.push('#');

	scanf("%c", &ch);
	while (ch != '\n' || num.size() > 1) {
		if (isdigit(ch)) {
			ungetc(ch, stdin);
			scanf("%d", &val);
			num.push(val);
			scanf("%c", &ch);
		} else {
			com = get_symbol(ch);
			top = get_symbol(op.top());
			if (ocp[com] > otp[top]) {
				op.push(ch);
				scanf("%c", &ch);
			} else if (ocp[com] == otp[top]) {
				op.pop();
				scanf("%c", &ch);
			} else {
				n2 = num.top();
				num.pop();
				n1 = num.top();
				num.pop();
				cp = op.top();
				op.pop();
				num.push(cal(n1, n2, cp));
			}
		}
	}
	printf("%d\n", num.top());

	return 0;
}
