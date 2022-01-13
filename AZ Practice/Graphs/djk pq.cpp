
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
using ii = pair<int,int>;
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n,m;
vector<vector<pair<int,int>>> g;  // node and weight
vector<int> d;

void djk(int node){
d[node] = 0;
priority_queue<ii> pq; //distance , node
pq.push({0,node});

while(!pq.empty()){
	ii temp = pq.top(); pq.pop();
	int dis = temp.first;
	int node = temp.second;
	for(auto nodes : g[node]){
		// node.f = connnection and node.s is distance
		if( ((-dis)+nodes.second) < d[nodes.first] ){
			pq.push({-((-dis)+nodes.second), nodes.first});
			d[nodes.first] = ((-dis)+nodes.second);
		}
	}

}


}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    d.assign(n+1, 1e9);
    for(int ii = 0; ii<m; ii++){
    	int i, j, k;
    	cin>>i>>j>>k;
    	g[i].push_back(make_pair(j,k));
    }
    djk(1);
    for(int i =1 ; i<=n;i++){
    	cout<<"for node : "<<i<<" we have shortest dis  : "<<d[i]<<endl;
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

