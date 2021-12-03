/*
    Sigma rule 101:
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
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n,m;
char arr[1001][1001];
int dp[1001][1001];

int rec(int i, int j){

	if(arr[i][j]=='#')
		return 0;

	if(i>n-1 or j> m-1){
		return 0;
		}
	if(i==n-1 and j==m-1)
			return 1;



	// dp check 
	if(dp[i][j]!= -1)
		return dp[i][j];

	int ans = 0;
	//compute
	if(i+1 <= n-1)
	ans = (ans%mod + rec(i+1,j)%mod)%mod;
	if(j+1 <= m-1)

	ans= (ans%mod + rec(i,j+1)%mod)%mod;

	return dp[i][j] = ans;



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
cin>>n>>m;
memset(dp,-1,sizeof(dp));
for(int i=0; i<n;i++){
	for(int j=0; j<m;j++)
		cin>>arr[i][j];
}
// cout<<arr[n-1][m-1];
cout<<rec(0,0)%mod;


}