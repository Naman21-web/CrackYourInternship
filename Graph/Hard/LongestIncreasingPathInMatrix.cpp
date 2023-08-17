class Solution {
public:
    vector<int> x = {1,-1,0,0};
    vector<int> y = {0,0,1,-1};
    int dfs(int row,int col,vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &dp){
        if(dp[row][col]!=-1) return dp[row][col];
        int ans=0;
        int val = matrix[row][col];
        for(int k=0;k<4;k++){
            int nrow = row + x[k];
            int ncol = col + y[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && matrix[nrow][ncol]>val){
                ans = max(ans,1+dfs(nrow,ncol,matrix,n,m,dp));
            }
        }
        return dp[row][col]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,1+dfs(i,j,matrix,n,m,dp));
            }
        }
        return ans;
    }
};