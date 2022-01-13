#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int m=1e9 +7;
#define int long long
// vector<vector<int>>g;
vector<int>g[100100];
vector<int>par;
vector<int> dep;

void dfs(int node,int parent,int depth){
      dep[node]=depth;
      par[node]=parent;

      for(auto v:g[node]){
        if(v!=parent){
        dfs(v,node,depth+1);
        }

      } 
}
void solve(){
     int n;
     cin>>n;
     // g.resize(n+1);
     for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
     }
     dep.assign(n+1,0);
     par.assign(n+1,0);
     dfs(1,0,0);
     int maxch=1;
     for(int i=2;i<=n;i++){
        if(dep[i]>dep[maxch])
        {
            maxch=i;
        }
     }
     // par.assign(n+1,0);
     dfs(maxch,0,0);
     for(int i=1;i<=n;i++){
        if(dep[i]>dep[maxch])
        {
            maxch=i;
        }
     }
     cout<<dep[maxch]<<endl;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
         #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
         #endif
    solve();

}