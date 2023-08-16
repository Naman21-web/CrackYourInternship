class Solution {
public:
    void bfs(int i,int j,vector<vector<char>> &grid,vector<int> &x,vector<int> &y,int n,int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                    int newr = row+x[k];
                    int newc = col+y[k];
                if(newr>=0 && newc>=0 && newr<n && newc<m && grid[newr][newc]=='1'){
                    grid[newr][newc]='0';
                    q.push({newr,newc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<int> x = {1,-1,0,0};
        vector<int> y = {0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    cnt++;
                    bfs(i,j,grid,x,y,n,m);
                }
            }
        }
        return cnt;
    }
};