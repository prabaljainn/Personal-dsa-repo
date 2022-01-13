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
int Rank[10005];
int parent[10005];

int find(int a){
	if(parent[a]!= a){
		parent[a] = find(parent[a]);
	}
	return parent[a];
}
void merge(int a, int b){
	if(a!=b){
		int x = find(a);
		int y = find(b);
		set_size--;
		if(Rank[x]<= Rank[y]){
			Rank[y]+= Rank[x];
			parent[x]= find(y);
		}

		else{
			Rank[x]+= Rank[y];
			parent[y]= find(x);
		}


	}
}


void solve(){
	int n,q;
	cin>>n>>q;
	set_size=n;
	for(int i=0; i<n;i++){
		parent[i] = i;
		Rank[i] = 1;
	}
	while(q--){
		int x; cin>>x;
		if(x==0){
			int a, b;
			cin>>a>>b;
			merge(a,b);
    			// merge a and b
		}
		else{
    		// find a and b are of same component or not
			int a, b;
			cin>>a>>b;
			bool flag = find(a)==find(b);
			cout<<flag<<endl;
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