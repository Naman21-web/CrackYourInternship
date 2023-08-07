class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int n,vector<int> &nums,vector<int> &temp){
        ans.push_back(temp);
        if(i==n) return;
        for(int j=i;j<n;j++){
            if(i!=j && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            solve(j+1,n,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,n,nums,temp);
        return ans;
    }
};