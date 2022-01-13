// https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define f first
#define s second
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
string s1; int n, m; 
string s2;
int dp[3001][3001];

int rec(int l, int r){
	//base case
	if(l==n or r==m)
		return 0;
	//pruning

	// cache check
	if(dp[l][r] != -1)
		return dp[l][r];

	if(s1[l]==s2[r])
		return dp[l][r] =  1 + rec(l+1, r+1);

	return dp[l][r] = max(rec(l+1,r), rec(l,r+1));


}
vector<char> ans;
void generate(int l, int r){
	if(l==n or r==m)
		return;

	if(s1[l]==s2[r])
	{
		ans.push_back(s2[r]);

		generate(l+1,r+1);
	}
	else{
		if(rec(l+1,r) > rec(l,r+1) )
		{
			generate(l+1,r);
		}
		else
	{
		generate (l,r+1);
	}
}

}

signed main() {

	IOS
	cin.tie(0);
	cout.tie(0);
   #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   #endif
	memset(dp,-1,sizeof(dp));
	cin>>s1>>s2;
	n = s1.size();
	m = s2.size();
    // int _t;cin >> _t;while (_t--) solve();
     // solve();
	// cout<<rec(0,0)<<endl;
	generate(0,0);

	for(char x : ans)
		cout<<x;


}