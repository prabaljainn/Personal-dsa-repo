#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define f first
#define s second
#define endl '\n'
#define vi vector < intd >
#define intd double
#define IOS ios::sync_with_stdio(0);
intd n;
intd arr[3001];
vector<vector<double>> dp(3000,vector<double>(3000,-1));

intd rec(int level, int heads){
 if(level==n ){
  if(heads> (n-heads))
    return 1;
  return 0;
}

if(dp[level][heads]!= -1)
  return dp[level][heads];
intd ans = 1.0;
ans= ( arr[level]*rec(level+1,heads+1)) + (((1-arr[level])*rec(level+1,heads)));

return dp[level][heads] =ans;

}

signed main() {

 IOS
 cin.tie(0);
 cout.tie(0);
   #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
   #endif

 cin>>n;
 for(int i=0; i<(int)n; i++)
  cin>>arr[i];
cout<<rec(0,0);






}