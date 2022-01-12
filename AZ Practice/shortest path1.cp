// @prabaljainn
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define S second
#define F first
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n,m;
vector<ii> g[100100];
int dist[100100];
int vis[100100];

void djk(int st){
  for(int i=1;i<=n;i++){
    dist[i]=1e18;
  }
  dist[st]=0;
  priority_queue<ii,vector<ii>,greater<ii>> pq;
  pq.push({0,st});
  while(!pq.empty()){
    ii fs=pq.top();pq.pop();
    if(vis[fs.S])continue;
    vis[fs.S]=1;
    for(auto v:g[fs.S]){
      int neigh=v.F;
      int weigh=v.S;
      if(dist[neigh]>dist[fs.S]+weigh){
        dist[neigh]=dist[fs.S]+weigh;
        pq.push({dist[neigh],neigh});
      }
    }
  }
}

void solve(){
    cin>>n>>m;
    for(int i=0; i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	g[a].push_back({b,c});
    	
    	// g[b].push_back(make_pair(a,c));
    }
    djk(1);
    for(int i =1; i<=n;i++){
    	cout<<dist[i]<<" ";
    }
    cout<<endl;
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
     return 0;



}