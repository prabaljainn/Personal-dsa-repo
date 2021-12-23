#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 100;
int pre[502];int arr[502];
int n; int dp[502][502];
int Asum(int L, int R){
if(L ==0)
	return pre[R];
return pre[R]- pre[L-1];

}

int rec(int l, int r){
if(l==r)
	return 0;




if(dp[l][r]==-1){
        int ans = 1e9;
        int tot = 0;
        for(int i=l;i<=r;i++){
            tot+=arr[i];
        }
        int sum = 0;
        for(int mid=l;mid<r;mid++){
            sum += arr[mid];
            ans = min(ans,rec(l,mid)+rec(mid+1,r)+ ((sum)%100)*((tot-sum)%100));
        }
        dp[l][r]=ans;
    }
    cout<<"For ans ==    "<<dp[l][r]<<"   l:  "<<l<<"         r:   "<<r<<endl;

    return dp[l][r];
}


void solve(){
	memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0; i<n; i++)
    	cin>>arr[i];
    pre[0] = arr[0]%mod;

    for(int i= 1; i<n;i++){
    	pre[i] = (arr[i]%mod+ pre[i-1]%mod)%mod;
    }

        // cout<<Asum(0,2)<<"	"<<Asum(2,2);
    cout<<rec(0,n-1)<<endl;
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