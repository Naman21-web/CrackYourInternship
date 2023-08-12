class Solution {
public:
    // int unique(int i,int j,vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;
    //     if(i==0 && j==0) return 1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int left = unique(i,j-1,dp);
    //     int up = unique(i-1,j,dp);
    //     return dp[i][j]=up+left;
    // }

    // int unique(int n,int m,vector<vector<int>> &dp){
    //     dp[0][0]=1;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 && j==0)continue;
    //             int up=0,left=0;
    //             if(i>0) up = dp[i-1][j];
    //             if(j>0) left = dp[i][j-1];
    //             dp[i][j] = up+left;
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    int unique(int n,int m){
        vector<int> curr(n+1,0),prev(n+1,0);
        curr[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up=0,left=0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
                curr[j] = up+left;
            }
            prev=curr;
        }
        return prev[n-1];
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int> (n,0));
        // return unique(n,m,dp);
        return unique(n,m);
    }
};