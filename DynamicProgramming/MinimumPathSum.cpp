class Solution {
public:
    // int minpath(int i,int j,vector<vector<int>> &grid){
    //     if(i<0 || j<0) return 1e9;
    //     if(i==0 && j==0)return grid[0][0];
    //     return grid[i][j]+min(minpath(i-1,j,grid),minpath(i,j-1,grid));
    // }

    // int minpath(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 1e9;
    //     if(i==0 && j==0)return grid[0][0];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     return dp[i][j]=grid[i][j]+min(minpath(i-1,j,grid,dp),minpath(i,j-1,grid,dp));
    // }

    // int minpath(int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp){
    //     dp[0][0]=grid[0][0];
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(i==0 && j==0) continue;
    //             int right = 1e9,down=1e9;
    //             if(i>0) down = dp[i-1][j];
    //             if(j>0) right = dp[i][j-1];
    //             dp[i][j] = grid[i][j] + min(right,down);
    //         }
    //     }
    //     return dp[n-1][m-1];
    // }

    int minpath(int n,int m,vector<vector<int>> &grid){
        vector<int> prev(m,0),curr(m,0);
        curr[0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int right = 1e9,down=1e9;
                if(i>0) down = prev[j];
                if(j>0) right = curr[j-1];
                curr[j] = grid[i][j] + min(right,down);
            }
            prev=curr;
        }
        return curr[m-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,0));
        return minpath(n,m,grid);
    }
};