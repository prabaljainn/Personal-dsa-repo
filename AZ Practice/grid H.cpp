#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int arr[1003][1003];
int n,m;
int mod = 1e9+7;
int dp[1003][1003];
// you have to reach n-1, m-1 from any point i,j 
// dp(i,j) ==> # nu of ways to reach from i,j to n-1, m-1
int rec(int i, int j){
  //base case
  if(arr[i][j] ==1)
    return 0;
    
    if(i==n-1 and j==m-1)
    return 1;
  //restriction
  
  //pruning
  if(i>n-1 or j > m-1)
    return 0;

  //dp check 
  if(dp[i][j] != -1)
    return dp[i][j];

  //computation and save
  // return dp[i][j] = (rec(i+1, j)%mod + rec(i, j+1)%mod)%mod;


  int ans = 0;
  //compute
  if(i+1 <= n-1)
    ans = (ans%mod + rec(i+1,j)%mod)%mod;
  if(j+1 <= m-1)

  ans= (ans%mod + rec(i,j+1)%mod)%mod;

  return dp[i][j] = ans;

}


void solve(){
 cin>>n>>m;   
 for(int i=0; i<n;i++){
  for(int j=0; j<m;j++){
    cin>>arr[i][j];
    dp[i][j] = -1;
  }
 }
 // memset(dp,-1,sizeof(dp));
 cout<<rec(0,0)%mod<<endl;

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