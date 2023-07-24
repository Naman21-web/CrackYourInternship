class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //O(N) space
        // vector<int> v(nums.size(),0);
        // int x;
        // for(int i=0;i<nums.size();i++){
        //     v[nums[i]]++;
        //     if(v[nums[i]]==2){
        //         x = nums[i];
        //         break;
        //     }
        // }
        // return x;
        
        //O(1) space
          for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            
            // mark as visited
            nums[index] *= -1;
            // incase of duplicate, this will become +ve 
            if(nums[index] > 0)
                return abs(nums[i]);
        }    
        return -1;
    }
};