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
int n,m; int id= 0;
vector<vector<int>> g;
vector<bool> vis;
void dfs(int node){
	vis[node]=true;
	for(auto elem : g[node]){
		if(!vis[elem])
			dfs(elem);
	}
}

void solve(){

	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,false);
	for(int i=0; i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);}

	for(int i=1; i<=n;i++){
		if(!vis[i])
			{dfs(i);
				id++;
			}
		
	}
	cout<<id-1<<endl;


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