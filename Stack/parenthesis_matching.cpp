#include <bits/stdc++.h>
using namespace std;

bool isMatching(char a, char b)
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

bool isParenthesisMatching(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else
        {
            if (s.empty())
                return false;
            else if (isMatching(s.top(), c))
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    cout << isParenthesisMatching(s) << endl;
    return 0;
}