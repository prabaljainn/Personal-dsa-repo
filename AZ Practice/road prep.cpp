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
int set_size;
int n,m;
int parent[100100];
int Rank[100100];
int find(int x){
	if(parent[x]!=x)
		parent[x] = find(parent[x]);
	
	return parent[x] ;
}
void merge(int a,int b){
	if(a!=b){
		set_size--;
		int x = find(a);
		int y = find(b);
		if(Rank[x]<= Rank[y]){
			Rank[y]+=Rank[x];
			parent[x] = y;
		}
		else{
			Rank[x]+= Rank[y];
			parent[y] = x;

		}
	}
}


void solve(){
	cin>>n>>m;
	pair<int,pair<int,int>> e[m];
	set_size = n;

	for(int i=1; i<=n;i++){
		Rank[i] = 1;
		parent[i] = i;
	}

	for(int i=0; i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[i].first = c;
		e[i].second.first = a;
		e[i].second.second =b;
	}
	int mstCost=0;
	int numberofEdges = 0;

	sort(e,e+m);
	for(int i=0; i<m;i++){
		auto element = e[i];
		int cost = element.first;
		int a = element.second.first;
		int b = element.second.second;
		if(find(a)!= find(b)){
			merge(a,b);
			mstCost+=cost;
			numberofEdges++;
		}
    	// find if a and b are not connected then connect them; increase cost and edges so far
	}

	if(set_size==1)
		cout<<mstCost<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
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