
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
// vector<vector<int>> g;
vector<int> g[100100];
int dep[1001];
int par[1001];
int subtree_len[1001];
bool is_leaf[1001];
void dfs(int node, int parent , int depth)
{
  dep[node]  =depth;
  par[node] = parent;
  subtree_len[node] = 1;

  for(auto elem : g[node]){

    if(elem != parent){
      dfs(elem,node,depth+1);
      subtree_len[node]++;
    }

  }

  if(subtree_len[node]==1)
  {
    is_leaf[node]  = 1;
  }


}

void solve(){
     int n;
     cin>>n;
  for(int i=1; i<n; i++){

    int a,b; 
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,0,0);
  cout<<dep[2]<<endl;
  cout<<subtree_len[1]<<endl;
  cout<<is_leaf[1]<<endl;
  cout<<is_leaf[2]<<endl;
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
