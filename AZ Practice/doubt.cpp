class Solution {
public:
    int m,n;
    int dp[20][20];
    int vis[20][20];
    int rec(int i, int j,vector<vector<int>> grid ){
        if(grid[i][j]==2)
            return 1;
        if(grid[i][j]==-1)
            return 0;
        //dp check
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans =0;
        // up 
        if(i-1 <= m-1 and i-1 >=0 and vis[i-1][j] != 1)
        {
            ans += rec(i-1,j,grid);
        }
        // down
        if(i+1 <= m-1 and vis[i+1][j] != 1)
        {
            ans += rec(i+1,j,grid);
        }
            
            //right
        if(j+1 <= n-1 and vis[i][j+1] != 1)
        {
            ans += rec(i,j+1,grid);
        }
        if(j-1 <= n-1 and j-1>=0 and vis[i][j-1] != 1)
        {
            ans += rec(i,j-1,grid);
        }
        //save and return
        
        return dp[i][j] = ans;
    
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(vis,-1,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        m = grid.size(); int I,J;
        n = grid[0].size();
        for(int i =0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    I =i;
                    J =j;
                }
            }
        }
        vis[I][J] = 1;
        return rec(I,J,grid);
    }
};