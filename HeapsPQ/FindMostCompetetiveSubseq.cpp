class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // int n = nums.size();
        // // priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        // priority_queue<PII, vector<PII>, Compare> pq;
        // pq.push({nums[0],0});
        // for(int i=1;i<n;i++){
        //     if(!pq.empty() && pq.top().first>nums[i]){
        //         int remele = n-i;
        //         int currsize = pq.size();

        //         while(!pq.empty() && (remele+currsize)>k){
        //             pq.pop();
        //             currsize--;
        //         }
        //     }
        //     pq.push({nums[i],i});
        // }
        // vector<int> ans;
        // while(k--){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(),ans.end());
        // for(int i=0;i<ans.size();i++){
        //     ans[i] = nums[ans[i]];
        // }
        // return ans;
        int n=nums.size();
        stack<int> st;
        int i=0;
        for(i;i<n;i++){
            if(!st.empty() && nums[i]<st.top()){
                int remele = n-i;
                int currsize = st.size();
                while(!st.empty() && (remele+currsize)>k && st.top()>nums[i]){
                    st.pop();
                    currsize--;
                }
            }
            if(st.size()<k) st.push(nums[i]);
            // cout<<st.size()<<" ";
        }
        vector<int> ans(k);
        i=k-1;
        while(!st.empty()){
            ans[i--]=st.top();
            st.pop();
        }
        return ans;
    }
};