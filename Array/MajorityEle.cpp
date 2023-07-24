class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int ele1=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ele1) cnt++;
            else if(cnt==0){
                ele1=nums[i];
                cnt++;
            }
            else cnt--;
        }
        return ele1;
    }
};