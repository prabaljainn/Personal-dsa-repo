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
char g[1010][1010];
bool visited[1010][1010];
int n, m; 
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

bool check(pair<int,int> node){
	int x = node.first;
	int y = node.second;

	if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='#') return 0;
	else return 1;
}

void dfs(pair<int,int> node){
	int xx = node.first;
	int yy = node.second;
	visited[xx][yy] = true;
	for(int i=0 ; i<4; i++){
		pair<int,int> neigh = {xx+ dx[i], yy+dy[i]};
		if(!visited[neigh.first][neigh.second] and check(neigh) ){
			dfs(neigh);
		}
	}
}

void solve(){
	cin>>n>>m;
	for(int i=0 ;i<n; i++){
		for(int j=0; j<m; j++){
			cin>>g[i][j];
			visited[i][j] = false;
		}}

		int cnt =0 ; 
		for(int i=0 ;i<n; i++){
			for(int j=0; j<m; j++){
				if(g[i][j]!='#' and !visited[i][j])
				{
					cnt++;
					pair<int,int> node = {i,j};
					dfs(node);

				}
			}
		}

		cout<<cnt<<endl;    
	}

	signed main(){
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