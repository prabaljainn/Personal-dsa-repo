#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
#define mod2 998244353
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define sz(v) ((ll)(v).size())
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornd(i, n) for (int i = (n)-1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i <= (b); ++i)
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    fast_io;
    // cin.ignore(); must be there when using getline(cin, s)
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        /* code */
        cin >> a[i];
        m[a[i]]++;
    }
    for (auto x : m)
    {
        if (x.s > n / 2)
        {
            cout << x.f << endl;
            break;
        }
    }
    return 0;
}