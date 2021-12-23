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
int n; char arr[10010];
int dp[100][100];
int rec(int l, int r){
	//prune
	if(l>r)
		return 0;
	//base
	if(l==r)
		return 1;
    //dp check 
	if(dp[l][r]!= -1)
		return dp[l][r];

    // int dp[l][r] = 0;
    //computation
	if(arr[l]==arr[r])
		dp[l][r] = 2+ rec(l+1,r-1);

	else{
		dp[l][r] = max(rec(l+1,r),rec(l,r-1));
	}

	return dp[l][r];
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
     // solve();
	memset(dp,-1,sizeof(dp));
	cin>>n;
 // cout<<n<<endl;
	for(int i=0; i<n;i++)
		cin>>arr[i];
  // for(int i=0; i<n;i++)
 	// cout<<arr[i];
	cout<<rec(0,n-1);



}