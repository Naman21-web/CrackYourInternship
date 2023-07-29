class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            int val = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            // vis[row][col]=1;
            for(int k=0;k<4;k++){
                int nrow = row+x[k];
                int ncol = col+y[k];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol]){
                    int nval = max(val,grid[nrow][ncol]);
                    if(nrow==n-1 && ncol==n-1) return nval;
                    vis[nrow][ncol]=1;
                    pq.push({nval,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};