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
int rec(int level){  // -> 0 based indexing, returns LIS at the level 
	//base case if level ==0 that is in the case [1] return 1 length
	if(level ==0)
		return 1;
	//dp check
	if(dp[level]!= -1)
		return dp[level];
	int ans =1;

	for(int i=0; i<level; i++){
		if(arr[i]<arr[level]){
			ans = max(ans, 1+ rec(i));
		}
	}
	//save and return 
	return dp[level]= ans;
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