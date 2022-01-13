class Solution {
public:
    int n; int states;
    int Rank[251];
    int Parent[251];

    int find(int x){
        if(x!= Parent[x])
        {
            Parent[x] = find(Parent[x]);
        }
        return Parent[x];
    }
    void merge(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        if(x!=y){
            states--;

            if(Rank[x]<= Rank[y]){
                Rank[y]+= Rank[x];
                Parent[x] = y;
            }
            else{
                Rank[x]+= Rank[y];
                Parent[y] = x;

            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {

        n = isConnected.size();
        states = n; 
        for(int i=0; i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if((i!=j) and (isConnected[i][j]==1)){
                    cout<<i<<"    "<<j<<" ";
                    merge(i,j);
                }
            }
        }
        return states;
    }
};



