class Solution {
public:
    void func(int i,vector<vector<int>> &ans,vector<int> &nums,int n){
        if(i==n){
            ans.push_back(nums);
        }
        unordered_set<int> s;
        for(int j=i;j<n;j++){
            if(s.count(nums[j])==1) continue;
            s.insert(nums[j]);
            swap(nums[i],nums[j]);
            func(i+1,ans,nums,n);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> freq(n,0);
        func(0,ans,nums,n);
        return ans;
    }
};