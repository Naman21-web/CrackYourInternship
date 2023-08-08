class Solution {
public:
    vector<vector<int>> ans;
    void generateSubset(int i,int n,vector<int> &temp,vector<int> &nums){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        generateSubset(i+1,n,temp,nums);
        temp.push_back(nums[i]);
        generateSubset(i+1,n,temp,nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> ans;
        // for(int i=0;i<(1<<n);i++){
        //     vector<int> v;
        //     for(int j=0;j<n;j++){
        //         if(i&(1<<j)){
        //             v.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(v);
        // }
        // return ans;
        vector<int> temp;
        int n=nums.size();
        generateSubset(0,n,temp,nums);
        return ans;
    }
};