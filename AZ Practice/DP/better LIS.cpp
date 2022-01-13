/*
    Sigma rule:
    1) never mix 0 based and 1 based indexing
    2) never use ceil function
    3) never use unordered_map||unordered_set
    4) always go with the gut feeling
    5) first sighted observations always lead to AC, not overthinking
    6) always take MOD, always :(
*/
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n; int arr[100100];
int dp[100100];
int lis(vector<int> temp){
	
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0 ;i<n;i++)
		cin>>arr[i];
	cout<<rec(n-1);
	OK
	
}

signed main() {

	IOS
	cin.tie(0);
	cout.tie(0);
   #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   #endif
    // int _t;cin >> _t;while (_t--) solve();
	solve();



}