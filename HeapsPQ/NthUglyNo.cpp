class Solution {
public:
    int nthUglyNumber(int n) {
        // int c2=0,c3=0,c5=0;
        // vector<int> dp(n+1);
        // dp[0]=1;
        // for(int i=1;i<n+1;i++){
        //     dp[i]=min(min(2*dp[c2],3*dp[c3]),5*dp[c5]);
        //     if(2*dp[c2]==dp[i]) c2++;
        //     if(3*dp[c3]==dp[i]) c3++;
        //     if(5*dp[c5]==dp[i]) c5++;
        // }
        // return dp[n-1];
        unordered_map<int,int> mp;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        int cnt=0;
        while(true){
            long long no = pq.top();
            pq.pop();
            if(mp[no]==0)cnt++;
            else continue;
            mp[no]++;
            if(cnt==n) return no;
            pq.push(no*2);
            pq.push(no*3);
            pq.push(no*5);
        }
        return -1;
    }
};