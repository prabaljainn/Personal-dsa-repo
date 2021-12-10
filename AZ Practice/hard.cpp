#include <bits/stdc++.h>
using namespace std;
    #define OK cout << endl;
    #define f first
    #define s second
    #define endl '\n'
    #define vi vector < int >
    #define int long long
    #define IOS ios::sync_with_stdio(0);
int n;
bool visited[3][3];
int last[2] = {-1,-1};
int ans=0;

bool check(int i, int j){
    if(last[0]==-1 and last[1]==-1)
        return true;
    int pi = last[0]; int pj = last[1];
    int diffRow = abs(pi-i);
    int diffCol = abs(pj-j);
    // if((pi==i) and (diffCol ==2) and !visited[i][1]){
    // return false;
    // }

    // if((pj == j) and (diffRow ==2) and !visited[1][j]){
    //  return false;

    // } 

    // if((diffRow == diffCol) and visited[1][1]==false ){
    //  return false;
    // }
    if(diffRow==1 or diffCol==1 or visited[(pi+i)/2][(pj+j)/2])
        return true;
    return false;
}
int rec(int level){
    if(level==n){
            // cout<<last[0]<<" "<<last[1];
            // OK
        ans++;
    }
    for(int i= 0; i<3;i++){
        for(int j=0; j<3; j++){
            if(visited[i][j]==false and check(i,j)){
                    //you take it
                int a =  last[0]; int b = last[1];
                visited[i][j]= true;
                last[0]=i; last[1]= j;
                rec(level+1);
                visited[i][j]= false;
                last[0]=a; last[1]= b;
            }
        }
    }


}

signed main() {

    IOS
    cin.tie(0);
    cout.tie(0);
       #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
       #endif
    memset(visited,false, sizeof(visited));
        // int _t;cin >> _t;while (_t--) solve();
    cin>>n;
    rec(0);
    cout<<ans;




}