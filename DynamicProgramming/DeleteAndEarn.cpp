class Solution {
public:
    // int earn(int i,vector<int>&nums,int n,unordered_map<int,int>& mp,unordered_map<int,int> &count){
    //     //if(i==n) return;
    //     //int sum=nums[i];
    //     //mp[nums[i]]++;
    //     int maxi=0;
    //     for(int j=0;j<n;j++){
    //         if(j!=i){
    //         if(mp[nums[j]]!=count[nums[j]] && mp.find(nums[j]+1)==mp.end() && mp.find(nums[j]-1)==mp.end()){
    //             mp[nums[j]]++;
    //             maxi = max(maxi,earn(j,nums,n,mp,count));
    //             mp[nums[j]]--;
    //             if(mp[nums[j]]==0){
    //             mp.erase(nums[j]);
    //             }
    //         }
    //         }
    //     }
    //     return maxi+nums[i];

    // }
    // int deleteAndEarn(vector<int>& nums) {
    //     int n = nums.size();
    //     unordered_map<int,int> mp,count;
    //     for(int i=0;i<nums.size();i++){
    //         count[nums[i]]++;
    //     }
    //     int maxi=0;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]++;
    //         maxi =max(maxi,earn(i,nums,n,mp,count));
    //         cout<<maxi;
    //         mp[nums[i]]--;
    //         if(mp[nums[i]]==0){
    //             mp.erase(nums[i]);
    //         }
    //     }
    //     return maxi;
    // }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi=INT_MIN;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            if(nums[i]>maxi) maxi=nums[i];
        }
        vector<int> dp(maxi+1);
        dp[0]=0;
        dp[1]=count[1];
        for(int i=2;i<=maxi;i++){
            dp[i] = max(dp[i-1],dp[i-2]+count[i]*i);
        }
        return dp[maxi];
    }
};