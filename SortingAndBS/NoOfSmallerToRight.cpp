class Solution {
public:
    vector<int> ans;
    void merge(int lo,int mid,int hi,vector<pair<int,int>> &copy){
        int i=lo,j=mid+1;
        vector<pair<int,int>> temp;
        while(i<mid+1 && j<hi+1){
            if(copy[i].first<=copy[j].first){
                ans[copy[i].second] += j-(mid+1);
                // cout<<j<<mid+1<<" ";
                temp.push_back({copy[i].first,copy[i].second});
                i++;
            }
            else{
                temp.push_back({copy[j].first,copy[j].second});
                j++;
            }
        }
        while(i<mid+1){
            ans[copy[i].second] += j-(mid+1);
            temp.push_back({copy[i].first,copy[i].second});
            i++;
        }
        while(j<hi+1){
            temp.push_back({copy[j].first,copy[j].second});
            j++; 
        }
        for(int i=lo;i<=hi;i++){
            copy[i] = temp[i-lo];
        }
    }
    void mergesort(int lo,int hi,vector<pair<int,int>> &copy){
        if(lo<hi){
            int mid = lo + (hi-lo)/2;
            mergesort(lo,mid,copy);
            mergesort(mid+1,hi,copy);
            merge(lo,mid,hi,copy);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        vector<pair<int,int>> copy;
        for(int i=0;i<nums.size();i++){
            copy.push_back({nums[i],i});
        }
        ans.resize(nums.size());
        mergesort(0,hi,copy);
        return ans;
    }
};