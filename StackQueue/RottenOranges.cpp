class Solution {
public:
    void bfs(int n,int m,vector<vector<int>> &grid,vector<int> &x,vector<int> &y,int &time){
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t = q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+x[i];
                int ncol=col+y[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        vector<int> x = {1,0,-1,0};
        vector<int> y = {0,1,0,-1};
        
        bfs(n,m,grid,x,y,time);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};