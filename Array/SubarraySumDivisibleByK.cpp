class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            //+k for the case of -ve no add k to make it positive then take remainder
            int x = ((sum%k)+k)%k;
            cnt += mp[x];
            mp[x]++;
        }
        return cnt;
    }
};