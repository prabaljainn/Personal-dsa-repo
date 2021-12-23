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

int binary_expo(int a, int b){
	// bi_mod is mod for binary_expo func
    int bi_mod = mod;
    int ans=1;

    while(b){
        if(b%2!=0){
            ans=(ans%bi_mod*a%bi_mod)%bi_mod;

        }
        a = (a%bi_mod*a%bi_mod)%bi_mod;
        b/=2;

    }
    return ans%bi_mod;
}

void solve(){
    int n;
    cin>>n;
    if(n%2==1)
    {
    	cout<<-1<<endl;
    }
    else{
    	int t = n/2;
    	string final ;
    	for(int i=0; i<t;i++){
    		final+= "10";
    	}
    	
    	cout<<final<<endl;

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
    int _t;cin >> _t;while (_t--) solve();
     // solve();



}