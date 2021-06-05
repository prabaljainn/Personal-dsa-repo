#include <bits/stdc++.h>

using namespace std;

bool isStringBalanced(string str);

int main()
{
    return 0;
}

bool MatchParaenthisis(char a, char b)
{
    return ((a == '[' && b == ']') || (a == '(' && b == ')') || (a == '{' && b == '}'));
}
bool isStringBalanced(string str)
{

    stack<char> stack;
    for (auto x : str)
    {
        if (x == '{' || x == '[' || x == '(')
            stack.push(x);
        else
        {
            if (stack.empty() == true)
                return false;
            if (MatchParaenthisis(stack.top(), x) == false)
                return false;
            else
                stack.pop();
        }
    }
}