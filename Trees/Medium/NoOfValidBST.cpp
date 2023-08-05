class Solution {
public:
    int findTrees(int n,vector<int> &dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int res=0;
        for(int i=0;i<=n-1;i++){
            res += findTrees(i,dp)*findTrees(n-i-1,dp);
        } 
        return dp[n]=res;
    }
    int numTrees(int n) {
       vector<int> dp(n+1,-1);
       return findTrees(n,dp);
    }
};