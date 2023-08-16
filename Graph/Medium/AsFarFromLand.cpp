class Solution {
public:
    bool isValid(int row,int col,int n,int m,vector<vector<int>> &vis){
        if(row>=0 && col>=0 && row<n && col<m && vis[row][col]==0) return true;
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {q.push({i,j});vis[i][j]=1;};
            }
        }
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        int dist=-1;
        while(!q.empty()){
            int sz=q.size();
            dist++;
            for(int i=0;i<sz;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nrow = row+x[k];
                    int ncol = col+y[k];
                    if(isValid(nrow,ncol,n,m,vis)){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        if(dist==0) return -1;
        return dist;
    }
};