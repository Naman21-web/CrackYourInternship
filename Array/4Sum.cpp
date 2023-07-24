class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
         vector<vector<int>> ans;
         set<vector<int>> st;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            if(i!=0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && arr[j]==arr[j-1]) continue;
                long sum1 = arr[i]+arr[j];
                long diff = k-sum1;
                int lo=j+1,hi=n-1;
                while(lo<hi){
                    long sum2=arr[lo]+arr[hi];
                    if(sum2>diff){
                        hi--;
                    }
                    else if(sum2==diff) {
                        ans.push_back({arr[i],arr[j],arr[lo],arr[hi]});
                        lo++;hi--;
                        while(lo<hi && arr[lo]==arr[lo-1]) lo++;
                        while(hi>lo && arr[hi]==arr[hi+1]) hi--;
                        // st.insert({arr[i],arr[j],arr[lo],arr[hi]});
                        // lo++;hi--;
                        // break;
                    }
                    else lo++;
                }
            }
        }
        // for(auto x:st){
        //     ans.push_back(x);
        // }
        return ans;  
    }
};