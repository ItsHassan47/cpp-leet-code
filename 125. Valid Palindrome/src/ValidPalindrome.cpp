#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string s)
{    
    stack<char>st;
    string res;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            st.push(toupper(s[i]));
            res += toupper(s[i]);
        }
    }

    for (int i = 0; i < res.length() && !st.empty(); i++) {
        if (st.top() != res[i]) {
            return false;
        }
        st.pop();
    }
    return true;
}

int main()
{
    //string s {"A man, a plan, a canal: Panama"};
    //string s {"0P"};
    string s {"race a car"};
    cout << isPalindrome(s);
	return 0;
}