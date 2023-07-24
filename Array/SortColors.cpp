class Solution{
    public:
 void sortColors(vector<int>& arr) {
        int lo=0,hi=arr.size()-1,mid=0;
        while(mid<=hi){
            if(arr[mid]==0){
                swap(arr[lo],arr[mid]);
                lo++;
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[hi]);
                hi--;
            }
            else mid++;
        }
    }
};