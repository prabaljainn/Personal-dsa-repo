class Solution {
public:
    int n; // number of bombs
    class Ball{
    public:
        int id;
        int x; int y; int r;
        Ball(vector<int> node, int iden){
            id = iden;
            x = node[0];
            y = node[1];
            r = node[2];
        }
    };
    vector<bool> vis;
    vector<Ball> g;
    map<int,int> mp;
    int id  =1;
    
    bool inrange(Ball node, Ball node2){
        long long int x1 = node.x;
        long long int x2 = node2.x;
        long long int y1 = node.y;
        
        long long int y2 = node2.y;
        long long int r1 = node.r;
        long long int r2 = node2.r;
        long long int d1 = (x1-x2)*(x1-x2);
        long long int d2 = (y1-y2)* (y1-y2);
        long long int dis = sqrt(d1+d2);
        
        return dis <= r1+r2; 
    }
    
    
    void dfs(Ball node )
    {
        vis[node.id] = true;
        mp[id]++;
        for(auto elem: g){
            if(!vis[elem.id] and inrange(elem,node)){
                dfs(elem);
            }
        }
    }
    
    
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        n= bombs.size();
        vis.assign(n,false);
        // g.resize(n);
        for(int i=0; i<n ;i++){
            g.push_back(Ball(bombs[i],i));
        }
        for(int i=0; i<n;i++){
            if(!vis[g[i].id]){
                dfs(g[i]);
                id++;
            }
        }
        int ans = 0;
        for(auto x: mp){
            if(x.second==2)
                cout<<x.first<<" ";
            ans = max(x.second,ans);
            
        }
        return ans;
        
    }
    
    


};