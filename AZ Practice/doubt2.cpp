#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long 
int t[400100];
void update(int index,int l,int r,int lq,int rq,int val){
    if(r<lq || rq<l ){
        return;
    }
    if( lq<=l && r<=rq){
        t[index]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*index,l,mid,lq,rq,val);
    update(2*index+1,mid+1,r,lq,rq,val);
    // return;
}
int query(int index,int l,int r,int pos){
    if(l==r){
        return t[l];
    }
    
    int mid=(l+r)/2;
    if(mid>=pos)
    return t[index] +query(2*index,l,mid,pos);

    return t[index] + query(2*index+1,mid+1,r,pos);
}
signed main(){
    IOS;
         #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
         #endif
    int n;
    cin>>n;

    for(int i = 0; i<n; i++)
  {
    update(1,0,n-1,i,i,0);
  }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int ch;
        cin>>ch;
        if(ch==1){
            int l,r,val;
            cin>>l>>r>>val;
            update(1,0,n-1,l,r,val);
        }
        else{
            int x;
            cin>>x;
            cout<<query(1,0,n-1,x)<<"\n";
        }
    }
    return 0;
}