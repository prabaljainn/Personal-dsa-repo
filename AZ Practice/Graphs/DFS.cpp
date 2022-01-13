
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n,m; //nodes and edges
vector<vector<int>>g1;  // graph 1 vector of vectors
// vector<int> g2[100100]; // geaph 2 vector of arrays
vector<int> vis;
int nodel;


void DFS(int node){
vis[node] =1;
nodel++;
for(auto vec: g1[node]){
  if(!vis[vec])
    DFS(vec);
}
}

// 5 3 nodes edges
// 1 2 edge 
// 2 3 edge 
// 4 5 edge 

v
oid solve(){
  cin>>n>>m;
  g1.clear(); // clear last graph
  g1.resize(n+1); // nodes are [1-n]
  vis.assign(n+1,0);
  for(int i= 0; i<m ;i++){
    int a, b; 
    cin>>a>>b;
    g1[a].push_back(b);
    g1[b].push_back(a);
  }
  for(int i=1 ; i<n+1; i++){
    if(!vis[i]){
      nodel=0;
      DFS(i);
      cout<<nodel<<endl;
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


// 3 types to form Graphs
// adjacency list , edge list , matrix-> most famous is ad list of all questions
// 