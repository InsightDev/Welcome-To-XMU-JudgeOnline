#include <stack>
#include <cstdio>
#include <cctype>
using namespace std;

typedef enum { slpa, srpa, sadd, ssub, smul, sdiv, ssen } symbol;

int ocp[] = { 20, 0, 5, 5, 10, 10, 0 };
int otp[] = { 0, 20, 6, 6, 11, 11, 0 };

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

int calculate(int a, int b, char op)
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
	int val, a, b;
	char ch, cp;
	symbol cs;
	symbol ts;

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
			cs = get_symbol(ch);
			ts = get_symbol(op.top());
			if (ocp[cs] > otp[ts]) {
				op.push(ch);
				scanf("%c", &ch);
			} else if (ocp[cs] == otp[ts]) {
				op.pop();
				scanf("%c", &ch);
			} else {
				b = num.top();
				num.pop();
				a = num.top();
				num.pop();
				cp = op.top();
				op.pop();
				num.push(calculate(a, b, cp));
			}
		}
	}
	printf("%d\n", num.top());

	return 0;
}
