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

int id = 1;
vector<vector<int>>g;
vector<bool> visited;
vector<int> color;
int siz[100100];

void dfs(int node){
	visited[node]= true;
	color[node] = id;
	siz[id]++;
	for(auto elem: g[node]){
		if(visited[elem] == false){
			dfs(elem);
		}
	}

}

void solve(){
	int n,m;
	int q;
	cin>>n>>m>>q;
	visited.assign(n+1, false);
	g.resize(n+1);
	color.assign(n+1,0);
	for(int i=0 ; i<m; i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
    // do dfs whose color has not been picked == -1;
	for(int i=1; i<=n; i++){
		if(visited[i]==false){
			dfs(i);
			id++;
		}
	}

	while(q--){
		int query; cin>>query;
		if(query==1){
			int x; cin>>x;
			cout<<siz[color[x]]<<endl;
		}
		else if(query==2){
			int a,b;
			cin>>a>>b;
			if(color[a]==color[b])
				cout<<"YES\n";
			else
				cout<<"NO\n";

		}
	}




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