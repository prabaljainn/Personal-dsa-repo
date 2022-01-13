#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define mp make_pair
#define F first
#define S second
using ii=pair<int,int>;
int n,m;
vector<pair<int,int>> g[100100];
int dist[100100];
bool flag = false;
void bellman(int st){
    for(int i=1;i<=n;i++){
        dist[i]=1e9;
    }
    dist[st]=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
            for(auto v:g[j]){
                if(dist[v.F]>dist[j]+v.S){
                    dist[v.F]=dist[j]+v.S;
                }
            }
        }    
    }
     for(int j=1;j<=n;j++){
            for(auto v:g[j]){
                if(dist[v.F]>dist[j]+v.S){
                    flag = true;
                }
            }
        } 

}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(mp(b,c));
        g[b].push_back(mp(a,c));
    }
    int st,en;
    cin>>st>>en;
    bellman(st);
    if(flag==false)
    cout<<dist[en]<<"\n";
    else
        cout<<"CYCLE DETECTED";
}
signed main(){
    IOS;
         #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
         #endif
    solve();
    return 0;
}