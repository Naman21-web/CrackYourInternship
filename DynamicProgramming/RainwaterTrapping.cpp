class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        vector<int> left(n);
        left[0]=-1;
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i-1]);
        }
        int right=height[n-1];
        for(int i=n-2;i>=0;i--){
            int h = min(right,left[i]);
            right = max(right,height[i]);
            if(h>height[i]) ans += h-height[i];
        }
        return ans;
    }
};