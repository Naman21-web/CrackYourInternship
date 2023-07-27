// class Solution {
// public:
//     void sortColors(vector<int>& arr) {
//         int i,j,k;
//         i=0,j=arr.size()-1;
//         while(j>i){
//             if(arr[i]==0){
//                 i++;
//             }
//             else if(arr[i]==2){
//                 swap(arr[i],arr[j]);
//                 j--;
//             }
//             else{
//                 k=i;
//                 while(arr[k]!=0 && k<=j)
//                     k++;
//                 if(k>=j){
//                     i++;
//                     //continue;
//                 }
//                 else{
//                 swap(arr[k],arr[i]);
//                 i++;
//                 }
//             }
//         }
//     }
// };
class Solution{
    public:
 void sortColors(vector<int>& arr) {
        
        // initialize variables:
        // int low = 0, mid = 0, high = nums.size() - 1;
        
        // // logic:
        // while(mid <= high)
        // {
        //     switch(nums[mid])
        //     {
        //         case 0: swap(nums[low++], nums[mid++]); break;
                
        //         case 1: mid++; break;
                
        //         case 2: swap(nums[mid], nums[high--]); break;
        //     }
        // }
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