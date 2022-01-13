
 #include <bits/stdc++.h>
using namespace std;
 #define OK cout << endl;
 #define f first
 #define s second
 #define endl '\n'
 #define vi vector < int >
 #define int long long
 #define IOS ios::sync_with_stdio(0);
int n,k;
int arr[100100];
int dp[100100];

int rec(int left)
{
  //base case
  if(left== 0)
    return 0;
  //dp check
  if(dp[left] != -1)
    return dp[left];

//compuatation
  int ans = 0;
  for(int i=0; i<n; i++){
    if(arr[i] <= left and rec(left-arr[i])==0)
     { ans = 1;
       break;}
     }

  // return and save
     return dp[left]= ans;
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
    cin>>n>>k;
    for(int i=0; i<n;i++){
      cin>>arr[i];
    }
    if(rec(k)==1)
      cout<<"First";
    else
      cout<<"Second";



  } 