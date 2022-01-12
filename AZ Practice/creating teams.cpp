// @prabaljainn
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n,m;
vector<vector<int>>g;
bool flag  = false;
vector<int> col;

void dfs(int node, int color){
	
	col[node] = color;
	for(auto ele: g[node]){
		if(col[ele]==-1)
			dfs(ele,1-color);
		else if(col[ele]== color){
			flag  = true;
			break;

		}
		
	}
}

void solve(){
	cin>>n>>m;
	col.assign(n+1,-1);

	g.resize(n+1);
	for(int i=0; i<m;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);

	}

	for(int i=1; i<=n; i++){
		if(col[i]==-1)
			dfs(i,0);
	}

	if(flag)
		cout<<"NO\n";
	else 
		cout<<"YES\n";
}

signed main() {
 //cout<<fixed<<setprecision(15)<<ans<<endl;
	IOS
	cin.tie(0);
	cout.tie(0);
   #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   #endif
    // int _t;cin >> _t;while (_t--) 
	solve();



}