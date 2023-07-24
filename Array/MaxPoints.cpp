class Solution {
public:
    // int sum(int i,int j,vector<int>& cardPoints, int k){
    //     if(k==0) return 0;
    //     int l = cardPoints[i]+sum(i+1,j,cardPoints,k-1);
    //     int r = cardPoints[j]+sum(i,j-1,cardPoints,k-1);
    //     return max(l,r);
    // }
    int maxScore(vector<int>& cardPoints, int k) {
        // int n = cardPoints.size();
        // return sum(0,n-1,cardPoints,k);
        int n = cardPoints.size();
        vector<int> pref(n);
        pref[0]=cardPoints[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+cardPoints[i];
        }
        if(k==n) return pref[n-1];
        int maxi = pref[n-1]-pref[n-1-k];
        for(int i=0;i<k;i++){
            int ans = pref[i]+pref[n-1]-pref[n-k+i];
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};