class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        v[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            v[i] = v[i-1]+nums[i];
        }
        int ans=0;
        unordered_map<int,int> mp;
        // int i=0,j=1,ans=0;
        // while(j<nums.size()){
        //     int x = v[j]-v[i];
        //     if(x<k){
        //         j++;
        //     }
        //     else if(x>k){
        //         i++;
        //     }
        //     else{
        //         ans++;
        //     }
        // }
        // return ans;
        for(int i=0;i<nums.size();i++){
            if(v[i]==k){
                ans++;
            }
            if(mp.find(v[i]-k)!=mp.end()){
                ans += mp[v[i]-k];
            }
            mp[v[i]]++;
        }
        return ans;
    }
};