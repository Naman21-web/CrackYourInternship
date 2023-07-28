class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // int m = 1e9+7;
        // int n=arr.size();
        // stack<pair<int,int>> st;
        // vector<int> ans(n),left;
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && st.top().first>=arr[i]) st.pop();
        //     if(st.empty()) ans[i]=i;//ans.push_back(i);
        //     else ans[i]=st.top().second;//ans.push_back(st.top().second);
        //     st.push({arr[i],i});
        // }
        // while(!st.empty()) st.pop();
        // for(int i=0;i<n;i++){
        //     while(!st.empty() && st.top().first>arr[i]) st.pop();
        //     if(st.empty()) left.push_back(-1);
        //     else left.push_back(st.top().second);
        //     st.push({arr[i],i});
        // }
        // //reverse(ans.begin(),ans.end());
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     int j=ans[i];
        //     int k=left[i];
        //     cout<<j<<k<<" ";
        //     if(j==i) j=n;
        //     sum += ((long)(j-i)*arr[i])%m;
        //     sum %= m;
        //     // cout<<sum<<" ";
        //     sum += ((long)(i-k-1)*(j-i)*arr[i])%m;
        //     sum %= m;
        //     // cout<<sum<<" ";
        // }
        // return sum%m;
        int mod=1e9+7;
        int n=arr.size();
        stack<int> st;
        vector<int> left;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()){
                left.push_back(i+1);
            }
            else left.push_back(i-st.top());
            st.push(i);
        }
        // for(int i=0;i<n;i++) cout<<left[i]<<" ";
        int right;
        while(!st.empty()) st.pop();
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) right=(n-i);
            else right=st.top()-i;
            st.push(i);
            // cout<<right<<" ";
            // int x = (right+left[i]-1);
            long long x = ((long long)right*left[i])%mod;
            ans = (ans + (x*arr[i])%mod)%mod;
        }
        return ans%mod;
    }
};