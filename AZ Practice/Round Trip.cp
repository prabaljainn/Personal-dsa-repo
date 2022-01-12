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
bool cycle = false;
vector<vector<int>>g;
vector<int> col;
vector<int> parent;

void dfs(int node, int par){
	parent[node] = par;
	col[node]=2;
	for(auto nod : g[node]){
		if(nod==par) continue;
		if(col[nod]==0){
			dfs(nod,node);
		// foreward edge
		}
		else if(col[nod]==2){
			cycle = true;
			//back edge
		}
		else{
			// cross edge
		}
	}
	col[node] =3;

}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0; i<m;i++){
		int a, b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	col.assign(n+1, 0);
	parent.assign(n+1, -1);
	for(int i=1; i<n ; i++){
		if(col[i]==0){
			dfs(i,0);
		}
	}
	if(cycle)
		cout<<"YES\n";
	else
		cout<<"NO\n";


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