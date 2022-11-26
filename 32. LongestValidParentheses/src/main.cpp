#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
	int longest = 0;
	stack<int>stack;
	stack.push(-1);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			stack.push(i);
		else {
			stack.pop();
			if (stack.empty())
				stack.push(i);
			else
				longest = max(longest, i - stack.top());
		}
	}
	return longest;
}

int main()
{
	string s {"(()"};
	cout << longestValidParentheses(s);

	return 0;
}