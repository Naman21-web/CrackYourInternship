class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int j=0;
        // for(int i=m;i<m+n;i++){
        //     nums1[i]=nums2[j];
        //     j++;
        // }
        // sort(nums1.begin(),nums1.end());
       int i = m - 1, j = n - 1, t = m + n - 1;
while (j >= 0)
{
if (i >= 0 && nums1[i] > nums2[j])
nums1[t--] = nums1[i--];
else
nums1[t--] = nums2[j--];
}
    }
};