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
int n,m,q;
vector<vector<ii>>g;
bool visited[100100];
int dist[505][505];



void floyd(){


	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dist[i][j]=1e18;
		}
	}

	for(int i=0; i<m; i++){
		int a,b,c;cin>>a>>b>>c;
		dist[a][b]=dist[b][a]= min(dist[a][b],c);
		// dist[a][b]=dist[b][a]= c;


	}


	
	
	for(int k=1; k<=n;k++){
		for(int i=1; i<=n;i++){
			for(int j=1; j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}

	while(q--)
	{
		int a,b;
		cin>>a>>b;
		int dis = dist[a][b];
		if(dis==1e18)
			dis= -1;
		cout<<dis<<endl;

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
	floyd();



}