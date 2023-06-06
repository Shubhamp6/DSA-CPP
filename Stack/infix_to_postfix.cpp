#include <bits/stdc++.h>
using namespace std;

int isOpretor(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || c == '(';
}

int precedance(char a)
{
    if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    return 0;
}

char *infixToPostfix(string infixExp)
{
    char *postfixExp;
    stack<char> s;
    int i = 0, j = 0;
    while (infixExp[i] != '\0')
    {
        char c = infixExp[i];
        if (!isOpretor(c))
        {
            postfixExp[j++] = c;
            i++;
        }
        else
        {
            if (c == '(')
            {
                s.push(c);
                i++;
            }

            else if (c == ')')
            {
                while (s.top() != '(')
                {
                    postfixExp[j++] = s.top();
                    s.pop();
                }
                s.pop();
                i++;
            }
            else if (s.empty() || precedance(c) > precedance(s.top()))
            {
                s.push(c);
                i++;
            }
            else
            {
                postfixExp[j++] = s.top();
                s.pop();
            }
        }
    }
    if (!s.empty())
    {
        while (!s.empty())
        {
            postfixExp[j++] = s.top();
            s.pop();
        }
    }
    postfixExp[j] = '\0';
    return postfixExp;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string infixExp;
    cin >> infixExp;
    cout << infixToPostfix(infixExp) << endl;
    return 0;
}