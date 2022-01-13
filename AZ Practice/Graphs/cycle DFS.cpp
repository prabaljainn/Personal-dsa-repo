// cycle DFS

#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n, m; 
int val =0;
vector<vector<int>> g;
vector<int> color;
vector<int> parent;
vector<int> any_cycle;
bool is_cycle=false;
void DFS(int node,int par){
	color[node] =2;
	parent[node] = par;
	for(auto ele: g[node] )
	{
	if(color[ele]==1) // node ele is forward edgge
		DFS(ele,node);
	
	else if(color[ele]==2) // node ele is back edge
		{val++;
			if(is_cycle==0){
				int temp  = node;
				while(temp!= ele){
					any_cycle.push_back(temp);
					temp = parent[temp];
				}
				any_cycle.push_back(temp);
				reverse(any_cycle.begin(),any_cycle.end());
			}

			is_cycle=true;
		}
	}
color[node]=3; // marked it as done
}
void solve(){
	cin>>n>>m;
	color.assign(n+1, 1);parent.assign(n+1, 1);
	g.resize(n+1);
	for(int i=0; i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
	}
	DFS(1,0);
	cout<<val<<endl;
	for(int x: any_cycle)
		cout<<x<<" ";
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

