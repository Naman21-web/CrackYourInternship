class Solution {
public:
    // int knight(int i,unordered_map<int,vector<int>> &mp,int j,int n){
    //     if(i==n) return 1;
    //     int sum=0;
    //     for(int k=0;k<mp[j].size();k++){
    //         sum += knight(i+1,mp,mp[j][k],n);
    //     }
    //     return sum;
    // }
    // int knight(int i,unordered_map<int,vector<int>> &mp,int j,int n,vector<vector<int>> &dp){
    //     int m = 1e9+7;
    //     if(j==5 && i!=n) return 0;
    //     if(i==n) return 1;
    //     int sum=0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     for(int k=0;k<mp[j].size();k++){
    //         sum += (knight(i+1,mp,mp[j][k],n,dp)%m);
    //         sum = sum%m;
    //     }
    //     return dp[i][j]=(sum%m);
    // }
    void knight(unordered_map<int,vector<int>> &mp,int n,vector<vector<long long int>> &dp){
        int m = 1e9+7;
        for(int i=0;i<10;i++){
            dp[n-1][i] = 1;
        }
        
        for(int i=n-2;i<=0;i--){
            for(int j=0;j<10;j--){
                long long int sum=0;
                if(j==5) dp[i][j]=0;
                else{
                    for(int k=0;k<mp[j].size();k++){
                        sum += (dp[i+1][mp[j][k]]%m);
                        sum = sum%m;
                    }
                }
                dp[i][j] = sum%m;
            }
        }
        // int sum=0;
        // for(int i=0;i<10;i++){
        //     sum += (dp[0][i]%m);
        //     sum = sum%m;
        // }
        // return (sum%m);
    }

    int knightDialer(int n) {
        int m = 1e9+7;
        long long int sum=0;
        vector<vector<long long int>> dp(n,vector<long long int> (10,-1));
        unordered_map<int,vector<int>> mp={{0,{4,6}},{1,{6,8}},{2,{7,9}},{3,{4,8}},{4,{0,3,9}},{5,{}},{6,{0,1,7}},{7,{2,6}},{8,{1,3}},{9,{2,4}}};
        knight(mp,n,dp);
         for(int i=0;i<10;i++){
        //     //sum += (knight(1,mp,i,n,dp)%m);
             sum += (dp[0][i]%m);
             sum = sum%m;
         }
         return sum%m;
        //return knight(mp,n,dp);
    }
};