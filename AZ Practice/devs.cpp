#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int m=1e9 +7;
int n;
#define int long long
int add(int a ,int b)
{
    a += b;
  if (a >= m) a -= m;
  return a;
}
int dp[200200][80];
int gen(int level,int prev)
{
    if(level==0)
    {
        return 1;
    }
      if(dp[level][prev-'a']!=-1)
  {
    return dp[level][prev-'a'];
  }
    int ans=0;

    if(prev=='a')
    {
        ans=add(gen(level-1,'o'),ans);
        ans=add(gen(level-1,'i'),ans);
        ans=add(gen(level-1,'u'),ans);
    }
    else if (prev=='e')
    {
          ans=add(gen(level-1,'a'),ans);
           ans=add(gen(level-1,'i'),ans);
            ans=add(gen(level-1,'o'),ans);

    }
    else if(prev=='i')
    {
       ans=add(gen(level-1,'e'),ans);
       ans=add(gen(level-1,'o'),ans);
    }
    else if(prev=='o')
    {
          ans=add(gen(level-1,'e'),ans);
       ans=add(gen(level-1,'o'),ans);
    }
    else
    {
         ans=add(gen(level-1,'i'),ans);
       ans=add(gen(level-1,'o'),ans);
    }
    return dp[level][prev-'a']=ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

      #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
   #endif
     int t;
     cin>>t;
    memset(dp,-1,sizeof(dp));
     while(t--)
     {
     
      cin>>n;
      vector<char>ch;
      ch.push_back('a');
      ch.push_back('e');
      ch.push_back('i');
      ch.push_back('o');
      ch.push_back('u');
      int x =0;


      for(auto c:ch){
      x=add(gen(n-1,c),x);}  
      cout<<x<<endl;

    }
}