#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        int num1 = Xa / xa;
        int num2 = Xb / xb;
        cout << num1 + num2 << "\n";
    }
    return 0;
}