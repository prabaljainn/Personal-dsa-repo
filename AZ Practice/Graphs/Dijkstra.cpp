
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
int n,m;
vector<vector<pair<int,int>>> g;  // node and weight
vector<int> d;

void djk(int node){
	d[node] =0;
	// queue<int> q;
	// q.push(node);
	set<pair<int,int>>s;
	s.insert({node,0});
	
	while(!s.empty()){
		auto it = s.begin();
		int temp = it->first;
		s.erase(s.begin());
		for(auto elem: g[temp]){
			int conn = elem.first;
			int we = elem.second;
			if(d[temp]+we < d[conn]){
				d[conn]= d[temp]+we;
				s.erase({conn,d[conn]});
				// q.push(conn);
				s.insert({conn,d[temp]+we});
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
	cout<<d[5]<<endl;

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

