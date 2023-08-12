// class Solution {
// public:
//     int decode(string &s,int i,int n){
//         if(i<n && s[i]=='0')
//             return 0;
//         if(i>=n)
//             return 1;
//         int ways=0;
//         if(s[i]!=0)
//             ways = decode(s,i+1,n);
//         if(i+1<n && ((s[i]=='1' && s[i+1]<='9') || (s[i]=='2'&& s[i+1]<'7'))){
//             ways += decode(s,i+2,n);
//         }
//         return ways;
//     }
//     int numDecodings(string s) {
//         int n = s.size();
//        return decode(s,0,n);
//     }
// };
class Solution {
public:    
    int numDecodings(string s) {
         int n = s.size();
         //if(s[0]=='0') return 0;
         //if(n==1) return 1;
        // vector<int> dp(n+1,0);
        // dp[0]=dp[1]=1;
        
        // for(int i=2;i<=n;i++){
        //     int one = s[i-1]-'0';
        //     int two = (s[i-1]-'0')+10*(s[i-2]-'0');
        //     if(one>=1)
        //         dp[i] +=dp[i-1];
        //     if(two>=10 && two<=26)
        //         dp[i] += dp[i-2];
        // }
        //return dp[n];
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]!='0') dp[i] += dp[i-1];
            if(i>1){
                if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
        //return help(0,s,n);
    }
    int help(int i,string &s,int n){
        if(i<n && s[i]=='0') return 0;
        if(i>=n) return 1;
        int ways=0;
        if(s[i]!='0')  ways = help(i+1,s,n);
        if(i<n-1){
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
            ways += help(i+2,s,n); 
        }}
        return ways;
    }
};

