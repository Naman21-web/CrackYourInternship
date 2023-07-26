bool check(vector<int> stalls,int cows,int mid){
    int prev=stalls[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if((stalls[i]-prev)>=mid){
            prev=mid;cnt++;
        }
    }
    return (cnt>=cows);
}

int aggressiveCows(vector<int> stalls,int cows){
    if(cows>n) return -1;
    int n=stalls.size();
    sort(stalls.begin(),stalles.end());
    int ans=-1;
    int lo = 0,hi = *max_element(stalls.begin(),stalls.end());
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(stalls,cows,mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}