#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

ll tree[4 * N];

void update(int node, int start, int end, int l, int r, int val) {
    if(start > r || end < l) return;
    if(start >= l && end <= r) {
        tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
}

ll query(int node, int start, int end, int idx) {
    if(start == end) return tree[node];
    int mid = (start + end) / 2;
    if(idx <= mid) return tree[node] + query(2 * node, start, mid, idx);
    return tree[node] + query(2 * node + 1, mid + 1, end, idx);
}

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);
      #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        update(1, 0, n - 1, i, i, x);
    }

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i, j, x;
            cin >> i >> j >> x;
            i--; j--;
            update(1, 0, n - 1, i, j, x);
        }
        else {
            int i;
            cin >> i;
            i--;
            cout << query(1, 0, n - 1, i) << "\n";
        }
    }
    return 0;
}