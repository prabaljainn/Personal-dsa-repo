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
int mod = 1e9+7;int n;
char arr[1001];
int is_palin[1001][1001];
int dp[1001];
bool isp(int l, int r){
	//base case 
	// if(l==r)
	// 	return true;
	if(l>=r)
		return true;

	//dp check
		if(is_palin[l][r]!= -1)
			return is_palin[l][r];
	//compuatation
	if(arr[l]==arr[r])
		return is_palin[l][r] =  isp(l+1,r-1);
	else 
		return is_palin[l][r] = false;
}
int rec(int level) // returns the minimum number of cuts required to cut seq from 0 - level into palindromes
{
	// base case
	if(level==-1)
		return -1 ;
	if(level==0)
		return 0 ;


	//dp check
	if(dp[level]!= -1)
		return dp[level];

	// compuatation [use isp(l,r) to find if [L,R] is palindrome or not]
	int ans = 1e9;
	for(int i= 0; i<=level; i++){
		if(isp(i,level)){
			// cout<<"i 		"<<i<<"level	"<<level<<endl;
			ans = min(ans,1+rec(i-1));
		}
	}
	return dp[level] = ans;

}

void solve(){
	memset(is_palin,-1,sizeof(is_palin));
		memset(dp,-1,sizeof(dp));

    cin>>n;
    for(int i =0 ; i<n; i++)
    	cin>>arr[i];
    // cout<<isp(0,2)<<endl;cout<<isp(0,4)<<endl;
    cout<<rec(n-1)<<endl;
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