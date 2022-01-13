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
struct Edge{
	int x,y,w;
};

void Bellman(){
	cin>>n>>m;
	Edge g[m];
	for(int i=0; i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[i].x = a;
		g[i].y = b;
		g[i].w = c;
	}
	vector<int> dist(n+1,1e18);
	dist[1]=0;


// now we have our edge list ready

// realax every edge for n-1 times
	for(int i =0 ; i<n-1; i++){
		for(int j=0; j<m;j++){
			if((dist[g[j].x] <1e18) and dist[g[j].x] + g[j].w<dist[g[j].y])
				{dist[g[j].y] = min(dist[g[j].x] + g[j].w,dist[g[j].y]) ;

			} // realAx

		}
	}
// so far we have relaxed the edges now if any cycle is there one more realx will change that again
	int flag = false;

	for(int j=0; j<m;j++){
		if(dist[g[j].x] + g[j].w<dist[g[j].y])
		{
			// dist[g[j].y] = min(dist[g[j].x] + g[j].w,dist[g[j].y]);
			flag = true;break;} // realAx

		}
		int ans = -1;
		if(flag==false){
			ans = dist[n];
		}
		cout<<ans;
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
		Bellman();
	}