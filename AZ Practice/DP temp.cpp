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
int dp[1001];
int n;
int rec(int level){
  if(level ==n)
    return 0;

  if(dp[level]!= -1)
    return dp[level];

  int ans = 1e9;
  
  if(level*2 <= n)
    ans  =  min (ans,2+ rec(level*2));
  
  if (level+1 <= n)
    ans = min(ans, 1+ rec(level+1));

  return dp[level]= ans;

}

void solve(){
  cin>>n;
  memset(dp,-1,sizeof(dp));
  cout<<(1,0)<<endl;
}

signed main() {

 IOS
 cin.tie(0);
 cout.tie(0);
   #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
   #endif
    int _t;cin >> _t;while (_t--) solve();
     // solve();



}