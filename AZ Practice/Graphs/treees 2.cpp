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
vector<int> g[100100];
int dep[1001];
int subtree_size[100100];
int par[1001];
int childs[1001];
bool is_leaf[1001];
void dfs(int node, int parent , int depth)
{
	dep[node]  =depth;
	par[node] = parent;
	childs[node] = 0;
	subtree_size[node] = 1;

	for(auto elem : g[node]){

		if(elem != parent){
			childs[node]++;
			dfs(elem,node,depth+1);

			subtree_size[node]+= subtree_size[elem];
		}

	}

	if(childs[node]==0)
	{
		is_leaf[node]  = 1;
	}


}


void solve(){
	
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