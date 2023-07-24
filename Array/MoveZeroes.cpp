class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int index=0,currindex=0;
        while(currindex<n){
            if(nums[currindex]==0) currindex++;
            else{
                nums[index] = nums[currindex];
                currindex++;
                index++;
            }
        }
        while(index<n){
            nums[index]=0;
            index++;
        }
    }
};