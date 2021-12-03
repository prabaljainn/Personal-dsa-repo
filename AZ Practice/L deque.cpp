
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define f first
#define s second
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int n;
int arr[3002];
int dp[3002][3002];
int rec(int l , int r){
	// base check

	if(l==r){
		return arr[l];
	}

	// pruning 
	//dp check
	if(dp[l][r] != -1)
		return dp[l][r];

	///compuataion
	dp[l][r] = max((arr[l] - rec(l+1,r)) ,(arr[r] - rec(l,r-1)));

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
 for(int i=0; i<n;i++)
 	cin>>arr[i];
 cout<<rec(0,n-1);




}