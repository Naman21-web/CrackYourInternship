class Solution {
public:
    long long conquer(vector<int> &arr,long long lo,long long mid,long long hi){
        long long i=lo,j=mid+1,n=mid+1;
        vector<int> temp;
        long long ans=0;
        for(i;i<mid+1;i++){
            while(j<=hi && arr[i]>(long)2*arr[j]) j++;
            ans += (j - (mid+1));
        }
        i = lo,j=mid+1;
        while(i<mid+1 && j<hi+1){
            if(arr[j]<arr[i]){
                temp.push_back(arr[j]);
                j++;
            }
            else{
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<mid+1){
            temp.push_back(arr[i++]);
        }
        while(j<hi+1){
            temp.push_back(arr[j++]);
        }
        for(long long i=lo;i<=hi;i++){
            arr[i] = temp[i-lo];
        }
        return ans;
    }
    
    long long divide(vector<int> &arr,long long lo,long long hi){
        long long ans=0;
        if(lo<hi){
            long long mid = (lo+hi)/2;
            ans += divide(arr,lo,mid);
            ans += divide(arr,mid+1,hi);
            ans += conquer(arr,lo,mid,hi);
        }
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        long long lo=0,hi=n-1;   
        long long ans = divide(nums,lo,hi);
        // for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        // cout<<ans<<" ";
        return ans;
    }
};