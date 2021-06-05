#include <bits/stdc++.h>
using namespace std;
void RevString(string &s)
{
    int size = s.length();
    for (int i = 0; i < size / 2; i++)
    {
        swap(s[i], s[size - i - 1]);
    }
}

int main()
{
    string s;
    //* Input of string s
    cin >> s;

    RevString(s);
    cout << s;

    return 0;
}