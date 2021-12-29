
#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
// #define int long long
#define IOS ios::sync_with_stdio(0);
using ii = pair<int,int>;
#define F first
#define S second
int mod = 1e9+7;
int n; int m;
vector<string> arr;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dis[1001][1001];

bool check(ii elem){
	int x = elem.F;
	int y = elem.S;
	if(x<0 or x>=n or y<0 or y>= m or arr[x][y]=='#')
		return false;
	return true;
}

void bfs(ii st ){
	for(int i= 0; i<n;i++){
		for(int j= 0; j<m;j++){
			dis[i][j]=10000;

		}	
	}
	dis[st.F][st.S] = 0;
	queue<ii> s;
	s.push(st);
	while(!s.empty()){
		ii temp = s.front();
		s.pop();
		int curd = dis[temp.F][temp.S];
		for(int i=0; i <4 ; i++){
			ii p = {temp.F+dx[i], temp.S+dy[i]};
			if(!check(p))continue;
			if(dis[p.F][p.S] > curd+1){
				dis[p.F][p.S] = curd+1;
				s.push(p);
				//
			}


		}

	}
	

}




void solve(){
	cin>>n>>m;
	arr.resize(n);
	ii st, en;
	for(int i=0 ; i<n;i++){
		cin>>arr[i];
		for(int j=0; j<m; j++){
			if(arr[i][j]=='S'){
				st.first = i;
				st.second =j;
			}else if(arr[i][j]=='E'){
				en.first = i;
				en.second =j;
				
			}
		}
	}
	bfs(st);
	cout<<dis[en.F][en.S]<<endl;

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



/*
    Sigma rule:
    1) never mix 0 based and 1 based indexing
    2) never use ceil function
    3) never use unordered_map||unordered_set
    4) always go with the gut feeling
    5) first sighted observations always lead to AC, not overthinking
    6) always take MOD, always :(
*/