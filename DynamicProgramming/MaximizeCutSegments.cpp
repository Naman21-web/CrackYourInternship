// int getMax(int n,int x,int y,int z,vector<int> &dp){
    //     // if(n<x && n<y && n<z) return 0;
    //     if(n==0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int ans=0;
    //     if(n>=x) ans = max(ans,1+getMax(n-x,x,y,z,dp));
    //     if(n>=y) ans = max(ans,1+getMax(n-y,x,y,z,dp));
    //     if(n>=z) ans = max(ans,1+getMax(n-z,x,y,z,dp));
    //     if(ans==0) return dp[n]=-1;
    //     return dp[n]=ans;
    // }
    
    int getMax(int n,int x,int y,int z,vector<int> &dp){
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int ans=0;
            if(i>=x) ans = max(ans,1+dp[i-x]);
            if(i>=y) ans = max(ans,1+dp[i-y]);
            if(i>=z) ans = max(ans,1+dp[i-z]);
            if(ans==0) dp[i]=-1;
            else dp[i] = ans;
        }
        if(dp[n]==-1) return 0;
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,0);
        return getMax(n,x,y,z,dp);
        // if(dp[n]==-1) return 0;
        // return dp[n];
    }