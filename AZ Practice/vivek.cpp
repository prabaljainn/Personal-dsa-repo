#include"bits/stdc++.h"
using namespace std;
#define int long long
#define mod 1000000007

int n,m,q;
vector<vector<int> >g;
vector<int> col;
int color;

int dfs(int node,int color){
    col[node]=color;
    for(auto v:g[node]){
        if(col[v]==0){
            dfs(v,color);
        }
    }
}

int checksize(int node){
	int ans=0;
    int x = col[node];
    for (int i = 1; i <=n; i++)
    {
        if(col[i]==x){
            ans++;
        }

    }
    cout<<ans<<endl;
}

int checklink(int node1,int node2){
    if(col[node1]==col[node2]){
        cout<<"YES"<<endl;
    }
    else{
         cout<<"NO"<<endl;
    }
}

void solve(){

cin>>n>>m>>q;
g.clear();
g.resize(n+1);
col.assign(n+1,0);
for (int i = 0; i < m; i++)
{
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
//to assign the same color of connected graph//
  color =1;
for (int i = 1; i <=n; i++)
{
    if(col[i]==0){
    dfs(i,color);
    color++;
    }
}

map<int,int> m;
for(int i= 1; i<=n; i++){
	m[col[i]]++;

}


for (int i = 0; i < q; i++)
{
    int p;
    cin>>p;
   if(p==1){
       int q;
       cin>>q;
       cout<<m[col[q]]<<endl;
   }
   else if(p==2){
       int u,v;
       cin>>u>>v;
       checklink(u,v);
   }
}




}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	 #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
        solve();
  

}