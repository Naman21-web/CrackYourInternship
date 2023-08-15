int lcs(int n,int m,string s1,string s2,vector<vector<int>> &dp){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        return lcs(n,m,S1,S2,dp);
    }