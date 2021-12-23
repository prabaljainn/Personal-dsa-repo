#include <bits/stdc++.h>
using namespace std;
#define OK cout << endl;
//vector<vector<double>> dp(3000,vector<double>(3000,-1));
#define endl '\n'
#define vi vector < int >
#define int long long
#define IOS ios::sync_with_stdio(0);
int mod = 1e9+7;
void solve(){
	int n;// --> atmost how much your window can reach, mainly array size
    int head = -1; int tail = 0; //---> begin with these values when head is behind of tail that is no elem in the window


    // Information to keep your dynamic window valid

    while(tail<n) // check if you are in the range or not
    {
    	while(head+1 <n and (some other conditions of your window)){
    		// increase head
    		// update info
    	}

    	// update ans 
    	// where at any time (head-tail+1) is the size of window

    	if(tail<= head){
    		tail++
    		//change info
    	}
    	else{
    		// tail++
    		// head = tail-1;
    	}
    }
    // return your ans
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


