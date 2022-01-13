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
vector<vi>g;
vi dep;
vi par;
void dfs(int node, int parent, int depth ){
	par[node] = parent;
	dep[node] = depth;
	for(auto elem : g[node]){
		if(elem != parent){
			dfs(elem,node,depth+1);
		}
	}

}


void solve(){
	int n;
	cin>>n;
	dep.assign(n+2,0);
	par.assign(n+2,0);
	g.resize(n+1);
	for(int i=0; i<n-1;i++){
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
    // do dfs from a random point
    dfs(1,0,0); // node parent depth

    // choose the max dep point
    int maxDepth = 1;
    for(int i=1; i<=n;i++){
    	if(dep[i] > dep[maxDepth] )
    		maxDepth = i;
    }

    // run dfs from max depth

    dfs(maxDepth,0,0);
    for(int i=1; i<=n;i++){
    	if(dep[i] > dep[maxDepth] )
    		maxDepth = i;
    }

    cout<<dep[maxDepth];

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