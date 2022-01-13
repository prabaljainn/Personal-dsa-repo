// @prabaljainn
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);

int mod = 1e9+7;
int n,m;
vector<vector<ii>>g;
int d[100100];
bool visited[100100];


void Dijkstra(int st){
	for(int i=1; i<= n; i++){
		d[i] =1000;
		visited[i] = false;
	}

	d[st] = 0;
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		ii node = pq.top(); pq.pop();
		// <distance,node>
		if(visited[node.second]) continue;
		visited[node.second] =true;
		for(auto element : g[node.second]){
			int neigh = element.first;
			int weight = element.second;
			if( (d[neigh]) > (d[node.second] + weight )){
				d[neigh]  = d[node.second] +weight;
				pq.push(make_pair(d[neigh],neigh));
			}
		}

	}
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0; i<m; i++){

			int a,b,c;cin>>a>>b>>c;
		g[a].push_back({b,c});
	}

	Dijkstra(1); // djk on node 1 saves the shotest path distance from node 1 to every othe node in graph 

	for(int i=1 ; i<= n; i++){
		cout<<i<<" "<<d[i]<<endl;
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