class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int mod=1e9+7;
        int n=s.size();
        vector<int> next(n,-1),prev(n,-1);//To store prev and next occourence of a character
        vector<vector<long long>> dp(n,vector<long long> (n));
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                prev[i]=-1;
            }
            else{
                prev[i] = mp[s[i]];
            }
            mp[s[i]]=i;
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            if(mp.find(s[i])==mp.end()){
                next[i]=-1;
            }
            else{
                next[i]=mp[s[i]];
            }
            mp[s[i]]=i;
        }
        /*
        Case1-> when s[i]!=s[j] -> ans = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
        
        Case2-> when s[i]==s[j]
                case1-> No char in bw i & j equals s[i]
                        ans = 2*dp[i+1][j-1]+2;

                case2-> 1 char in bw i & j equals s[i]
                        ans = 2*dp[i+1][j-1]+1;

                case3-> more than 1 char bw i & j equals s[i]
                        ans = 2*dp[i+1][j-1]-dp[n+1][p-1];

        */
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1){
                    dp[i][j]=2;
                }
                else{
                    if(s[i]!=s[j]){
                        dp[i][j]= (((dp[i+1][j]%mod)+(dp[i][j-1]%mod)%mod)-(dp[i+1][j-1]%mod))%mod;
                    }
                    else{
                        int n=next[i];
                        int p=prev[j];
                        if(n>p){//No char in bw which is same
                            dp[i][j] = ((2*dp[i+1][j-1])%mod+2)%mod;

                        }
                        else if(n==p){//1 char in bw which is same
                            dp[i][j] = ((2*dp[i+1][j-1])%mod+1)%mod;
                        }
                        else{//more than 1 char in bw which is same
                            dp[i][j] = ((2*dp[i+1][j-1])%mod-(dp[n+1][p-1]%mod))%mod;
                        }
                    }
                }
            }
        }
        if(dp[0][n-1]<0) dp[0][n-1] += mod;
        return dp[0][n-1];
    }
};