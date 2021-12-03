
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define f first
#define s second
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int arr[2021];
int dp[2021][2021];
bool done[2021][2021];
int n;

int rec(int l, int r){
	if(l==r){
		return arr[l];
	}

	if(done[l][r]){
		return dp[l][r];
	}
	done[l][r]= true;
	dp[l][r] = max(arr[l] - rec(l+1,r), arr[r]-rec(l,r-1) );

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
// memset(done,false,sizeof(done));
cin>>n;
	for(int i=0; i<n;i++)
	cin>>arr[i];

	for(int i= 0; i<n;i++)
		for(int j=0; j<n;j++)
		done[i][j] = false;
cout<<rec(0,n-1);


}