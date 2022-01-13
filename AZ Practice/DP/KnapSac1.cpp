// https://atcoder.jp/contests/dp/tasks/dp_d


#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define f first
#define s second
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int n, w;
int dp[101][100100];
int weight[101];
int points[101];

int rec(int level, int wei){
  // pruning //base case
  if(level==n){
    return 0;
  }
  

  //dp check 
  if(dp[level][wei] != -1)
    return dp[level][wei];
  int ans = -1e18;
  if(wei + weight[level] <= w)
    ans = rec(level+1, wei+weight[level])+ points[level];
  ans = max(ans,rec(level+1,wei));

  

  //save;
  return dp[level][wei] = ans;
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
 cin>>n>>w;
 for(int i=0 ; i<n;i++){
  cin>>weight[i]>>points[i];
}
cout<<rec(0,0);




 }
