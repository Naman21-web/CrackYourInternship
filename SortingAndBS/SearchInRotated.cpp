class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;int hi=nums.size()-1;int mid;
        while(hi>=lo){
            mid = (lo+hi)/2;
            if(target==nums[mid]) return mid;
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && nums[mid]>=target) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};